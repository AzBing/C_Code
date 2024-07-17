#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

typedef char DataType;
class Stack
{
public:
	Stack(size_t capacity = 4)
	{
		cout << "Stack()" << endl;

		_array = new DataType[capacity];
		//_array = new char[0x7fffffff];

		_capacity = capacity;
		_size = 0;
	}

	void Push(DataType data)
	{
		// CheckCapacity();
		_array[_size] = data;
		_size++;
	}

	~Stack()
	{
		cout << "~Stack()" << endl;

		delete[] _array;
		_array = nullptr;
		_size = _capacity = 0;
	}
private:
	// 内置类型
	DataType* _array;
	int _capacity;
	int _size;
};

////Stack* func()
////{
////	int n;
////	cin >> n;
////	Stack* pst = new Stack(n);
////
////	return pst;
////}

//int main()
//{
//	Stack* ptr = func();
//	ptr->Push(1);
//	ptr->Push(2);
//	// ....
//
//	delete ptr;
//
//	return 0;
//}
//
//void func()
//{
//	Stack st;
//	//char* p1 = new char[0x7fffffff];
//
//	char* p1 = new char[1000000000];
//	cout << (void*)p1 << endl;
//
//	cout << "hello world" << endl;
//}

//int main()
//{
//	try
//	{
//		func();
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}

class A
{
public:
	A(int a = 0)
		:_a1(a)
	{}

	~A()
	{
		cout << "~A()" << endl;
	}

private:
	int _a1;
};

//int main()
//{
//	Stack* pst1 = (Stack*)operator new(sizeof(Stack));
//	operator delete(pst1);
//
//
//	Stack* pst2 = new Stack;
//	//delete pst2;
//	//free(pst2);
//
//	//int* p1 = new int[10];
//	//free(p1);
//	//delete p1;
//	//delete[] p1;
//
//	A* p2 = new A[10];
//	//free(p2);
//	delete p2;
//	//delete (p2-1);
//	//delete[] p2;
//
//	return 0;
//}

int main()
{
	// 内存池
	Stack* pst1 = (Stack*)operator new(sizeof(Stack));
	//pst1->Stack(4); // 不支持
	new(pst1)Stack(4); // 显示调用构造函数

	pst1->~Stack();
	operator delete(pst1);

	return 0;
}

//int main()
//{
//	char* p1 = new char[1024 * 1024 * 1024];
// 
//	return 0;
//}