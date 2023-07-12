#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <class K>
struct Hash
{
	size_t operator()(const K& key)
	{
		return key;
	}
};

// 特化
template<>
struct Hash <string>
{
	size_t operator()(const string& s)
	{
		// BKDR
		size_t value = 0;
		for (auto ch : s)
		{
			value *= 31;
			value += ch;
		}
		return value;
	}
};

namespace LinkHash
{
	template <class T>
	struct HashNode
	{
		T _data;
		HashNode<T>* _next;

		HashNode(const T& data, HashNode<T>* next = nullptr)
			:_data(data)
			, _next(next)
		{}
	};

	// 哈希表的前置声明
	template <class K, class T, class KeyOfT, class HashFunc>
	class hashtable;

	template <class K, class T, class Ref, class Ptr, class KeyOfT, class HashFunc>
	struct _HTIterator
	{
		typedef HashNode<T> Node;
		typedef _HTIterator<K, T, Ref, Ptr, KeyOfT, HashFunc> Self;

		Node* _node; 
		hashtable<K, T, KeyOfT, HashFunc>* _pht; // 哈希表的指针

		// 构造函数
		_HTIterator(Node* node, hashtable<K, T, KeyOfT, HashFunc>* pht)
			:_node(node)
			, _pht(pht)
		{}

		Self& operator++()
		{
			// 不为空说明还没遍历完该桶
			if (_node->_next != nullptr)
			{
				_node = _node->_next;
			}
			else // 为空则需要切换桶
			{
				KeyOfT kt;
				HashFunc _hs;

				// 通过哈希表的指针找到目前桶的位置，然后再让其++就得到下一个桶的位置
				size_t index = _hs(kt(_node->_data)) % _pht->_tables.size();
				index++;

				// 寻找下一个不为空的桶
				while (index < _pht->_tables.size())
				{
					// 不为空则让 _node 移动过来
					if (_pht->_tables[index] != nullptr)
					{
						_node = _pht->_tables[index];
						break;
					}
					else // 为空则继续判断下一个桶
					{
						index++;
					}
				}

				// 出了循环后要判断是否出界
				if (index >= _pht->_tables.size())
					_node = nullptr;
			}
			return *this;
		}

		Self operator++(int)
		{
			Self tmp(this->_node, this->_pht);
			++*this;
			return tmp;
		}

		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &_node->_data;
		}

		bool operator!=(const Self& s) const 
		{
			return _node != s._node;
		}

