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
	// ��Դ������������������������ڣ���Դ��Ч�������������ڵ��ˣ��ͷ���Դ
	// 1��RAII�ܿ���Դ�ͷ�
	// 2����ָ��һ��
	// 3����������
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
	// weak_ptr����RAII����ָ�룬ר���������shared_ptrѭ����������
	// weak_ptr���������ü��������Է�����Դ����������Դ�ͷŵĹ���
};

int main()
{
	//Node* n1 = new Node;
	//Node* n2 = new Node;
	////...

	//delete n1;
	//delete n2;

	// ѭ������
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