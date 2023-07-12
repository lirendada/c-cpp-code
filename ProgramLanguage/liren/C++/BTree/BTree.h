#pragma once
#include <iostream>
using namespace std;

template<class K, size_t M = 3>
struct BTreeNode
{
	size_t _n; // 每个节点中有效关键字的个数

	// 为了方便插入以后再分裂，多给一个空间
	K _keys[M]; // 关键字数组
	BTreeNode<K, M>* _subs[M + 1]; // 孩子节点数组，注意：孩子比数据多一个
	BTreeNode<K, M>* _parent; // 在分裂节点后可能需要继续向上插入，为实现简单增加parent域

	BTreeNode()
	{
		for (int i = 0; i < M; ++i)
		{
			_keys[i] = K();
			_subs[i] = nullptr;
		}
		
		_subs[M] = nullptr;
		_parent = nullptr;
		_n = 0;
	}
};

// 数据是存在磁盘的，所以K是磁盘地址
template<class K, size_t M = 3>
class BTree
{
	typedef BTreeNode<K, M> Node;
public:
	BTree()
		:_root(nullptr)
	{}

	// 参数：key为待查找的元素
	// 返回值：Node*代表找到的节点，int为该元素在该节点中的位置
	pair<Node*, int> Find(const K& key)
	{
		Node* cur = _root;
		Node* parent = nullptr; // 记录下cur的前一个节点

		while (cur != nullptr)
		{
			// 遍历每个节点的各个关键字进行比较
			size_t i = 0;
			while (i < cur->_n)
			{
				if (key < cur->_keys[i])
				{
					// 该元素可能在i的左边的孩子节点中
					break;
				}
				else if (key > cur->_keys[i])
				{
					// 继续向右查找
					i++;
				}
				else
				{
					// 找到返回
					return make_pair(cur, i);
				}
			}

			// 往孩子节点跳
			parent = cur;
			cur = cur->_subs[i];
		}
		return make_pair(parent, -1);
	}

	void InsertKey(Node* parent, const K& key, Node* child)
	{
		int end = parent->_n - 1;
		while (end >= 0)
		{
			if (parent->_keys[end] > key)
			{
				// 注意要同时挪动key和他的右孩子
				parent->_keys[end + 1] = parent->_keys[end];
				parent->_subs[end + 2] = parent->_subs[end + 1];
				--end;
			}
			else
			{
				break;
			}
		}
		parent->_keys[end + 1] = key;
		parent->_subs[end + 2] = child;
		
		// 记得若child不为空则要将其双亲结点连接到parent
		if (child != nullptr)
		{
			child->_parent = parent;
		}

		// 最后将有效个数更新
		parent->_n++;
	}

	bool Insert(const K& key)
	{
		// 如果树为空，直接插入新节点中
		if (_root == nullptr)
		{
			_root = new Node;
			_root->_n++;
			_root->_keys[0] = key;

			return true;
		}

		// 树不为空，首先找到要插入的位置
		pair<Node*, int> ret = Find(key);
		if (ret.second != -1)
		{
			// 存在该节点则直接返回false
			return false;
		}

		Node* cur = ret.first;
		K newKey = key;
		Node* child = nullptr;

		while (cur != nullptr)
		{
			InsertKey(cur, newKey, child);
			
			// 判断一下是否需要裂变
			if (cur->_n < M)
			{
				// 若空间还没满则无需裂变
				return true;
			}
			else
			{
				Node* brother = new Node;
				size_t mid = M / 2;

				// 分裂拷贝key和key的左孩子到brother中去
				size_t i = mid + 1;
				size_t j = 0;
				for (; i < M; ++i)
				{
					brother->_keys[j] = cur->_keys[i];
					brother->_subs[j] = cur->_subs[i];

					// 注意要判断一下这个孩子节点的双亲结点是否需要链接到brother
					if (brother->_subs[j])
					{
						brother->_subs[j]->_parent = brother;
					}
					++j;

					// 拷走时候重置一下方便观察
					cur->_keys[i] = K();
					cur->_subs[i] = nullptr;
				}

				// 记得还有多出来的最后一个孩子要拷贝过去
				brother->_subs[j] = cur->_subs[i];
				if (brother->_subs[j])
				{
					brother->_subs[j]->_parent = brother;
				}
				cur->_subs[i] = nullptr;

				// 将这些节点的有效个数更新一下
				brother->_n = j;
				cur->_n -= (j + 1);

				// 先将cur中mid处的值记录下来，并将cur中的mid处设为默认值
				K midKey = cur->_keys[mid];
				cur->_keys[mid] = K();

				// 判断一下是否存在parent
				if (cur->_parent != nullptr)
				{
					// 存在的话则说明parent中有元素，可能会导致继续分裂
					// 所以将cur变成parent继续循环判断
					newKey = midKey;
					cur = cur->_parent;
					child = brother;
				}
				else
				{
					// 不存在的话，要先定义一个parent
					Node* parent = new Node;
					parent->_keys[0] = midKey;
					parent->_subs[0] = cur;
					parent->_subs[1] = brother;
					parent->_n = 1;

					// 将双亲节点链接上
					brother->_parent = parent;
					cur->_parent = parent;
					
					// 最后让parent作为root
					_root = parent;
					break;
				}
			}
		}

		return true;
	}

	void _InOrder(Node* cur)
	{
		if (cur == nullptr)
			return;

		// 左 根  左 根  ...  右
		size_t i = 0;
		for (; i < cur->_n; ++i)
		{
			_InOrder(cur->_subs[i]); // 左子树
			cout << cur->_keys[i] << " "; // 根
		}

		_InOrder(cur->_subs[i]); // 最后的那个右子树
	}

	void InOrder()
	{
		_InOrder(_root);
	}
private:
	Node* _root;
};

void Test()
{
	int a[] = { 36, 139, 75, 49, 145, 53, 50, 47, 101 };
	BTree<int, 3> t;
	for (auto e : a)
	{
		t.Insert(e);
	}
	t.InOrder();
}