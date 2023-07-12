#pragma once
#include "HashTables.h"

namespace liren
{
	template <class K, class HashFunc = Hash<K>>
	class unordered_set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:
		typedef typename LinkHash::hashtable<K, K, SetKeyOfT, HashFunc>::iterator iterator;

		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}

		pair<iterator, bool> insert(const K& key)
		{
			return _ht.insert(key);
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
			SetKeyOfT kt;
			return _ht.bucket(key);
		}
	private:
		LinkHash::hashtable<K, K, SetKeyOfT, Hash<K>> _ht;
	};

	void testset()
	{
		unordered_set<int> st;
		int a[] = { 4, 24, 14,7,37,27,57,67,34,14,54 };
		for (auto e : a)
			st.insert(e);

		auto it = st.begin();
		while (it != st.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : a)
			st.erase(e);
	}
}