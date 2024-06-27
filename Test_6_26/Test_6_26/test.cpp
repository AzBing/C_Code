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

//template<class T>
//Ptr::unique_ptr<T>::unique_ptr(const Ptr::unique_ptr<T>& up)
//	:_ptr(up._ptr)
//{}
//
//void test_unique_ptr1()
//{
//	std::unique_ptr<int> up1(new int(1));
//	//std::unique_ptr<int> up2 = up1;
//
//	std::unique_ptr<int> up3(new int(2));
//	//up1 = up3;
//}

void test_shared_ptr2()
{
	Ptr::shared_ptr<string> sp1(new string("xxxxxxxxxxxxxxxxxx"));
	Ptr::shared_ptr<string> sp2(sp1);

	Ptr::shared_ptr<string> sp3(new string("yyyyyyyyy"));

	//sp1 = sp3;
	//sp3 = sp1;

	sp3 = sp3;
	cout << *sp3 << endl;

	sp1 = sp2;
}

struct ListNode
{
	int val;
	Ptr::weak_ptr<ListNode> next;
	Ptr::weak_ptr<ListNode> prev;

	~ListNode()
	{
		cout << "~ListNode()" << endl;
	}
};

void test_shared_ptr3()
{
	Ptr::shared_ptr<ListNode> n1(new ListNode);
	Ptr::shared_ptr<ListNode> n2(new ListNode);
	cout << n1.use_count() << endl;
	cout << n2.use_count() << endl;

	// 循环引用
	n1->next = n2;
	n2->prev = n1;

	cout << n1.use_count() << endl;
	cout << n2.use_count() << endl;
}


int main()
{
	//TestSmartPtr2();
	//test_auto_ptr1();

	//test_unique_ptr1();

	test_shared_ptr3();

	return 0;
}
