#pragma once
#include <iostream>
#include "Iterator.h"
#include <string>   
using namespace std;

enum Color
{
	BLACK,
	RED
};

template <class T>
struct RBTreeNode
{
	RBTreeNode(const T& data)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _data(data)
		, _col(RED)
	{}

	RBTreeNode<T>* _left; // 节点的左孩子
	RBTreeNode<T>* _right; // 节点的右孩子
	RBTreeNode<T>* _parent; // 节点的双亲(红黑树需要旋转，为了实现简单给出该字段)
	T _data; // 节点的值域
	Color _col; // 节点的颜色
};

template <class T, class Ref, class Ptr>
struct TreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef TreeIterator<T, Ref, Ptr> Self;

	// 给反向迭代器中用的
	typedef Ref Ref;
	typedef Ptr Ptr;

	TreeIterator(Node* node)
		:_node(node)
	{}

	Ref operator*()
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		return &(_node->_data);
	}

	Self& operator++()
	{
		// 若右子树不为空，则去访问右子树中序的那个，即右子树的最左节点
		if (_node->_right != nullptr)
		{
			Node* cur = _node->_right;
			while (cur->_left)
				cur = cur->_left;

			_node = cur;
		}
		else // 若右子树为空，说明_node节点已经访问完了，则向上查找为祖先的左的节点
		{
			Node* cur = _node;
			Node* parent = _node->_parent;
			while (parent && parent->_right == cur)
			{
				cur = parent;
				parent = parent->_parent;
			}

			_node = parent;
		}
		return *this;
	}

	Self operator++(int)
	{
		Self tmp = *this;
		this->operator++();
		return tmp;
	}

	Self& operator--()
	{
		// 若左子树不为空，则去访问左子树中序的那个，即左子树的最右节点
		if (_node->_left != nullptr)
		{
			Node* cur = _node->_left;
			while (cur->_right)
				cur = cur->_right;

			_node = cur;
		}
		else // 若左子树为空，说明_node节点已经访问完了，则向上查找为祖先的右的节点
		{
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && parent->_left == cur)
			{
				cur = parent;
				parent = parent->_parent;
			}

			_node = parent;
		}
		return *this;
	}

	Self operator--(int)
	{
		Self tmp(*this);
		this->operator--();
		return tmp;
	}

	bool operator!=(const Self& s) const 
	{
		return _node != s._node;
	}

	bool operator==(const Self& s) const
	{
		return _node == s._node;
	}

	Node* _node;
};

template <class K, class T, class KeyOfT>
class RBTree
{
public:
	typedef RBTreeNode<T> Node;
	typedef TreeIterator<T, T&, T*> iterator;
	typedef TreeIterator<T, const T&, const T*> const_iterator;
	typedef ReverseIterator<iterator> reverse_iterator;
	// typedef ReverseIterator<const_iterator> const_reverse_iterator; 可以有的，但是这里就不写了
public:
	RBTree()
		:_root(nullptr)
	{}

	RBTree(const RBTree<K, T, KeyOfT>& t)
	{
		_root = Copy(t._root);
	}

	RBTree<K, T, KeyOfT>& operator=(RBTree<K, T, KeyOfT> t)
	{
		swap(t._root, _root);
		return *this;
	}

	~RBTree()
	{
		Destory(_root);
		_root = nullptr;
	}

	iterator begin()
	{
		Node* cur = _root;
		while (cur && cur->_left)
		{
			cur = cur->_left;
		}
		return iterator(cur);
	}

	iterator end()
	{
		return iterator(nullptr);
	}

	reverse_iterator rbegin()
	{
		Node* cur = _root;
		while (cur && cur->_right)
		{
			cur = cur->_right;
		}
		return reverse_iterator(iterator(cur));
	}

	reverse_iterator rend()
	{
		return reverse_iterator(iterator(nullptr));
	}

	pair<iterator, bool> Insert(const T& data)
	{
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_col = BLACK;
			return make_pair(iterator(_root), true);
		}

