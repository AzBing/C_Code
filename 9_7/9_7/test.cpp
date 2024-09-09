#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<functional>
#include<vector>
using namespace std;

#include"SmartPtr.h"

template<class T>
class SmartPtr
{
public:
	// RAII
	// 资源交给对象管理，对象生命周期内，资源有效，对象生命周期到了，释放资源
	// 1、RAII管控资源释放
	// 2、像指针一样
	// 3、拷贝问题
	SmartPtr(T* ptr)
		:_ptr(ptr)
	{}

	~SmartPtr()
	{
		cout << "delete:" << _ptr << endl;
		delete _ptr;
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}
private:
	T* _ptr;
};

class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A(int a = 0)" << endl;
	}

	~A()
	{
		cout << this;
		cout << " ~A()" << endl;
	}
	//private:

	int _a;
};

struct Node
{
	A _val;
	//Node* _next;
	//Node* _prev;

	//bit::shared_ptr<Node> _next;
	//bit::shared_ptr<Node> _prev;

	bit::weak_ptr<Node> _next;
	bit::weak_ptr<Node> _prev;
	// weak_ptr不是RAII智能指针，专门用来解决shared_ptr循环引用问题
	// weak_ptr不增加引用计数，可以访问资源，不参与资源释放的管理
};

int main()
{
	//Node* n1 = new Node;
	//Node* n2 = new Node;
	////...

	//delete n1;
	//delete n2;

	// 循环引用
	bit::shared_ptr<Node> sp1(new Node);
	bit::shared_ptr<Node> sp2(new Node);

	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;

	sp1->_next = sp2;
	sp2->_prev = sp1;

	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;

	return 0;
}