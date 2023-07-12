#pragma once
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

template <class K, class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	pair<K, V> _kv;

	int _bf; //该点的平衡因子 --> balance factor

	AVLTreeNode(const pair<K, V>& kv)
		: _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		, _bf(0)
	{}
};

template <class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	AVLTree()
		:_root(nullptr)
	{}

	V& operator[](const K& key)
	{
		pair<Node*, bool> res = Insert(make_pair(key, V()));
		return res.first->_kv.second;
	}

	~AVLTree()
	{
		Destory(_root);
		_root = nullptr;
	}

	pair<Node*, bool> Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return make_pair(_root, true);
		}

		// 先找到该节点
		Node* cur = _root;
		Node* parent = _root;
		while (cur != nullptr)
		{
			if (kv.first < cur->_kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (kv.first > cur->_kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return make_pair(cur, false);
			}
		}

		// 接着插入节点
		cur = new Node(kv);
		Node* newnode = cur; // 这一步是为了后面返回值返回的
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}

		// 1、更新平衡因子
		while (parent != nullptr) // 或者while(cur != _root)
		{
			if (parent->_left == cur)
			{
				parent->_bf--;
			}
			else
			{
				parent->_bf++;
			}

			if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = parent;
				parent = parent->_parent;
			}
			else if(parent->_bf == 2 || parent->_bf == -2)
			{
				// 2、调整高度
				if (parent->_bf == -2)
				{
					if (cur->_bf == -1)
					{
						RotateR(parent); //右单旋
					}
					else if(cur->_bf == 1)
					{
						RotateLR(parent); //左右双旋
					}
				}
				else if (parent->_bf == 2)
				{
					if (cur->_bf == 1)
					{
						RotateL(parent); //左单旋
					}
					else if (cur->_bf == -1)
					{
						RotateRL(parent); //右左双旋 
					}
				}
				// 注意这里的break很关键，因为我们调整了子树的平衡因子后，它的父亲其实就已经不会有影响了
				break;
			}
			else
			{
				// 插入节点之前，树已经不平衡了，或者bf出错。需要检查其他逻辑
				assert(false);
			}
		}
		return make_pair(newnode, true);
	}

	void RotateR(Node* parent)
	{
		// SubL: Parent的左孩子
		// SubLR: Parent左孩子的右孩子
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		// 先将parent的左子树连上subLR，注意要双向链接
		parent->_left = subLR;
		if (subLR != nullptr)
			subLR->_parent = parent;

		// 让parent作为subL的右子树
		subL->_right = parent;
		Node* parent_parent = parent->_parent; // 先将parent的parent记录下来，后面链接要用到
		parent->_parent = subL;

		// 判断一下parent是否为二叉树的根节点
		if (parent == _root)
		{
			_root = subL;
			_root->_parent = nullptr;
		}
		else
		{
			if (parent_parent->_left == parent)
			{
				parent_parent->_left = subL;
			}
			else
			{
				parent_parent->_right = subL;
			}

			subL->_parent = parent_parent;
		}

		// 最后记得要将平衡因子置零
		subL->_bf = parent->_bf = 0;
	}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL != nullptr)
			subRL->_parent = parent;

		subR->_left = parent;
		Node* parent_parent = parent->_parent;
		parent->_parent = subR;

		if (parent == _root)
		{
			_root = subR;
			_root->_parent = nullptr;
		}
		else
		{
			if (parent_parent->_left == parent)
			{
				parent_parent->_left = subR;
			}
			else
			{
				parent_parent->_right = subR;
			}
			subR->_parent = parent_parent;
		}

		// 最后记得要将平衡因子置零
		subR->_bf = parent->_bf = 0;
	}

	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		// 旋转之前，保存subLR的平衡因子，旋转完成之后，需要根据该平衡因子来调整其他节点的平衡因子
		int bf = subLR->_bf;

		RotateL(parent->_left);
		RotateR(parent);

		if (bf == 1)
		{
			subL->_bf = -1;
			subLR->_bf = 0;
			parent->_bf = 0;
		}
		else if (bf == -1)
		{
			subL->_bf = 0;
			subLR->_bf = 0;
			parent->_bf = 1;
		}
		else if (bf == 0)
		{
			subL->_bf = 0;
			subLR->_bf = 0;
			parent->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}

	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;

		RotateR(parent->_right);
		RotateL(parent);

		if (bf == 1)
		{
			parent->_bf = -1;
			subRL->_bf = 0;
			subR->_bf = 0;
		}
		else if (bf == -1)
		{
			parent->_bf = 0;
			subRL->_bf = 0;
			subR->_bf = 1;
		}
		else if (bf == 0)
		{
			parent->_bf = 0;
			subRL->_bf = 0;
			subR->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}

	Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur != nullptr)
		{
			if (cur->_kv.first < key)
			{
				cur = cur->_right;
			}
			else if (cur->_kv.first > key)
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}
		return nullptr;
	}

	bool Erase(const K& key)
	{
		if (_root == nullptr)
			return false;

		Node* cur = _root;
		Node* parent = nullptr;
		while (cur != nullptr)
		{
			if (cur->_kv.first > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				// 找到了该节点，准备删除
				// 1、左右都为空或者其中一个为空
				if (cur->_left == nullptr || cur->_right == nullptr)
				{
					if (_root == cur)
					{
						if (cur->_left == nullptr)
							_root = _root->_right;
						else
							_root = _root->_left;
						delete cur;

						// 平衡因子调节
						if(_root != nullptr)
							_root->_bf = 0;
					}
					else if (cur->_left == nullptr && cur->_right == nullptr)
					{
						if (parent->_left == cur)
						{
							parent->_left = nullptr;
							parent->_bf++;
						}
						else
						{
							parent->_right = nullptr;
							parent->_bf--;
						}
						delete cur;

						// 调节高度
						Erase_rotate(parent);
					}
					else if (cur->_left == nullptr && cur->_right != nullptr)
					{
						cur->_kv = cur->_right->_kv;
						delete cur->_right;
						cur->_right = nullptr;

						// 调节高度
						cur->_bf--;
						Erase_rotate(cur);
					}
					else if (cur->_left != nullptr && cur->_right == nullptr)
					{
						cur->_kv = cur->_left->_kv;
						delete cur->_left;
						cur->_left = nullptr;

						// 调节高度
						cur->_bf++;
						Erase_rotate(cur);
					}
				}
				else // 2、左右都不为空
				{
					Node* minRight = cur->_right;
					Node* minParent = cur;
					while (minRight->_left != nullptr)
					{
						minParent = minRight;
						minRight = minRight->_left;
					}

					cur->_kv = minRight->_kv;

					// 将删除节点转化为上面左右都为空或者其中一个为空的情况解决
					if (cur == minParent)
					{
						if (minRight->_right != nullptr)
						{
							minRight->_kv = minRight->_right->_kv;

							delete minRight->_right;
							minRight->_right = nullptr;
							minRight->_bf++;

							Erase_rotate(minRight);
						}
						else
						{
							minParent->_right = nullptr;
							delete minRight;

							minParent->_bf--;
							Erase_rotate(minParent);
						}
					}
					else
					{
						if (minRight->_right != nullptr)
						{
							minRight->_kv = minRight->_right->_kv;

							delete minRight->_right;
							minRight->_right = nullptr;
							minRight->_bf++;

							Erase_rotate(minRight);
						}
						else
						{
							minParent->_left= nullptr;
							delete minRight;

							minParent->_bf++;
							Erase_rotate(minParent);
						}
					}
				}
				return true;
			}
		}
		return false;
	}

	void Erase_rotate(Node* cur)
	{
		Node* prev = nullptr;
		while (cur != nullptr)
		{
			if (cur->_bf == 1 || cur->_bf == -1)
			{
				break;
			}
			else if (cur->_bf == 0)
			{
				prev = cur;
				cur = cur->_parent;
			}
			else if (cur->_bf == 2 || cur->_bf == -2)
			{
				if (cur->_bf == 2)
				{
					if (cur->_right->_bf == 0) // 这种情况是插入没有的，这里要特殊处理一下
					{
						RotateL(cur);
						cur->_parent->_bf = -1;
						cur->_bf = 1;
						break;		// 由于旋转完的树的bf的值为-1，所以不用继续循环
					}
					else if (cur->_right->_bf == 1)
					{
						RotateL(cur);
						// 下面这两步置零其实可以不用写，因为在左旋的实现里面已经置零了
						// cur->_parent->_bf = 0;
						// cur->_bf = 0;

						prev = cur->_parent;
						cur = prev->_parent;
						continue;
					}
					else if (cur->_right->_bf == -1)
					{
						RotateRL(cur);

						prev = cur->_parent;
						cur = prev->_parent;
						continue;
					}
				}
				else if(cur->_bf == -2)
				{
					if (cur->_left->_bf == 0) // 这种情况是插入没有的，这里要特殊处理一下
					{
						RotateR(cur);
						cur->_bf = -1;
						cur->_parent->_bf = 1;

						break;
					}
					else if (cur->_left->_bf == -1)
					{
						RotateR(cur);

						prev = cur->_parent;
						cur = prev->_parent;
						continue;
					}
					else if (cur->_left->_bf == 1)
					{
						RotateRL(cur);

						prev = cur->_parent;
						cur = prev->_parent;
						continue;
					}
				}
			}
			else
			{
				assert(false);
			}

			// 更新平衡因子
			if (cur && cur->_left == prev)
				cur->_bf++;
			else if (cur && cur->_right == prev)
				cur->_bf--;
		}

	}

	bool IsAVLTree()
	{
		return IsBalanceTree(_root);
	}

	void Inorder()
	{
		_Inorder(_root);
		cout << endl;
	}
private:
	void Destory(Node* root)
	{
		if (root == nullptr)
			return;

		Destory(root->_left);
		Destory(root->_right);
		delete root;
	}

	void _Inorder(Node* root)
	{
		if (root == nullptr)
			return;

		_Inorder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << endl;
		_Inorder(root->_right);
	}

	int Height(Node* root)
	{
		if (root == nullptr)
			return 0;

		int leftH = Height(root->_left);
		int rightH = Height(root->_right);

		return leftH > rightH ? leftH + 1 : rightH + 1;
	}

	bool IsBalanceTree(Node* root)
	{
		if (root == nullptr)
			return true;

		int leftH = Height(root->_left);
		int rightH = Height(root->_right);

		// 检查一下平衡因子是否正确 (右平衡因子 - 左平衡因子)
		if (rightH - leftH != root->_bf)
		{
			cout << "平衡因子异常:" << root->_kv.first << endl;
			return false;
		}

		if (abs(rightH - leftH) > 2)
			return false;

		return IsBalanceTree(root->_left) && IsBalanceTree(root->_right);
	}
	Node* _root;
};