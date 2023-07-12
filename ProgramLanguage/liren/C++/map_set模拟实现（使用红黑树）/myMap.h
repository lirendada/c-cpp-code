#pragma once
#include "RBTree.h"

namespace liren
{
	template <class K, class V>
	class map
	{
	public:
		struct MapKeyOfT
		{
			const K& operator()(const pair<const K, V>& kv)
			{
				return kv.first;
			}
		};
	public:
		typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::iterator iterator;
		typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::reverse_iterator reverse_iterator;
	public:
		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

		reverse_iterator rbegin()
		{
			return _t.rbegin();
		}

		reverse_iterator rend()
		{
			return _t.end();
		}

		pair<iterator, bool> insert(const pair<const K, V>& kv)
		{
			return _t.Insert(kv);
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> res = insert(make_pair(key, V()));
			return res.first->second;
		}
	private:
		RBTree<K, pair<const K, V>, MapKeyOfT> _t;
	};
}