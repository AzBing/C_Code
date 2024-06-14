#pragma once
#include "HashTable.h"
namespace Ha
{
	template<class K, class V>
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
		typedef typename hash_bucket::HashTable<K, pair<K, V>, MapKeyOfT>::iterator iterator;

		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}

		bool insert(const pair<K, V>& kv)
		{
			return _ht.Insert(kv);
		}
	private:
		hash_bucket::HashTable<K, pair<K, V>, MapKeyOfT> _ht;
	};
	void test_map()
	{
		unordered_map<string, string> dict;
		dict.insert(make_pair("sort", "ÅÅĞò"));
		dict.insert(make_pair("string", "×Ö·û´®"));
		dict.insert(make_pair("insert", "²åÈë"));
		for (auto& kv : dict)
		{
			//kv.first += 'x';
			//kv.second += 'x';

			cout << kv.first << ":" << kv.second << endl;
		}
		cout << endl;

	}
}
