#pragma once

#include"RBTree.h"

namespace bit
{
	template<class K>
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

		bool insert(const K& key)
		{
			return _t.Insert(key);
		}

	private:
		RBTree<K, K, SetKeyOfT> _t;
	};
}
