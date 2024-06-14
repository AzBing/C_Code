#pragma once
#include "HashTable.h"
namespace Ha
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
		unordered_set<int> us;
		us.insert(5);
		us.insert(15);
		us.insert(52);
		us.insert(3);
		unordered_set<int>::iterator it = us.begin();
		while (it != us.end())
		{
			//*it += 5;
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : us)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}
