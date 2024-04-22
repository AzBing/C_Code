#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

//class A
//{
//public:
//	A(int i,int j)
//		:a(i)
//		,size(j)
//		,b()
//	{}
//private:
//	int a;
//	int size;
//	const int b;
//};
//
//int main()
//{
//	A aa(2,3);
//
//	return 0;
//}

//void test_string1()
//{
//	string s1("hello world");
//
//	for (size_t i = 0; i < s1.size(); i++)
//	{
//		s1[i]++;
//	}
//
//	cout << s1 << endl;
//
//	string::iterator i = s1.begin();
//	while (i != s1.end())
//	{
//		cout << *i << ' ';
//		++i;
//	}
//	cout << endl;
//
//	for (auto ch : s1)
//	{
//		cout << ch << ' ';
//	}
//	cout << endl;
//
//}
//void test_string2()
//{
//	string s1("hello world");
//
//	string::const_iterator i = s1.begin();
//	while (i != s1.end())
//	{
//		cout << *i << ' ';
//		++i;
//	}
//	cout << endl;
//
//	auto j = s1.begin();
//	while (j != s1.end())
//	{
//		cout << *j << ' ';
//		++j;
//	}
//	cout << endl;
//
//}
//
//int main()
//{
//	test_string2();
//
//	return 0;
//}
#include "string.h"

int main()
{
	bit::test_string6();

	return 0;
}


