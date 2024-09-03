#pragma once
#include"bit_set.h"

struct BKDRHash
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

		return hash;
	}
};

struct APHash
{
	size_t operator()(const string& key)
	{
		size_t hash = 0;
		for (size_t i = 0; i < key.size(); i++)
		{
			char ch = key[i];
			if ((i & 1) == 0)
			{
				hash ^= ((hash << 7) ^ ch ^ (hash >> 3));
			}
			else
			{
				hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));
			}
		}
		return hash;
	}
};

struct DJBHash
{
	size_t operator()(const string& key)
	{
		size_t hash = 5381;
		for (auto ch : key)
		{
			hash += (hash << 5) + ch;
		}
		return hash;
	}
};


template<size_t N, class K = string, class HashFunc1 = BKDRHash, class HashFunc2 = APHash, class HashFunc3 = DJBHash>
class BloomFilter
{
public:
	void Set(const K& key)
	{
		size_t hash1 = HashFunc1()(key) % N;
		size_t hash2 = HashFunc2()(key) % N;
		size_t hash3 = HashFunc3()(key) % N;

		_bs.set(hash1);
		_bs.set(hash2);
		_bs.set(hash3);
	}

	bool Test(const K& key)
	{
		// 判断不存在是准确的
		size_t hash1 = HashFunc1()(key) % N;
		if (_bs.test(hash1) == false)
			return false;
		size_t hash2 = HashFunc2()(key) % N;
		if (_bs.test(hash1) == false)
			return false;
		size_t hash3 = HashFunc3()(key) % N;
		if (_bs.test(hash1) == false)
			return false;
		// true可能存在误判
		return true;
	}


private:
	bit::bit_set<N> _bs;
};

void TestBF1()
{
	BloomFilter<100> bf;
	bf.Set("猪八戒");
	bf.Set("沙悟净");
	bf.Set("孙悟空");
	bf.Set("二郎神");

	cout << bf.Test("猪八戒") << endl;
	cout << bf.Test("沙悟净") << endl;
	cout << bf.Test("孙悟空") << endl;
	cout << bf.Test("二郎神") << endl;
	cout << bf.Test("二郎神1") << endl;
	cout << bf.Test("二郎神2") << endl;
	cout << bf.Test("二郎神 ") << endl;
	cout << bf.Test("太白晶星") << endl;
}

