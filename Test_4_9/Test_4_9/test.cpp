#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//int main()
//{
//	//int* p1 = new int;  // 不会初始化
//	int* p1 = new int(10); // 申请一个int，初始化10
//	int* p3 = new int[10]; // 申请10个int的数组
//	int* p4 = new int[10] {1, 2, 3, 4};
//
//	int* p2 = (int*)malloc(sizeof(int));
//	if (p2 == nullptr)
//	{
//		perror("malloc fail");
//	}
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

class Stack
{
public:
	Stack()
	{
		cout << "Stack()" << endl;
		_a = new int[4];
		_top = 0;
		_capacity = 4;
	}

	~Stack()
	{
		cout << "~Stack()" << endl;
		delete[] _a;
		_top = _capacity = 0;
	}

private:
	int* _a;
	int _top;
	int _capacity;
};

// 匹配使用，不要交叉，否则结果是不确定
int main()
{
	// new/delete 和 malloc/free最大区别是 new/delete对于【自定义类型】除了开空间还会调用构造函数和析构函数
	A* p1 = (A*)malloc(sizeof(A));
	A* p2 = new A(1);
	free(p1);
	delete p2;

	// 内置类型是几乎是一样的
	int* p3 = (int*)malloc(sizeof(int)); // C
	int* p4 = new int;
	free(p3);
	delete p4;
	//delete p3;
	//free(p4);

	A* p5 = (A*)malloc(sizeof(A)* 10);
	A* p6 = new A[10];
	delete p5;
	delete[] p6;

	return 0;
}

//int main()
//{
//	// 失败了抛异常
//	//int* p1 = (int*)operator new(sizeof(int*));
//
//	//// 失败返回nullptr
//	//int* p2 = (int*)malloc(sizeof(int*));
//	//if (p2 == nullptr)
//	//{
//	//	perror("malloc fail");
//	//}
//
//	// 申请空间 operator new -> 封装malloc
//	// 调用构造函数
//	A* p5 = new A;
//
//	// 先调用析构函数
//	// 再operator delete p5指向的空间
//	// operator delete -> free
//	delete p5;
//
//	// 申请空间 operator new[] ->perator new-> 封装malloc
//	// 调用10次构造函数
//	A* p6 = new A[10];
//	
//	// 先调用10次析构函数
//	// 再operator delete[] p6指向的空间
//	delete[] p6;
//
//
//	int* p7 = new int[10];
//	free(p7);  // 正常释放
//
//	A* p8 = new A;
//	//free(p8); // 少调用了析构函数
//	delete p8;
//
//	Stack st;
//
//	Stack* pst = new Stack;
//	//delete pst;
//	free(pst); // 少调用了析构函数 -- 有内存泄漏
//
//	// 结论：new/malloc系列 由于底层实现机制有关联交叉。不匹配使用
//	// 可能有问题，可能没问题，建议大家一定匹配使用
//
//	A* p9 = new A[10];
//	//free(p9);
//	//delete p9;
//	delete[] p9;
//
//	return 0;
//}
//int main()
//{
//	size_t size = 0;
//	while (1)
//	{
//		int* p1 = (int*)malloc(1024 * 1024 * 4);
//		if (p1 == nullptr)
//		{
//			break;
//		}
//
//		size += 1024 * 1024 * 4;
//		cout << p1 << endl;
//	}
//
//	cout << size << endl;
//	cout << size / 1024 / 1024 << "MB" << endl;
//
//
//	return 0;
//}


//int main()
//{
//	size_t size = 0;
//
//	try
//	{
//		while (1)
//		{
//			int* p1 = new int[1024 * 1024 * 4];
//			size += 1024 * 1024 * 4;
//			cout << p1 << endl;
//		}
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	cout << size << endl;
//	cout << size / 1024 / 1024 << "MB" << endl;
//
//
//	return 0;
//}

//int main()
//{
//	A aa;
//
//	A* p1 = (A*)malloc(sizeof(A));
//	if (p1 == nullptr)
//	{
//		perror("malloc fail");
//	}
//
//	// 对一块已有的空间初始化 -- 定义new
//	//new(p1)A;
//	new(p1)A(1);
//
//	A* p2 = new A;
//
//	p1->~A();
//	free(p1);
//
//	delete p2;
//
//
//	return 0;
//}

//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//
//void Swap(double& left, double& right)
//{
//	double temp = left;
//	left = right;
//	right = temp;
//}