#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace K
{
	template <class K>
	class BSTreeNode
	{
	public:
		BSTreeNode(const K& key = K())
			:_key(key),
			_left(nullptr),
			_right(nullptr)
		{}
	public:
		BSTreeNode<K>* _left;
		BSTreeNode<K>* _right;

		K _key;
	};

	template <class K>
	class BSTree
	{
	public:
		typedef BSTreeNode<K> Node;
	private:
		//查找递归的子函数
		Node* _FindR(Node* root, const K& key)
		{
			//没找到直接返回false
			if (root == nullptr)
				return false;

			if (root->_key > key)
				return _FindR(root->_left, key);
			else if (root->_key < key)
				return _FindR(root->_right, key);
			else
				return root;
		}

		//插入递归的子函数
		bool _InsertR(Node*& root, const K& key)
		{
			//若为空说明没有重复的，则直接开辟节点，返回true
			if (root == nullptr)
			{
				root = new Node(key);
				return true;
			}

			//查找要插入的位置
			if (root->_key > key)
				return _InsertR(root->_left, key);
			else if (root->_key < key)
				return _InsertR(root->_right, key);
			//若找到重复的直接返回false
			else
				return false;
		}

		//删除递归的子函数
		bool _EraseR(Node*& root, const K& key)
		{
			if (root == nullptr)
				return false;

			if (root->_key > key)
			{
				return _EraseR(root->_left, key);
			}
			else if (root->_key < key)
			{
				return _EraseR(root->_right, key);
			}
			else //找到了节点后开始删
			{
				//左右子树有一棵为空的情况
				if (root->_left == nullptr)
				{
					Node* del = root;
					root = root->_right;
					delete del;
				}
				else if (root->_right == nullptr)
				{
					Node* del = root;
					root = root->_left;
					delete del;
				}
				else  //左右子树都不为空的情况
				{
					//先找到右子树的最小值
					Node* cur = root->_right;
					while (cur->_left)
					{
						cur = cur->_left;
					}

					//先记下最小值，然后继续调用函数去删掉那个用来代替的cur节点
					K rightMin = cur->_key;
					_EraseR(root->_right, rightMin);

					root->_key = rightMin;

				}
				return true;
			}
		}

		Node* Copy(Node* root)
		{
			if (root == nullptr)
				return nullptr;

			Node* copynode = new Node(root->_key);
			copynode->_left = Copy(root->_left);
			copynode->_right = Copy(root->_right);
			return copynode;
		}

		void Destory(Node* root)
		{
			if (root == nullptr)
				return;

			//得用后序遍历的方式来删除，不然会找不到左右子树
			Destory(root->_left);
			Destory(root->_right);
			delete root;
		}
	public:
		BSTree()
			:_root(nullptr)
		{}

		//拷贝构造函数
		BSTree(const BSTree<K>& t)
		{
			_root = Copy(t._root);
		}

		//赋值重载
		BSTree<K>& operator=(BSTree<K> t)
		{
			swap(t._root, _root);
			return *this;
		}

		//析构函数
		~BSTree()
		{
			Destory(_root);
			_root = nullptr;
		}

		//递归版本的插入
		bool InsertR(const K& key)
		{
			return _InsertR(_root, key);
		}

		//递归版本的查找
		Node* FindR(const K& key)
		{
			Node* tmp = _FindR(_root, key); //交给子函数去递归
			return tmp;
		}

		//递归版本的删除
		bool EraseR(const K& key)
		{
			return _EraseR(_root, key);
		}

		//若是重复元素则返回false，插入成功则返回true
		bool Insert(const K& key)
		{
			//若没有元素的时候直接给_root开辟节点
			if (_root == nullptr)
			{
				_root = new Node(key);
				return true;
			}

			Node* cur = _root;
			Node* parent = nullptr;
			while (cur != nullptr)
			{
				parent = cur; //让parent先记录cur的位置

				if (key < cur->_key)
				{
					cur = cur->_left;
				}
				else if (cur->_key < key)
				{
					cur = cur->_right;
				}
				else  //重复则直接返回false
				{
					return false;
				}
			}

			//最后记得开辟新节点和parent链接起来
			if (key < parent->_key)
				parent->_left = new Node(key);
			else
				parent->_right = new Node(key);

			return true;
		}

		bool Erase(const K& val)
		{
			Node* cur = _root;
			Node* parent = nullptr;
			//先找到该节点
			while (cur != nullptr)
			{
				if (cur->_key > val)
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (cur->_key < val)
				{
					parent = cur;
					cur = cur->_right;
				}
				else //找到后开始删除
				{
					//判断不同情况下怎么删除节点
					//1、左为空或者右为空，把另一个孩子交给父亲，删除自己
					if (cur->_left == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_right;
						}
						else
						{
							if (parent->_left == cur)
							{
								parent->_left = cur->_right;
							}
							else
							{
								parent->_right = cur->_right;
							}
						}
						delete cur;
					}
					else if (cur->_right == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_left;
						}
						else
						{
							if (parent->_left == cur)
							{
								parent->_left = cur->_left;
							}
							else
							{
								parent->_right = cur->_left;
							}
						}
						delete cur;
					}
					else //2、当左右节点都不为空的情况，替换法删除（这里默认为找右子树的最小值）
					{
						//先找到右子树的最小值，顺便记下minParent的值，以便后面的删除
						Node* minParent = cur; //注意这里不能设为空，如果minRight没进去循环，后面的删除就会崩了
						Node* minRight = cur->_right;
						while (minRight->_left != nullptr) //注意这里不能写minRight != nullptr，因为这样子也可能最后自己变成了nullptr
						{
							minParent = minRight;
							minRight = minRight->_left;
						}

						//让cur节点与minRight的值交换
						cur->_key = minRight->_key;

						//删除minRight节点，此时可能只有右子树或者就是叶子节点
						if (minParent->_left == minRight)
						{
							minParent->_left = minRight->_right;
						}
						else
						{
							minParent->_right = minRight->_right;
						}
						delete minRight;
					}

					return true;
				}
			}

			return false;
		}

		Node* Find(const K& val)
		{
			Node* cur = _root;
			while (cur != nullptr)
			{
				if (cur->_key > val)
				{
					cur = cur->_left;
				}
				else if (cur->_key < val)
				{
					cur = cur->_right;
				}
				else
					return cur;
			}
			return nullptr;
		}

		//中序遍历得用子函数去调用，因为我们的二叉树遍历接口一般不用传参的，如t.Inorder()
		//但是如果不传参的话，这里没办法接着去走它的左右子树，所以我们得把它变成子函数去调用
		void Inorder()
		{
			_Inorder(_root);
			cout << endl;
		}
	private:
		void _Inorder(Node* root) //作为私有成员函数，防止被外界访问
		{
			if (root == nullptr)
				return;

			_Inorder(root->_left);
			cout << root->_key << " ";
			_Inorder(root->_right);
		}

	private:
		Node* _root;
	};
}


