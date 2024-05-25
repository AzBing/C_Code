#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<set>
#include<map>
using namespace std;


void test_map1()
{
	map<string, string> dict;
	dict.insert(pair<string, string>("sort", "排序"));
	dict.insert(pair<string, string>("insert", "插入"));
	dict.insert(pair<const char*, const char*>("left", "左边"));

	dict.insert(make_pair("right", "右边")); // 推荐这个

	dict["erase"];  // 插入
	cout << dict["erase"] << endl; // 查找
	dict["erase"] = "删除"; // 修改
	cout << dict["erase"] << endl;// 查找
	dict["test"] = "测试";  // 插入+修改
	dict["left"] = "左边、剩余"; // 修改



	// 
	string s1("xxx"), s2("yyy");
	dict.insert(make_pair(s1, s2));

	map<string, string>::iterator it = dict.begin();
	while (it != dict.end())
	{
		cout << (*it).first << ":" << (*it).second << endl;
		cout << it.operator->()->first << ":" << it.operator->()->second << endl;
		cout << it->first << ":" << it->second << endl;

		++it;
	}
	cout << endl;

	for (auto& kv : dict)
	{
		// kv.first += 'x';
		kv.second += 'x';

		cout << kv.first << ":" << kv.second << endl;
	}
}

void test_map2()
{
	string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" };
	map<string, int> countMap;
	//for (auto& str : arr)
	//{
	//	//auto ret = countMap.find(str);
	//	//if (ret == countMap.end())
	//	//{
	//	//	// 么有表示第一次出现，插入
	//	//	countMap.insert(make_pair(str, 1));
	//	//}
	//	//else
	//	//{
	//	//	// 次数++
	//	//	ret->second++;
	//	//}
	//	countMap[str]++;
	//}

	for (auto& str : arr)
	{
		countMap[str]++;
	}

	for (auto& kv : countMap)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
}

int main()
{
	test_map1();

	return 0;
}