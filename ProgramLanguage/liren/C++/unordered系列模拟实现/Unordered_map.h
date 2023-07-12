#pragma once
#include "HashTables.h"

namespace liren
{
	template <class K, class V, class HashFunc = Hash<K>>
	class unordered_map
	{
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};
	public:
		typedef typename LinkHash::hashtable<K, pair<K, V>, MapKeyOfT, HashFunc>::iterator iterator;

		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}

		pair<iterator, bool> insert(const pair<K, V>& kv)
		{
			return _ht.insert(kv);
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = insert(make_pair(key, V()));
			return ret.first->second;
		}

		iterator find(const K& key)
		{
			return _ht.find(key);
		}

		bool erase(const K& key)
		{
			return _ht.erase(key);
		}

		size_t bucket_count() const
		{
			return _ht.bucket_count();
		}

		size_t bucket_size(size_t n) const
		{
			return _ht.bucket_size(n);
		}

		size_t bucket(const K& key)
		{
			return _ht.bucket(key);
		}
	private:
		LinkHash::hashtable<K, pair<K, V>, MapKeyOfT, Hash<K>> _ht;
	};

	void testmap1()
	{
		unordered_map<int, int> mp;
		int a[] = { 4, 24, 14,7,37,27,57,67,34,14,54 };
		for (auto e : a)
			mp.insert(make_pair(e, e));

		auto it = mp.begin();
		while (it != mp.end())
		{
			cout << it->first << ":" << it->second << " ";
			++it;
		}
		cout << endl;

		/*for (auto& e : mp)
		{
			e.second = 1;
			cout << e.second << " ";
		}*/
		//mp[24] = 1;

		/*for (auto e : a)
			mp.erase(e);*/
		it = mp.begin();
		while (it != mp.end())
		{
			cout << it->first << ":" << it->second << " ";
			it++;
		}
		cout << endl;

		unordered_map<int, int> copy(mp);
		for (auto& e : copy)
		{
			cout << e.first << " " << e.second << " ";
		}
	}

	void testmap2()
	{
		unordered_map<int, int> mp;
		int a[] = { 4, 24, 14,7,37,27,57,67,34,14,54 };
		for (auto e : a)
			mp.insert(make_pair(e, e));

		auto it = mp.begin();
		while (it != mp.end())
		{
			cout << it->first << ":" << it->second << " ";
			++it;
		}
		cout << endl;

		cout << mp.bucket_count() << endl;
		cout << mp.bucket_size(4) << endl;
		cout << mp.bucket_size(0) << endl;

		it = mp.begin();
		while (it != mp.end())
		{
			cout << mp.bucket(it->first) << endl;
			++it;
		}
	}
}