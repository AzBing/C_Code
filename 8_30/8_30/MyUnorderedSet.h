#pragma once
#include "HashTable.h"

namespace Ht
{
	template<class K>
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
		typedef typename hash_bucket::HashTable<K, K, SetKeyOfT>::iterator iterator;

		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}

		bool insert(const K& key)
		{
			return _ht.Insert(key);
		}

	private:
		hash_bucket::HashTable<K, K, SetKeyOfT> _ht;
	};

	void test_set()
	{
		unordered_set<int> st;
		st.insert(1);
		st.insert(2);
		st.insert(3);
		st.insert(4);
		st.insert(5);

		unordered_set<int>::iterator it = st.begin();
		while (it != st.end())
		{
			//*it += 5;
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

}