namespace KV
{
	template <class K, class V>
	class BSTreeNode
	{
	public:
		BSTreeNode(const K& key = K(), const V& value = V())
			:_key(key),
			_value(value),
			_left(nullptr),
			_right(nullptr)
		{}
	public:
		BSTreeNode<K, V>* _left;
		BSTreeNode<K, V>* _right;
		K _key;
		V _value;
	};

	template <class K, class V>
	class BSTree
	{
	public:
		typedef BSTreeNode<K, V> Node;
	private:
		//查找递归的子函数
		Node* _FindR(Node* root, const K& key)
		{
			//没找到直接返回nullptr
			if (root == nullptr)
				return nullptr;

			if (root->_key > key)
				return _FindR(root->_left, key);
			else if (root->_key < key)
				return _FindR(root->_right, key);
			else
				return root;
		}

		//插入递归的子函数
		bool _InsertR(Node*& root, const K& key, const V& value)
		{
			//若为空说明没有重复的，则直接开辟节点，返回true
			if (root == nullptr)
			{
				root = new Node(key, value);
				return true;
			}

			//查找要插入的位置
			if (root->_key > key)
				return _InsertR(root->_left, key, value);
			else if (root->_key < key)
				return _InsertR(root->_right, key, value);
			//若找到重复的直接返回false
			else
				return false;
		}

		//删除递归的子函数
		bool _EraseR(Node*& root, const K& key)
		{
			if (root == nullptr)
				return false;

			if (root->_key > key)
			{
				return _EraseR(root->_left);
			}
			else if (root->_key < key)
			{
				return _EraseR(root->_right);
			}
			else //找到了节点后开始删
			{
				//左右子树有一棵为空的情况
				if (root->_left == nullptr)
				{
					Node* del = root;
					root = root->_right;
					delete del;
				}
				else if (root->_right == nullptr)
				{
					Node* del = root;
					root = root->_left;
					delete del;
				}
				else  //左右子树都不为空的情况
				{
					//先找到右子树的最小值
					Node* cur = root->_right;
					while (cur->_left)
					{
						cur = cur->_left;
					}

					//先记下最小值，然后继续调用函数去删掉那个用来代替的cur节点
					K krightMin = cur->_key;
					V vrightMin = cur->_value;
					_EraseR(root->_right, krightMin);

					root->_key = krightMin;
					root->_value = vrightMin;
				}
				return true;
			}
		}

