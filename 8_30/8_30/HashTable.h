#pragma once
#include <vector>

template<class K>
struct HashFunc
{
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};

template<>
struct HashFunc<string>
{
	size_t operator()(const string& key)
	{
		// BKDR
		size_t hash = 0;
		for (auto e : key)
		{
			hash *= 31;
			hash += e;
		}

		//cout << key << ":" << hash << endl;
		return hash;
	}
};

namespace hash_bucket
{

	template<class T>
	struct HashNode
	{
		HashNode* _next;
		T _data;

		HashNode(const T& data)
			:_data(data)
			,_next(nullptr)
		{}
	};

	template<class K, class T, class KeyOfT, class Hash>
	class HashTable;

	template<class K, class T, class KeyOfT, class Hash = HashFunc<K>>
	struct __HTiterator
	{
		typedef HashNode<T> Node;
		typedef __HTiterator<K, T, KeyOfT, Hash> Self;
		Node* _node;
		HashTable<K, T, KeyOfT, Hash>* _pht;
		size_t _hashi;

		__HTiterator(Node* node, HashTable<K, T, KeyOfT, Hash>* pht, size_t hashi)
			:_node(node)
			, _pht(pht)
			, _hashi(hashi)
		{}


		Self& operator++()
		{
			if (_node->_next)
			{
				_node = _node->_next;
			}
			else
			{
				++_hashi;
				while (_hashi < _pht->_tables.size())
				{
					if (_pht->_tables[_hashi])
					{
						_node = _pht->_tables[_hashi];
						break;
					}

					++_hashi;
				}
				if (_hashi == _pht->_tables.size())
				{
					_node = nullptr;
				}
			}
			return *this;
		}

		T& operator*()
		{
			return _node->_data;
		}

		bool operator!=(const Self& s)
		{
			return _node != s._node;
		}

	};

	template<class K, class T, class KeyOfT, class Hash = HashFunc<K>>
	class HashTable
	{
		typedef HashNode<T> Node;

		template<class K, class T, class KeyOfT, class Hash>
		friend struct __HTiterator;

	public:
		typedef __HTiterator<K, T, KeyOfT, Hash> iterator;

		iterator begin()
		{
			for (size_t i = 0; i < _tables.size(); i++)
			{
				if (_tables[i])
				{
					return iterator(_tables[i], this, i);
				}
			}
			return end();
		}

		iterator end()
		{
			return iterator(nullptr, this, -1);
		}

		HashTable()
		{
			_tables.resize(10);
		}

		~HashTable()
		{
			for (size_t i = 0; i < _tables.size(); i++)
			{
				Node* cur = _tables[i];
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}
				_tables[i] = nullptr;
			}
		}

		bool Insert(const T& data)
		{
			Hash hf;
			KeyOfT kt;

			if (Find(data))
				return false;

			if (_n == _tables.size())
			{
				vector<Node*> newTables;
				newTables.resize(_tables.size() * 2, nullptr);

				for (size_t i = 0; i < _tables.size(); i++)
				{
					Node* cur = _tables[i];
					while (cur)
					{
						Node* next = cur->_next;

						size_t hashi = hf(kt(cur->_data)) % newTables.size();
						cur->_next = newTables[i];
						newTables[i] = cur;

						cur = next;
					}
					_tables[i] = nullptr;
				}
				_tables.swap(newTables);
			}

			size_t hashi = hf(kt(data)) % _tables.size();
			Node* newnode = new Node(data);

			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;
			++_n;

			return true;
		}

		Node* Find(const T& data)
		{
			Hash hf;
			KeyOfT kt;

			size_t hashi = hf(kt(data)) % _tables.size();
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (kt(cur->_data) == data)
				{
					return cur;
				}
				cur = cur->_next;
			}

			return nullptr;
		}

		bool Erase(const K& key)
		{
			Hash hf;
			KeyOfT kt;

			size_t hashi = hf(key) % _tables.size();
			Node* prev = nullptr;
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (kt(cur->_data) == key)
				{
					if (prev == nullptr)
					{
						_tables[hashi] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;
					}
					delete cur;
					return true;
				}
				prev = cur;
				cur = cur->_next;
			}
			return false;
		}

	private:
		vector<Node*> _tables;
		size_t _n = 0;
	};

	//void TestHT1()
	//{
	//	HashTable<int, int> ht;
	//	int a[] = { 4,14,24,34,5,7,1,15,25,3 };
	//	for (auto e : a)
	//	{
	//		ht.Insert(make_pair(e, e));
	//	}

	//	ht.Insert(make_pair(13, 13));
	//}

	//void TestHT3()
	//{
	//	string arr[] = { "Ïã½¶", "Ìð¹Ï","Æ»¹û", "Î÷¹Ï", "Æ»¹û", "Î÷¹Ï", "Æ»¹û", "Æ»¹û", "Î÷¹Ï", "Æ»¹û", "Ïã½¶", "Æ»¹û", "Ïã½¶" };
	//	HashTable<string, int> ht;

	//	for (auto& e : arr)
	//	{
	//		//auto ret = ht.Find(e);
	//		HashNode<string, int>* ret = ht.Find(e);
	//		if (ret)
	//		{
	//			ret->_kv.second++;
	//		}
	//		else
	//		{
	//			ht.Insert(make_pair(e, 1));
	//		}
	//	}

	//}

}