		bool operator==(const Self& s) const 
		{
			return _node == s._node;
		}
	};

	template <class K, class T, class KeyOfT, class HashFunc>
	class hashtable
	{
		// 将迭代器设为哈希表的友元对象，这样子迭代器才能访问哈希表的成员变量
		template <class K, class T, class Ref, class Ptr, class KeyOfT, class HashFunc>
		friend struct _HTIterator;

		typedef HashNode<T> Node;
	public:
		typedef _HTIterator<K, T, T&, T*, KeyOfT, HashFunc> iterator;

		// 告诉编译器使用默认的构造函数
		hashtable() = default;

		hashtable(const hashtable<K, T, KeyOfT, HashFunc>& s)
		{
			_tables.resize(s._tables.size());
			for (size_t i = 0; i < _tables.size(); ++i)
			{
				Node* tmp = s._tables[i];
				while (tmp != nullptr)
				{
					Node* copy = new Node(tmp->_data);

					// 头插
					copy->_next = _tables[i];
					_tables[i] = copy;

					tmp = tmp->_next;
				}
			}
			// 记得将有效个数也拷贝过去
			_n = s._n;
		}

		// 赋值重载
		hashtable<K, T, KeyOfT, HashFunc>& operator=(hashtable<K, T, KeyOfT, HashFunc> s)
		{
			swap(_n, s._n);
			_tables.swap(s._tables);
			return *this;
		}

		~hashtable()
		{
			for (size_t i = 0; i < _tables.size(); ++i)
			{
				// 循环去删除每个元素
				Node* cur = _tables[i];
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}
				_tables[i] = nullptr;
			}
		}

		// 获取下一个素数
		size_t GetNextPrime(size_t prime)
		{
			const int PrimeCount = 28;
			static const size_t primeList[PrimeCount] =
			{
				53, 97, 193, 389, 769,1543, 3079, 6151, 12289, 24593,
				49157, 98317, 196613, 393241, 786433,1572869, 3145739, 6291469, 12582917,
				25165843,50331653, 100663319, 201326611, 402653189, 805306457,1610612741, 3221225473, 4294967291
			};

			size_t i = 0;
			for (i = 0; i < PrimeCount; ++i)
			{
				if (primeList[i] > prime)
					return primeList[i];
			}

			return primeList[i];
		}

		iterator begin()
		{
			for (size_t i = 0; i < _tables.size(); ++i)
			{
				if (_tables[i] != nullptr)
				{
					return iterator(_tables[i], this);
				}
			}
			return end();
		}

		iterator end()
		{
			return iterator(nullptr, this);
		}

		pair<iterator, bool> insert(const T& data)
		{
			KeyOfT kt;

			// 检测是否有重复元素
			iterator ret = find(kt(data));
			if (ret != end())
				return make_pair(ret, false);

			// 检测是否需要扩容
			_CheckCapacity();

			HashFunc _hs; // 哈希函数
			size_t index = _hs(kt(data)) % _tables.size();
			Node* newnode = new Node(data);

			// 头插
			newnode->_next = _tables[index];
			_tables[index] = newnode;
			++_n;

			return make_pair(iterator(newnode, this), true);
		}

		void _CheckCapacity()
		{
			// 当表为空或者负载因子为1的时候扩容
			if (_tables.size() == 0 || _n == _tables.size())
			{
				// 与闭散列不同，开散列这里不推荐新建一个哈希表进行插入，而是直接新建一个vector插入即可
				size_t newSize = GetNextPrime(_tables.size());
				vector<Node*> newTables(newSize);

				KeyOfT kt;
				HashFunc _hs; // 哈希函数

				for (size_t i = 0; i < _tables.size(); ++i)
				{
					Node* cur = _tables[i];

					// 重新头插到newTables
					while (cur != nullptr)
					{
						Node* next = cur->_next;

						// 头插
						size_t index = _hs(kt(cur->_data)) % newTables.size();
						cur->_next = newTables[index];
						newTables[index] = cur;

						// 继续往下循环遍历单链表
						cur = next;
					}

					// 保险起见，将旧表_tables的指针变成空指针
					_tables[i] = nullptr;
				}
				_tables.swap(newTables);
			}
		}

		iterator find(const K& key)
		{
			if (_tables.size() == 0)
				return iterator(nullptr, this);

			KeyOfT kt;
			HashFunc _hs; // 哈希函数

			size_t index = _hs(key) % _tables.size();
			Node* cur = _tables[index];
			while (cur != nullptr)
			{
				if (kt(cur->_data) == key)
					return iterator(cur, this);
				cur = cur->_next;
			}
			return iterator(nullptr, this);
		}

		bool erase(const K& key)
		{
			if (_tables.size() == 0)
				return false;

			KeyOfT kt;
			HashFunc _hs; // 哈希函数

			size_t index = _hs(key) % _tables.size();
			Node* pre = nullptr;
			Node* cur = _tables[index];
			while (cur != nullptr)
			{
				if (kt(cur->_data) != key)
				{
					pre = cur;
					cur = cur->_next;
				}
				else
				{
					// 找到了开始删除
					if (pre == nullptr) // 头删
					{
						_tables[index] = cur->_next;
					}
					else // 中间删
					{
						pre->_next = cur->_next;
					}
					delete cur;
					// 记得减少有效个数
					--_n;

					return true;
				}
			}

			// 没找到直接返回false
			return false;
		}

		// 返回哈希桶中桶的总个数
		size_t bucket_count() const 
		{
			return _tables.size();
		}

		// 返回n号桶中有效元素的总个数
		size_t bucket_size(size_t n) const
		{
			size_t count = 0;
			Node* cur = _tables[n];
			while (cur != nullptr)
			{
				count++;
				cur = cur->_next;
			}
			return count;
		}

		// 返回元素key所在的桶号
		size_t bucket(const K& key) const
		{
			HashFunc hs;
			return hs(key) % _tables.size();
		}
	private:
		vector<Node*> _tables; // 指针数组
		size_t _n = 0; // 有效数据个数
	};
}