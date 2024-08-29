#pragma once
#include <vector>

namespace HT
{
	enum Status
	{
		EMPTY,
		EXIST,
		DELETE
	};

	template<class K, class V>
	struct HashData
	{
		pair<K, V> _kv;
		Status _s;
	};

	template<class K, class V>
	class HashTable
	{
		HashTable()
		{
			_tables.resize(10);
		}
		bool Insert(const pair<K, V>& kv)
		{
			// À©ÈÝ
			if (_n * 10 / _tables.size() == 7)
			{
				size_t newSize = _tables.size() * 2;
				HashTable<K, V> newHT;
				newHT._tables.resize(newSize);

				for (int i = 0; i < _tables.size(); i++)
				{
					if (_tables[i] == EXIST)
					{
						newHT.Insert(_tables[i]._kv);
					}
				}

				_tables.swap(newHT._tables);
			}
			
			size_t hashi = kv.first % _tables.size();
			while (_tables[hashi]._s == EXIST)
			{
				hashi++;

				hashi %= _tables.size();
			}
			_tables[hashi]._kv = kv;
			_tables[hashi]._s = EXIST;
			++_n;

			return true;
		}


	private:
		vector<HashTable> _tables;
		size_t _n = 0;
	};
}