		// 寻找要插入的位置
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (_kt(cur->_data) > _kt(data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (_kt(cur->_data) < _kt(data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return make_pair(iterator(cur), false);
			}
		}

		// 插入新节点并将新节点的颜色设为红色
		cur = new Node(data);
		Node* newnode = cur;
		cur->_col = RED;
		if (_kt(parent->_data) > _kt(data))
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_right = cur;
			cur->_parent = parent;
		}

		// 控制平衡
		while (parent && parent->_col == RED)
		{
			Node* grandparent = parent->_parent;

			// 判断一下parent的位置
			if (grandparent->_left == parent)
			{
				Node* uncle = grandparent->_right;
				if (uncle && uncle->_col == RED) // uncle存在且为红色的情况
				{
					// 调整颜色
					parent->_col = uncle->_col = BLACK;
					grandparent->_col = RED;

					// 继续向上调整
					cur = grandparent;
					parent = cur->_parent;
				}
				else // uncle不存在或者为黑色的情况
				{
					// 根据cur与parent的位置判断要如何旋转
					if (parent->_left == cur)
					{
						// 右单旋
						RotateR(grandparent);

						// 调整颜色
						grandparent->_col = RED;
						parent->_col = BLACK;
					}
					else
					{
						// 先左单旋，然后右单旋
						RotateL(parent);
						RotateR(grandparent);

						// 调整颜色
						cur->_col = BLACK;
						grandparent->_col = RED;
					}
					break;
				}
			}
			else
			{
				Node* uncle = grandparent->_left;
				if (uncle && uncle->_col == RED) // uncle存在且为红色的情况
				{
					// 调整颜色
					parent->_col = uncle->_col = BLACK;
					grandparent->_col = RED;

					// 继续向上调整
					cur = grandparent;
					parent = cur->_parent;
				}
				else // uncle不存在或者为黑色的情况
				{
					// 根据cur与parent的位置判断要如何旋转
					if (parent->_left == cur)
					{
						// 先右单旋，然后左单旋
						RotateR(parent);
						RotateL(grandparent);

						// 调整颜色
						cur->_col = BLACK;
						grandparent->_col = RED;
					}
					else
					{
						// 左单旋
						RotateL(grandparent);

						// 调整颜色
						parent->_col = BLACK;
						grandparent->_col = RED;
					}
					break;
				}
			}
		}
		// 最后记得将根节点的颜色调为黑色
		_root->_col = BLACK;

		return make_pair(iterator(newnode), true);
	}

	Node* find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (_kt(cur->_data) > key)
				cur = cur->_left;
			else if (_kt(cur->_data) < key)
				cur = cur->_right;
			else
				return cur;
		}
		return nullptr;
	}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
		{
			subRL->_parent = parent;
		}

		Node* parentParent = parent->_parent;
		subR->_left = parent;
		parent->_parent = subR;

		if (_root == parent)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (parentParent->_left == parent)
				parentParent->_left = subR;
			else
				parentParent->_right = subR;
			subR->_parent = parentParent;
		}
	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		Node* parentParent = parent->_parent;

		subL->_right = parent;
		parent->_parent = subL;

		if (parent == _root)
		{
			_root = subL;
			_root->_parent = nullptr;
		}
		else
		{
			if (parentParent->_left == parent)
				parentParent->_left = subL;
			else
				parentParent->_right = subL;

			subL->_parent = parentParent;
		}
	}

	bool _CheckBlance(Node* root, int blackNum, int count)
	{
		// 走到nullptr之后，判断count和blackNum是否相等
		if (root == nullptr)
		{
			if (count != blackNum)
			{
				cout << "黑色节点的数量不相等" << endl;
				return false;
			}

			return true;
		}

		// 检测当前节点与其双亲是否都为红色
		if (root->_col == RED && root->_parent->_col == RED)
		{
			cout << "存在连续的红色节点" << endl;
			return false;
		}

		// 统计黑色节点的个数
		if (root->_col == BLACK)
		{
			count++;
		}

		return _CheckBlance(root->_left, blackNum, count)
			&& _CheckBlance(root->_right, blackNum, count);
	}

	bool CheckBlance()
	{
		// 空树也是红黑树
		if (_root == nullptr)
		{
			return true;
		}

		// 检测根节点是否满足情况
		if (_root->_col == RED)
		{
			cout << "根节点是红色的" << endl;
			return false;
		}

		// 获取任意一条路径中黑色节点的个数
		int blackNum = 0;
		Node* left = _root;
		while (left)
		{
			if (left->_col == BLACK)
			{
				blackNum++;
			}

			left = left->_left;
		}

		// 检测是否满足红黑树的性质，count用来记录路径中黑色节点的个数
		int count = 0;
		return _CheckBlance(_root, blackNum, count);
	}

	void Destory(Node* root)
	{
		if (root == nullptr)
			return;
		Destory(root->_left);
		Destory(root->_right);
		delete root;
	}

	Node* Copy(Node* root)
	{
		if (root == nullptr)
			return nullptr;

		Node* copynode = new Node(root->_data);
		copynode->_col = root->_col;
		copynode->_left = Copy(root->_left);
		copynode->_right = Copy(root->_right);

		// 将孩子节点的_parent链接上
		if (copynode->_left)
			copynode->_left->_parent = copynode;
		if (copynode->_right)
			copynode->_right->_parent = copynode;

		return copynode;
	}
private:
	KeyOfT _kt;
	Node* _root;
};
