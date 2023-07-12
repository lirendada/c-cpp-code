#pragma once
#include <iostream>
#include <string>   
#include <ctime>
#include <vector>
using namespace std;

enum Color
{
	BLACK,
	RED
};

template <class K, class V>
struct RBTreeNode
{
	RBTreeNode(const pair<K, V>& kv, Color col = RED)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		, _col(col)
	{}

	RBTreeNode<K, V>* _left; // 节点的左孩子
	RBTreeNode<K, V>* _right; // 节点的右孩子
	RBTreeNode<K, V>* _parent; // 节点的双亲(红黑树需要旋转，为了实现简单给出该字段)
	pair<K, V> _kv; // 节点的键值对
	Color _col; // 节点的颜色
};

template <class K, class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	RBTree()
		:_root(nullptr)
	{}

	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return true;
		}

		// 寻找要插入的位置
		Node* cur = _root;
		Node* parent = _root;
		while (cur)
		{
			if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}

		// 插入新节点并将新节点的颜色设为红色
		cur = new Node(kv);
		cur->_col = RED;
		if (parent->_kv.first > kv.first)
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

		return true;
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

	bool Erase(const K& key)
	{
		if (_root == nullptr)
			return false;

		// 先找到要删除的节点
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first > key)
			{
				cur = cur->_left;
			}
			else if (cur->_kv.first < key)
			{
				cur = cur->_right;
			}
			else
			{
				// 找到了节点就开始删除
				if (cur->_left == nullptr || cur->_right == nullptr)
				{
					if (cur == _root)
					{
						if (cur->_left == nullptr && cur->_right != nullptr)
						{
							_root = _root->_right;
							_root->_col = BLACK;
						}
						else if (cur->_right == nullptr && cur->_left != nullptr)
						{
							_root = _root->_left;
							_root->_col = BLACK;
						}
						else
						{
							_root = nullptr;
						}
						delete cur;
					}
					else if (cur->_left == nullptr && cur->_right != nullptr)
					{
						Node* right = cur->_right;
						Node* parent = cur->_parent;

						right->_parent = parent;
						if (parent->_left == cur)
						{
							parent->_left = right;
						}
						else
						{
							parent->_right = right;
						}
						delete cur;

						// 最后将right的颜色改为黑色
						right->_col = BLACK;
					}
					else if (cur->_left != nullptr && cur->_right == nullptr)
					{
						Node* left = cur->_left;
						Node* parent = cur->_parent;

						left->_parent = parent;
						if (parent->_left == cur)
						{
							parent->_left = left;
						}
						else
						{
							parent->_right = left;
						}
						delete cur;

						// 最后将left的颜色改为黑色
						left->_col = BLACK;
					}
					else if (cur->_left == nullptr && cur->_right == nullptr) // 无叶子节点
					{
						if (cur->_col == RED)
						{
							// 直接删除节点即可
							if (cur->_parent->_left == cur)
							{
								cur->_parent->_left = nullptr;
							}
							else
							{
								cur->_parent->_right = nullptr;
							}
						}
						else
						{
							Erase_balanceTwo(cur);
							if (cur->_parent->_left == cur)
							{
								cur->_parent->_left = nullptr;
							}
							else
							{
								cur->_parent->_right = nullptr;
							}
						}
						delete cur;
					}
				}
				else // 左右子树都存在的情况
				{
					Node* minRight = cur->_right;
					Node* minParent = cur;
					while (minRight->_left)
					{
						minParent = minRight;
						minRight = minRight->_left;
					}

					cur->_kv = minRight->_kv;

					if (cur == minParent)
					{
						// 若为红色，则可直接删除该节点
						if (minRight->_col == RED)
						{
							delete minRight;
							minParent->_right = nullptr;
						}
						else // 若为黑色，则转化为组合2和组合4的问题
						{
							if (minRight->_right != nullptr)
							{
								Node* right = minRight->_right;

								right->_parent = minParent;
								minParent->_right = right;
								delete minRight;

								// 最后变色 
								right->_col = BLACK;
							}
							else
							{
								Erase_balanceTwo(minRight);
								minParent->_right = nullptr;
								delete minRight;
							}
						}
					}
					else
					{
						// 若为红色，则可直接删除该节点
						if (minRight->_col == RED)
						{
							delete minRight;
							minParent->_left = nullptr;
						}
						else // 若为黑色，则转化为组合2或组合4的问题
						{
							if (minRight->_right != nullptr)
							{
								Node* right = minRight->_right;

								right->_parent = minParent;
								minParent->_left = right;
								delete minRight;

								// 最后变色 
								right->_col = BLACK;
							}
							else
							{
								Erase_balanceTwo(minRight);
								minParent->_left = nullptr;
								delete minRight;
							}
						}
					}
				}
				return true;
			}
		}
		return false;
	}

	void Erase_balanceTwo(Node* cur)
	{
		if (cur == _root)
			return;

		Node* parent = cur->_parent;
		if (parent->_left == cur) // uncle为parent右子树
		{
			Node* uncle = parent->_right;
			if (uncle->_col == RED) // 情形四
			{
				RotateL(parent);
				parent->_col = RED;
				uncle->_col = BLACK;

				Erase_balanceTwo(cur); // 对x重新执行这个过程，此时一定是情形一 二 三中的一种
			}
			else
			{
				if ((uncle->_left && uncle->_left->_col == RED) || (uncle->_right && uncle->_right->_col == RED))
				{
					// 情形一
					if (uncle->_right != nullptr)
					{
						uncle->_right->_col = BLACK;
						uncle->_col = parent->_col;
						parent->_col = BLACK;
						RotateL(parent);
					}
					else //情形二
					{
						uncle->_left->_col = BLACK;
						uncle->_col = RED;
						RotateR(uncle);

						Erase_balanceTwo(cur);
					}
				}
				else // 情形三
				{
					if (parent->_col == RED)
					{
						parent->_col = BLACK;
						uncle->_col = RED;
					}
					else
					{
						uncle->_col = RED;
						Erase_balanceTwo(parent);
					}
				}
			}
		}
		else // uncle为parent左子树
		{
			Node* uncle = parent->_left;
			if (uncle->_col == RED) // 情形四
			{
				RotateR(parent);
				parent->_col = RED;
				uncle->_col = BLACK;

				Erase_balanceTwo(cur); // 对x重新执行这个过程，此时一定是情形一 二 三中的一种 
			}
			else
			{
				if ((uncle->_left && uncle->_left->_col == RED) || (uncle->_right && uncle->_right->_col == RED))
				{
					// 情形一
					if (uncle->_left != nullptr)
					{
						uncle->_left->_col = BLACK;
						uncle->_col = parent->_col;
						parent->_col = BLACK;
						RotateR(parent);
					}
					else // 情形二
					{
						uncle->_right->_col = BLACK;
						uncle->_col = RED;
						RotateL(uncle);

						Erase_balanceTwo(cur);
					}
				}
				else // 情形三
				{
					if (parent->_col == RED)
					{
						parent->_col = BLACK;
						uncle->_col = RED;
					}
					else
					{
						uncle->_col = RED;
						Erase_balanceTwo(parent);
					}
				}
			}
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

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	void _InOrder(Node* root)
	{
		if (root == NULL)
			return;

		_InOrder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << endl;
		_InOrder(root->_right);
	}

private:
	Node* _root;
};
