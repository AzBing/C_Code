#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;


int& Count()
{
	int n = 0;
	n++;
	// ...
	return n;
}

//int main()
//{
//
//	int& ref = Count();
//
//	int a = 0;
//	int* p1 = &a;
//	int& ref = a;
//
//	++(*p1);
//	++ref;
//
//	return 0;
//}

#define N 10
// 实现一个ADD的宏函数

// #define ADD(int x, int y) {return x+y;}
// #define ADD(x, y) (return x+y;)
// #define ADD(x, y) return x+y;

//#define ADD(x, y) x+y;
//#define ADD(x, y) x+y
//#define ADD(x, y) (x+y)
#define ADD(x, y) ((x)+(y))

inline int add(int x, int y)
{
	return x + y;
}

inline int func()
{
	int x1 = 0;
	int x2 = 0;
	int x3 = 0;
	int x4 = 0;

	int ret = 0;
	ret += x1;


	return ret;
}

//int main()
//{
//	ADD(1, 2);
//	printf("%d\n", ADD(1, 2));
//	printf("%d\n", ADD(1, 2)*3);
//
//	int a = 1, b = 2;
//	ADD(a | b, a & b); // (a|b + a&b)
//
//	//int ret = add(1, 2);
//	int ret = add(a|b, a&b);
//	printf("%d\n", ret);
//
//	ret = func();
//
//	// 只有声明
//	f(1);
//
//	fx();
//
//	return 0;
//}

// inline const enum

//int main()
//{
//	int a = 0;
//	//int b = a;
//	auto b = a;
//	auto c = &a;
//	auto& d = a;
//
//	// 普通场景没有什么价值
//	// 类型很长，就有价值，简化代码
//	std::vector<std::string> v;
//	//std::vector<std::string>::iterator it = v.begin();
//	auto it = v.begin();
//
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//	cout << typeid(it).name() << endl;
//
//	return 0;
//}

//void TestFor(int array[])
//{
//	for (auto& e : array)
//		cout << e << endl;
//}

//int main()
//{
//	int array[] = { 1, 2, 3, 4, 5 };
//
//	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
//		array[i] *= 2;
//
//	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
//		cout << array[i] << " ";
//	cout << endl;
//
//
//	for (auto& x : array)
//	{
//		x *= 2;
//	}
//
//	// 范围for
//	// 依次取数组中的数据赋值给e
//	// 自定判断结束
//	// 自动迭代
//	for (auto e : array)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	return 0;
//}

void f(int i)
{
	cout << "f(int)" << endl;
}

void f(int* p)
{
	cout << "f(int*)" << endl;
}

int main()
{
	f(0);
	f(NULL);
	f(nullptr);
	f((int*)NULL);

	return 0;
}