#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//namespace bit
//{
//	int rand = 0;
//}
//
//int main()
//{
//	printf("hello world\n");
//	printf("%p\n", rand);
//
//	// �������޶���::
//	printf("%p\n", bit::rand);
//
//	return 0;
//}

//namespace bit
//{
//	// �����ռ��п��Զ������/����/����
//	int rand = 10;
//
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//
//	struct Node
//	{
//		struct Node* next;
//		int val;
//	};
//
//	namespace xxx
//	{
//		int rand = 1;
//	}
//}

//int Add(int left, int right)
//{
//	return (left + right) * 10;
//}

//int main()
//{
//	printf("%d\n", bit::rand);
//	printf("%d\n", bit::Add(1,2));
//	printf("%d\n", Add(1, 2));
//
//	struct bit::Node node;
//
//	return 0;
//}

// ȫ��չ��(��Ȩ)
// using namespace bit;

// ����չ��(��Ȩ)
//using bit::Add;
//
//int main()
//{
//	printf("%p\n", rand);
//	printf("%d\n", bit::rand);
//	printf("%d\n", bit::xxx::rand);
//
//	printf("%d\n", Add(1, 2));
//	printf("%d\n", Add(1, 2));
//	printf("%d\n", Add(1, 2));
//	printf("%d\n", Add(1, 2));
//	printf("%d\n", Add(1, 2));
//
//	struct bit::Node node;
//
//	return 0;
//}


#include<iostream>

// #include<iostream.h>

//using namespace std;

using std::cout;
using std::endl;

#include"Stack.h"
#include"Queue.h"

//int main()
//{
//	// << �����������
//	cout << "hello world" << endl;
//	cout << "hello world" << '\n';
//	cout << "hello world" << endl;
//
//	bit::StackInit();
//	bit::QueueInit();
//
//	// ����ȡ
//	int i = 0;
//	std::cin >> i;
//
//	return 0;
//}

//int main()
//{
//	int i;
//	double j;
//	std::cin >> i >> j;
//
//	cout << i << endl;
//	cout << j << endl;
//	printf("%.1f\n", j);
//
//	cout << &i << endl;
//	cout << &j << endl;
//
//	return 0;
//}

// ȱʡ����
//void Func(int a = 1)
//{
//	cout << a << endl;
//}
//
//int main()
//{
//	Func(2);
//
//	Func();
//
//	return 0;
//}

// ȫȱʡ
//void Func(int a = 10, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl << endl;
//}
//
//int main()
//{
//	Func();
//
//	// ��ʾ���Σ�����������ʾ����
//	Func(1);
//	Func(1,2);
//	Func(1, 2, 3);
//
//	return 0;
//}

// ��ȱʡ -- ����������󣬸�ȱʡֵ
void Func(int a, int b = 10, int c = 20)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}


// 17:25����
//int main()
//{
//	Func(1);
//	Func(1,2);
//	Func(1, 2, 3);
//
//	bit::ST st1;
//	StackInit(&st1, 10);
//	for (size_t i = 0; i < 10; i++)
//	{
//		StackPush(&st1, i);
//	}
//
//	bit::ST st2;
//	StackInit(&st2, 100);
//	for (size_t i = 0; i < 100; i++)
//	{
//		StackPush(&st2, i);
//	}
//
//	// ��֪�����ܻ������ٸ�
//	bit::ST st3;
//	StackInit(&st3);
//
//	return 0;
//}

// C���Բ�����ͬ������
// CPP���ԣ�����Ҫ�󹹳ɺ�������
// ��������ͬ��������ͬ

int Add(int left, int right)
{
	cout << "int Add(int left, int right)" << endl;

	return left + right;
}

double Add(double left, double right)
{
	cout << "double Add(double left, double right)" << endl;

	return left + right;
}

void Swap(int* p1, int* p2)
{
	//...
}

void Swap(double* p1, double* p2)
{
	//...
}

void f(int a, char b)
{
	cout << "f(int a,char b)" << endl;
}

void f(char a, int b)
{
	cout << "f(int a,char b)" << endl;
}

// ����ֵ��ͬ���ܹ�������
//int f(char a, int b)
//{
//	cout << "f(int a,char b)" << endl;
//}

//namespace bit1
//{
//	void func(int x)
//	{}
//}
//
//namespace bit1
//{
//	void func(double x)
//	{}
//}

//int main()
//{
//	cout << Add(1, 2) << endl;
//	cout << Add(1.1, 2.2) << endl;
//
//	int i = 1, j = 2;
//	double k = 1.1, l = 2.2;
//	Swap(&i, &j);
//	Swap(&k, &l);
//	//cout << i;
//	//cout << k;
//
//	return 0;
//}

// ���ɺ�������
void func(int a)
{
	cout << "void func(int a)" << endl;
}

void func(int a, int b = 1)
{
	cout << "void func(int a, int b)" << endl;
}

int main()
{
	func(1, 2);

	// ���ô������壬��֪�������ĸ�
	// func(1);


	return 0;
}

