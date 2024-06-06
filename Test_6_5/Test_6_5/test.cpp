#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;

#include"RBTree.h"
#include"MyMap.h"
#include"MySet.h"

void test_set()
{
	bit::set<int> s;
	s.insert(4);
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(2);
	s.insert(0);
	s.insert(10);
	s.insert(5);

	bit::set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		//*it += 1;

		cout << *it << " ";
		++it;
	}
	cout << endl;

	// key
	/*it = s.begin();
	*it = 100;*/

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_map()
{
	bit::map<string, string> dict;
	dict.insert(make_pair("sort", "排序"));
	dict.insert(make_pair("sort", "整理"));
	dict.insert(make_pair("left", "左边"));
	dict.insert(make_pair("right", "右边"));

	bit::map<string, string>::iterator it = dict.begin();
	while (it != dict.end())
	{
		// key
		/*it->first += 'x';
		it->second += 'y';*/

		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;

	string arr[] = { "苹果", "苹果","西瓜", "苹果", "西瓜", "香蕉", "苹果", "橘子", "苹果", "西瓜", "香蕉", "苹果", "西瓜" };
	bit::map<string, int> countMap;
	for (auto& e : arr)
	{
		countMap[e]++;
	}

	for (auto& kv : countMap)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;
}

int main()
{
	test_map();
	test_set();

	return 0;
}