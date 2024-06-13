#pragma once
template<class K>
struct HashFunc
{
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};

//HashFunc<string>
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

		cout << key << ":" << hash << endl;
		return hash;
	}
};

namespace hash_bucket
{
	template<class K, class V>
	struct HashNode
	{
		HashNode* _next;
		pair<K, V> _kv;

		HashNode(const pair<K, V>& kv)
			:_kv(kv)
			, _next(nullptr)
		{}
	};

	template<class K, class V, class Hash = HashFunc<K>>
	class HashTable
	{
		typedef HashNode<K, V> Node;
	public:
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

		bool Insert(const pair<K, V>& kv)
		{
			if (Find(kv.first))
				return false;

			Hash hf;

			// 负载因子最大到1
			if (_n == _tables.size())
			{
				vector<Node*> newTables;
				newTables.resize(_tables.size() * 2, nullptr);
				// 遍历旧表
				for (size_t i = 0; i < _tables.size(); i++)
				{
					Node* cur = _tables[i];
					while (cur)
					{
						Node* next = cur->_next;

						// 挪动到映射的新表
						size_t hashi = hf(cur->_kv.first) % newTables.size();
						cur->_next = newTables[i];
						newTables[i] = cur;

						cur = next;
					}

					_tables[i] = nullptr;
				}

				_tables.swap(newTables);
			}

			size_t hashi = hf(kv.first) % _tables.size();
			Node* newnode = new Node(kv);

			// 头插
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;
			++_n;

			return true;
		}

		Node* Find(const K& key)
		{
			Hash hf;
			size_t hashi = hf(key) % _tables.size();
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (cur->_kv.first == key)
				{
					return cur;
				}

				cur = cur->_next;
			}

			return NULL;
		}

		bool Erase(const K& key)
		{
			Hash hf;
			size_t hashi = hf(key) % _tables.size();
			Node* prev = nullptr;
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (cur->_kv.first == key)
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
		void Some()
		{
			size_t bucketSize = 0;
			size_t maxBucketLen = 0;
			size_t sum = 0;
			double averageBucketLen = 0;

			for (size_t i = 0; i < _tables.size(); i++)
			{
				Node* cur = _tables[i];
				if (cur)
				{
					++bucketSize;
				}

				size_t bucketLen = 0;
				while (cur)
				{
					++bucketLen;
					cur = cur->_next;
				}

				sum += bucketLen;

				if (bucketLen > maxBucketLen)
				{
					maxBucketLen = bucketLen;
				}
			}

			averageBucketLen = (double)sum / (double)bucketSize;

			printf("all bucketSize:%d\n", _tables.size());
			printf("bucketSize:%d\n", bucketSize);
			printf("maxBucketLen:%d\n", maxBucketLen);
			printf("averageBucketLen:%lf\n\n", averageBucketLen);
		}

	private:
		vector<Node*> _tables;
		size_t _n = 0;

	};
	void TestHT3()
	{
		const size_t N = 100000;

		unordered_set<int> us;
		set<int> s;
		HashTable<int, int> ht;

		vector<int> v;
		v.reserve(N);
		srand(time(0));
		for (size_t i = 0; i < N; ++i)
		{
			//v.push_back(rand()); // N比较大时，重复值比较多
			v.push_back(rand() + i); // 重复值相对少
			//v.push_back(i); // 没有重复，有序
		}

		size_t begin1 = clock();
		for (auto e : v)
		{
			s.insert(e);
		}
		size_t end1 = clock();
		cout << "set insert:" << end1 - begin1 << endl;

		size_t begin2 = clock();
		for (auto e : v)
		{
			us.insert(e);
		}
		size_t end2 = clock();
		cout << "unordered_set insert:" << end2 - begin2 << endl;

		size_t begin10 = clock();
		for (auto e : v)
		{
			ht.Insert(make_pair(e, e));
		}
		size_t end10 = clock();
		cout << "HashTbale insert:" << end10 - begin10 << endl << endl;


		size_t begin3 = clock();
		for (auto e : v)
		{
			s.find(e);
		}
		size_t end3 = clock();
		cout << "set find:" << end3 - begin3 << endl;

		size_t begin4 = clock();
		for (auto e : v)
		{
			us.find(e);
		}
		size_t end4 = clock();
		cout << "unordered_set find:" << end4 - begin4 << endl;

		size_t begin11 = clock();
		for (auto e : v)
		{
			ht.Find(e);
		}
		size_t end11 = clock();
		cout << "HashTable find:" << end11 - begin11 << endl << endl;

		cout << "插入数据个数：" << us.size() << endl << endl;
		ht.Some();

		size_t begin5 = clock();
		for (auto e : v)
		{
			s.erase(e);
		}
		size_t end5 = clock();
		cout << "set erase:" << end5 - begin5 << endl;

		size_t begin6 = clock();
		for (auto e : v)
		{
			us.erase(e);
		}
		size_t end6 = clock();
		cout << "unordered_set erase:" << end6 - begin6 << endl;

		size_t begin12 = clock();
		for (auto e : v)
		{
			ht.Erase(e);
		}
		size_t end12 = clock();
		cout << "HashTable Erase:" << end12 - begin12 << endl << endl;
	}

}
