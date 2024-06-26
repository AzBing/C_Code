#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#include "SmartPtr.h"

void TestSmartPtr1()
{
	SmartPtr<int> sp1(new int);
	*sp1 = 1;

	SmartPtr<pair<string, int>> sp2(new pair<string, int>("xxxx", 1));
	sp2->first += 'y';
	sp2->second += 1;
	sp2.operator->()->second += 1;
}

void TestSmartPtr2()
{
	SmartPtr<int> sp1(new int);
	SmartPtr<int> sp2 = sp1;
}

void test_auto_ptr1()
{
	Ptr::auto_ptr<int> ap1(new int);
	Ptr::auto_ptr<int> ap2 = ap1;

	// 管理权转移，导致对象悬空
	//(*ap1)++;
	//(*ap2)++;
}

int main()
{
	//TestSmartPtr2();
	test_auto_ptr1();

	return 0;
}
