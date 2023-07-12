#pragma once
#include "RBTree.h"

namespace liren
{
	template <class K>
	class set
	{
	public:
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:
		typedef typename RBTree<K, K, SetKeyOfT>::iterator iterator;
		typedef typename RBTree<K, K, SetKeyOfT>::reverse_iterator reverse_iterator;
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

		pair<iterator, bool> insert(const K& key)
		{
			return _t.Insert(key);
		}
	private:
		RBTree<K, K, SetKeyOfT> _t;
	};
}