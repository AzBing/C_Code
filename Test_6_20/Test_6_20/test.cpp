#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<map>
#include<array>
#include<algorithm>
#include<functional>
using namespace std;

#include<assert.h>

// 包装器
void swap_func(int& r1, int& r2)
{
	int tmp = r1;
	r1 = r2;
	r2 = tmp;
}

struct Swap
{
	void operator()(int& r1, int& r2)
	{
		int tmp = r1;
		r1 = r2;
		r2 = tmp;
	}
};

//int main()
//{
//	int x = 0, y = 1;
//	cout << x << " " << y << endl;
//
//	auto swaplambda = [](int& r1, int& r2) {
//		int tmp = r1;
//		r1 = r2;
//		r2 = tmp;
//	};
//
//	function<void(int&, int&)> f1 = swap_func;
//	f1(x, y);
//	cout << x << " " << y << endl << endl;
//
//	function<void(int&, int&)> f2 = Swap();
//	f2(x, y);
//	cout << x << " " << y << endl << endl;
//
//	function<void(int&, int&)> f3 = swaplambda;
//	f3(x, y);
//	cout << x << " " << y << endl << endl;
//
//	map<string, function<void(int&, int&)>> cmdOP = {
//		{"函数指针", swap_func},
//		{"仿函数", Swap()},
//		{"lambda", swaplambda},
//	};
//
//	cmdOP["函数指针"](x, y);
//	cout << x << " " << y << endl << endl;
//
//	cmdOP["仿函数"](x, y);
//	cout << x << " " << y << endl << endl;
//
//	cmdOP["lambda"](x, y);
//	cout << x << " " << y << endl << endl;
//
//	return 0;
//}

int f(int a, int b)
{
	return a + b;
}

struct Functor
{
public:
	int operator() (int a, int b)
	{
		return a + b;
	}
};

class Plus
{
public:
	static int plusi(int a, int b)
	{
		return a + b;
	}

	double plusd(double a, double b)
	{
		return a + b;
	}
};

int main()
{
	// 成员函数取地址，比较特殊，要加一个类域和&
	function<int(int, int)> f1 = &Plus::plusi;
	cout << f1(1, 2) << endl;

	function<double(Plus*, double, double)> f2 = &Plus::plusd;
	Plus ps;
	cout << f2(&ps, 1.1, 2.2) << endl;

	function<double(Plus, double, double)> f3 = &Plus::plusd;
	cout << f3(Plus(), 1.11, 2.22) << endl;

	function<double(double, double)> f4 = bind(&Plus::plusd, Plus(), placeholders::_1, placeholders::_2);
	cout << f4(1.11, 2.22) << endl;

	return 0;
}

int Sub(int a, int b)
{
	return a - b;
}

//int main()
//{
//	function<int(int, int)> f1 = Sub;
//	cout << f1(10, 5) << endl;
//
//	// 调整参数顺序
//	function<int(int, int)> f2 = bind(Sub, placeholders::_2, placeholders::_1);
//	cout << f2(10, 5) << endl;
//
//	// 调整参数个数，有些参数可以bind时写死
//	function<int(int)> f3 = bind(Sub, 20, placeholders::_1);
//	cout << f3(5) << endl;
//
//	return 0;
//}