		Node* Copy(Node* root)
		{
			if (root == nullptr)
				return nullptr;

			Node* copynode = new Node(root->_key, root->_value);
			copynode->_left = Copy(root->_left);
			copynode->_right = Copy(root->_right);
			return copynode;
		}

		void Destory(Node* root)
		{
			if (root == nullptr)
				return;

			//得用后序遍历的方式来删除，不然会找不到左右子树
			Destory(root->_left);
			Destory(root->_right);
			delete root;
		}
	public:
		BSTree()
			:_root(nullptr)
		{}

		//拷贝构造函数
		BSTree(const BSTree<K, V>& t)
		{
			_root = Copy(t._root);
		}

		//赋值重载
		BSTree<K, V>& operator=(BSTree<K, V> t)
		{
			swap(t._root, _root);
			return *this;
		}

		//析构函数
		~BSTree()
		{
			Destory(_root);
			_root = nullptr;
		}

		//递归版本的插入
		bool InsertR(const K& key, const V& value)
		{
			return _InsertR(_root, key, value);
		}
		
		//递归版本的查找
		Node* FindR(const K& key)
		{
			Node* tmp = _FindR(_root, key); //交给子函数去递归
			return tmp;
		}

		//递归版本的删除
		bool EraseR(const K& key)
		{
			return _EraseR(_root, key);
		}

		//若是重复元素则返回false，插入成功则返回true
		bool Insert(const K& key, const V& value)
		{
			//若没有元素的时候直接给_root开辟节点
			if (_root == nullptr)
			{
				_root = new Node(key, value);
				return true;
			}

			Node* cur = _root;
			Node* parent = nullptr;
			while (cur != nullptr)
			{
				parent = cur; //让parent先记录cur的位置

				if (key < cur->_key)
				{
					cur = cur->_left;
				}
				else if (cur->_key < key)
				{
					cur = cur->_right;
				}
				else  //重复则直接返回false
				{
					return false;
				}
			}

			//最后记得开辟新节点和parent链接起来
			if (key < parent->_key)
				parent->_left = new Node(key, value);
			else
				parent->_right = new Node(key, value);

			return true;
		}

		bool Erase(const K& val)
		{
			Node* cur = _root;
			Node* parent = nullptr;
			//先找到该节点
			while (cur != nullptr)
			{
				if (cur->_key > val)
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (cur->_key < val)
				{
					parent = cur;
					cur = cur->_right;
				}
				else //找到后开始删除
				{
					//判断不同情况下怎么删除节点
					//1、左为空或者右为空，把另一个孩子交给父亲，删除自己
					if (cur->_left == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_right;
						}
						else
						{
							if (parent->_left == cur)
							{
								parent->_left = cur->_right;
							}
							else
							{
								parent->_right = cur->_right;
							}
						}
						delete cur;
					}
					else if (cur->_right == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_left;
						}
						else
						{
							if (parent->_left == cur)
							{
								parent->_left = cur->_left;
							}
							else
							{
								parent->_right = cur->_left;
							}
						}
						delete cur;
					}
					else //2、当左右节点都不为空的情况，替换法删除（这里默认为找右子树的最小值）
					{
						//先找到右子树的最小值，顺便记下minParent的值，以便后面的删除
						Node* minParent = cur; //注意这里不能设为空，如果minRight没进去循环，后面的删除就会崩了
						Node* minRight = cur->_right;
						while (minRight->_left != nullptr) //注意这里不能写minRight != nullptr，因为这样子也可能最后自己变成了nullptr
						{
							minParent = minRight;
							minRight = minRight->_left;
						}

						//让cur节点与minRight的值交换
						cur->_key = minRight->_key;

						//删除minRight节点，此时可能只有右子树或者就是叶子节点
						if (minParent->_left == minRight)
						{
							minParent->_left = minRight->_right;
						}
						else
						{
							minParent->_right = minRight->_right;
						}
						delete minRight;
					}

					return true;
				}
			}

			return false;
		}

		Node* Find(const K& val)
		{
			Node* cur = _root;
			while (cur != nullptr)
			{
				if (cur->_key > val)
				{
					cur = cur->_left;
				}
				else if (cur->_key < val)
				{
					cur = cur->_right;
				}
				else
					return cur;
			}
			return nullptr;
		}

		//中序遍历得用子函数去调用，因为我们的二叉树遍历接口一般不用传参的，如t.Inorder()
		//但是如果不传参的话，这里没办法接着去走它的左右子树，所以我们得把它变成子函数去调用
		void Inorder()
		{
			_Inorder(_root);
			cout << endl;
		}
	private:
		void _Inorder(Node* root) //作为私有成员函数，防止被外界访问
		{
			if (root == nullptr)
				return;

			_Inorder(root->_left);
			cout << root->_key << ":" << root->_value << endl;
			_Inorder(root->_right);
		}

	private:
		Node* _root;
	};
}