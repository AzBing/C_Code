#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <map>
#include <set>
using namespace std;

void test_set1()
{
	// 查找在不在
	// 排序 + 去重
	set<int> s;
	s.insert(5);
	s.insert(2);
	s.insert(6);
	s.insert(1);
	s.insert(1);
	s.insert(2);

	auto ret1 = s.insert(5);
	cout << ret1.second << endl;

	pair<set<int>::iterator, bool> ret2 = s.insert(5);
	cout << ret2.second << endl;

	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		//*it = 10;
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	// 删除存在的
	s.erase(2);

	//set<int>::iterator it = s.find(3);
	it = s.find(30);
	if (it != s.end())
	{
		s.erase(it);
	}

	if (s.count(3))
	{
		cout << "3在" << endl;
	}
	else
	{
		cout << "3不在" << endl;
	}

	// 删除不存在的
	s.erase(3);

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_set2()
{
	std::set<int> myset;
	std::set<int>::iterator itlow, itup;

	for (int i = 1; i < 10; i++) myset.insert(i * 10); // 10 20 30 40 50 60 70 80 90


	//itlow = myset.lower_bound(30);              //
	itlow = myset.lower_bound(25);                // >= val值位置的iterator
	itup = myset.upper_bound(70);                 // >  val值位置的iterator

	// [25, 70]
	myset.erase(itlow, itup);                     // 10 20 70 80 90

	for (auto e : myset)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_set3()
{
	std::set<int> myset;

	for (int i = 1; i <= 5; i++) myset.insert(i * 10);   // myset: 10 20 30 40 50

	//std::pair<std::set<int>::const_iterator, std::set<int>::const_iterator> ret;
	auto ret = myset.equal_range(35);

	std::cout << "the lower bound points to: " << *ret.first << '\n';   // >= val
	std::cout << "the upper bound points to: " << *ret.second << '\n';  // > val
}

void test_set4()
{
	// 排序
	multiset<int> s;
	s.insert(5);
	s.insert(2);
	s.insert(6);
	s.insert(1);
	s.insert(1);
	s.insert(2);
	s.insert(1);
	s.insert(5);
	s.insert(2);

	multiset<int>::iterator it = s.begin();
	while (it != s.end())
	{
		//*it = 10;
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	// 如果有多个值，find返回中序第一个val
	it = s.find(2);
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	cout << s.count(1) << endl;

	// [>=val, >val)
	//auto ret = s.equal_range(2);
	//s.erase(ret.first, ret.second);
	size_t n = s.erase(2);
	cout << n << endl;
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

int main()
{
	test_set1();

	return 0;
}

