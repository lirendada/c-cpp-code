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

namespace CloseHash
{
	enum Status
	{
		EXIST,
		EMPTY,
		DELETE
	};

	template <class K, class V>
	struct HashData
	{
		pair<K, V> _kv;
		Status _status = EMPTY;
	};

	template <class K, class V, class HashFunc = Hash<K>>
	class hashtable
	{
	public:
		bool insert(const pair<K, V>& kv)
		{
			// 进来先判断是否存在重复的元素
			HashData<K, V>* ret = find(kv.first);
			if (ret)
				return false;

			// 每次判断是否需要扩容
			_CheckCapacity();

			HashFunc _hs; //哈希函数

			// 采用除留余数法
			size_t start = _hs(kv.first) % _tables.size();
			size_t i = 0;
			size_t index = start; // 这里多定义一个index是为了等会的二次探测的代码兼容性

			// 线性探测
			while (_tables[index]._status == EXIST)
			{
				i++;

				//index = start + i * i;
				index = start + i;

				index %= _tables.size(); // 记得取模哈希表的长度，防止越界出去
			}

			// 插入新元素
			_tables[index]._kv = kv;
			_tables[index]._status = EXIST;
			_n++;

			return true;
		}

		void _CheckCapacity()
		{
			// 当表的大小为0 或者 负载因子超过0.7 则扩容
			
			// 负载因子越小，冲突的概率越小，效率越高，但是空间浪费就太大
			// 负载因子越大，冲突的概率越大，效率就越低，但是空间浪费就比较小
			if (_tables.size() == 0 || (_n * 10) / _tables.size() > 7)
			{
				// 扩容
				size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				hashtable<K, V> newTables;
				newTables._tables.resize(newSize);

				// 这里不能直接调用vector的扩容函数，因为扩容后我们需要对表里的数据重新定位
				// 方法：遍历原表，把原表中的数据，重新按newSize映射到新表
				for (size_t i = 0; i < _tables.size(); ++i)
				{
					if (_tables[i]._status == EXIST)
						newTables.insert(_tables[i]._kv);
				}

				// 最后交换新表和旧表的内容
				_tables.swap(newTables._tables);
			}
		}

		HashData<K, V>* find(const K& key)
		{
			if (_tables.size() == 0)
				return nullptr;

			HashFunc _hs; //哈希函数

			// 按insert的监测方式查找
			size_t start = _hs(key) % _tables.size();
			size_t i = 0;
			size_t index = start + i;
			while (_tables[index]._status != EMPTY)
			{
				// 这里必须加_status == EXIST，因为不加的话在删除后还是能查到该值
				if (_tables[index]._kv.first == key && _tables[index]._status == EXIST)
					return &_tables[index];

				i++;
				//index = start + i * i;
				index = start + i;
				index %= _tables.size();
			}
			// 没找到则返回空
			return nullptr;
		}

		bool erase(const K& key)
		{
			HashData<K, V>* ret = find(key);
			if (ret == nullptr)
			{
				return false;
			}
			else
			{
				--_n;
				ret->_status = DELETE;
				return true;
			}
		}
	private:
		vector<HashData<K, V>> _tables;
		size_t _n = 0; // 有效数据个数
	};
}

namespace LinkHash
{
	template <class K, class V>
	struct HashNode
	{
		pair<K, V> _kv;
		HashNode<K, V>* _next;

		HashNode(const pair<K, V>& kv, HashNode<K, V>* next = nullptr)
			:_kv(kv)
			, _next(next)
		{}
	};

	template <class K, class V, class HashFunc = Hash<K>>
	class hashtable
	{
		typedef HashNode<K, V> Node;
	public:
		bool insert(const pair<K, V>& kv)
		{
			// 检测是否有重复元素
			Node* ret = find(kv.first);
			if (ret != nullptr)
				return false;

			// 检测是否需要扩容
			_CheckCapacity();

			HashFunc _hs; // 哈希函数
			size_t index = _hs(kv.first) % _tables.size();
			Node* newnode = new Node(kv);
			
			// 头插
			newnode->_next = _tables[index];
			_tables[index] = newnode;
			++_n;

			return true;
		}

		void _CheckCapacity()
		{
			// 当表为空或者负载因子为1的时候扩容
			if (_tables.size() == 0 || _n == _tables.size())
			{
				// 与闭散列不同，开散列这里不推荐新建一个哈希表进行插入，而是直接新建一个vector插入即可
				size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				vector<Node*> newTables(newSize);

				HashFunc _hs; // 哈希函数

				for (size_t i = 0; i < _tables.size(); ++i)
				{
					Node* cur = _tables[i];

					// 重新头插到newTables
					while (cur != nullptr)
					{
						Node* next = cur->_next;
						
						// 头插
						size_t index = _hs(cur->_kv.first) % newTables.size();
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

		Node* find(const K& key)
		{
			if (_tables.size() == 0)
				return nullptr;

			HashFunc _hs; // 哈希函数

			size_t index = _hs(key) % _tables.size();
			Node* cur = _tables[index];
			while (cur != nullptr)
			{
				if (cur->_kv.first == key)
					return cur;
				cur = cur->_next;
			}
			return nullptr;
		}
		
		bool erase(const K& key)
		{
			if (_tables.size() == 0)
				return false;

			HashFunc _hs; // 哈希函数

			size_t index = _hs(key) % _tables.size();
			Node* pre = nullptr;
			Node* cur = _tables[index];
			while (cur != nullptr)
			{
				if (cur->_kv.first != key)
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
	private:
		vector<Node*> _tables; // 指针数组
		size_t _n = 0; // 有效数据个数
	};
}