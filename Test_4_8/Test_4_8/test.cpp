#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//int main()
//{
//	int* p2 = (int*)calloc(4, sizeof (int));
//	int* p3 = (int*)realloc(p2, sizeof(int)* 100);
//
//	cout << p2 << endl;
//	cout << p3 << endl;
//
//	// 这里需要free(p2)吗？
//	//free(p2);
//	free(p3);
//
//	return 0;
//}

class A
{
public:
	A(int a = 0)
		: _a(a)
	{
		cout << "A():" << this << endl;
	}

	~A()
	{
		cout << "~A():" << this << endl;
	}

private:
	int _a;
};

struct ListNode
{
	int _val;
	ListNode* _next;

	ListNode(int val)
		:_val(val)
		, _next(nullptr)
	{}
};

//ListNode BuyListNode(int x)
//{
//	//...
//}

int main()
{
	int* pp1 = (int*)malloc(sizeof(int));
	int* p1 = new int;

	free(pp1);

	delete p1;

	int* pp2 = (int*)malloc(sizeof(int) * 10);
	int* p2 = new int[10];

	free(pp2);
	delete[] p2;

	A* pp3 = (A*)malloc(sizeof(A));
	free(pp3);

	A* p3 = new A(1);
	delete p3;

	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);


	return 0;
}