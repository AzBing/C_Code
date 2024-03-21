#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<map>
#include<string>
using namespace std;

//#include "Func.h"
//
//int main()
//{
//	f(1);
//
//	return 0;
//}

////////////////////////////////////////////////////////////////////////////////////
// C++11

//int main()
//{
//	int a = 0;
//	//int b = a;
//	auto b = a;
//	auto c = &a;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//
//	// auto 实际价值 简化代码，类型很长时，可以考虑自动推导
//	map<string, string> dict;
//	typedef map<string, string>::iterator DictIt;
//	//map<string, string>::iterator dit = dict.begin();
//	//DictIt dit = dict.begin();
//	auto dit = dict.begin();
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
//	int a = 0;
//	auto b = &a;
//	auto* c = &a;
//	auto& d = a;
//
//	int array[] = { 1, 2, 3, 4, 5,6,6,4 };
//	for (int i = 0; i < sizeof(array) / sizeof(int); ++i)
//	{
//		cout << array[i] << " ";
//	}
//	cout << endl;
//
//	// 范围for -- 语法糖
//	// 自动依次取数组中数据赋值给e对象，自动判断结束
//	for (auto& e : array)
//	{
//		e *= 2;
//		cout << e << " ";
//	}
//	cout << endl;
//
//	//for (int x : array)
//	for (auto x : array)
//	{
//		cout << x << " ";
//	}
//	cout << endl;
//
//	return 0;
//}

//void f(int)
//{
//	cout << "f(int)" << endl;
//}
//
//void f(int*)
//{
//	cout << "f(int*)" << endl;
//}
//
//int main()
//{
//	/*int* p1 = NULL;
//	int* p2 = nullptr;*/
//	f(0);
//	f(NULL);
//	f(nullptr);
//
//	return 0;
//}

// C++兼容C结构体用法
//typedef struct ListNode
//{
//	int val;
//	struct ListNode* next;
//}LTN;
//
//// C struct ListNode是类型
//
//// C++把结构体升级成了类
//struct ListNode
//{
//	int val;
//	ListNode* next;
//};

// 类
// 成员函数直接定义到类里面
//struct Stack
//{
//	// 成员函数
//	void Init(int n = 4)
//	{
//		a = (int*)malloc(sizeof(int)* n);
//		if (nullptr == a)
//		{
//			perror("malloc申请空间失败");
//			return;
//		}
//
//		capacity = n;
//		size = 0;
//	}
//
//	void Push(int x)
//	{
//		//...
//		a[size++] = x;
//	}
//
//	// 成员变量
//	int* a;
//	int size;
//	int capacity;
//};

//#include "Stack.h"
//
//// 16:30继续
//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Stack st;
//	st.Init();
//	st.Push(1);
//	st.Push(2);
//	st.Push(3);
//
//	Date d1;
//	d1.Init(2023, 2, 3);
//
//	return 0;
//}

// 类 -- 别墅设计图
//class Date
//{
//public:
//	// 定义
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
////private:
//	int _year;  // 声明
//	int _month;
//	int _day;
//};
//
//class A2 {
//public:
//	void f2() {}
//};
//
//// 类中什么都没有---空类
//class A3
//{};
//
//int main()
//{
//	// 类对象实例化 -- 开空间
//	// 实例化 -- 用设计图建造一栋栋别墅
//	Date d1;
//	Date d2;
//
//	// 为什么成员变量在对象中，成员函数不在对象中呢？
//	// 每个对象成员变量时不一样的，需要独立存储
//	// 每个对象调用成员函数是一样的，放到共享公共区域(代码段）
//	d1.Init(2023, 2, 2);
//	d1._year++;
//
//	d2.Init(2022, 2, 2);
//	d2._year++;
//
//	cout << sizeof(d1) << endl;
//
//	// 大小是1，这1byte不存储有效数据
//	// 占位，标识对象被实例化定义出来了。
//	A2 aa1;
//	A2 aa2;
//	cout << &aa1 << endl;
//	cout << &aa2 << endl;
//	cout << sizeof(aa1) << endl;
//
//	return 0;
//}


//class Date
//{
//public:
//	// 定义
//	void Init(int year, int month, int day)
//	{
//		/*_year = year;
//		_month = month;
//		_day = day;*/
//		cout << this << endl;
//		this->_year = year;
//		this->_month = month;
//		this->_day = day;
//	}
//
//	void func()
//	{
//		cout << this << endl;
//		cout << "func()" << endl;
//	}
//
////private:
//	int _year;  // 声明
//	int _month;
//	int _day;
//};
//
//// 1、this存在哪里？-- 栈，因为他是隐含形参 / vs下面是通过ecx寄存器
//// 2、空指针问题
//int main()
//{
//	Date d1;
//	Date d2;
//	d1.Init(2022, 2, 2);
//	d2.Init(2023, 2, 2);
//
//	// 编译报错  运行崩溃   正常运行
//	Date* ptr = nullptr;
//	//ptr->Init(2022, 2, 2); // 运行崩溃
//
//	ptr->func();           // 正常运行
//	(*ptr).func();           // 正常运行
//
//	return 0;
//}

class Stack
{
public:
	// 成员函数
	void Init(int n)
	{
		a = (int*)malloc(sizeof(int) * n);
		if (nullptr == a)
		{
			perror("malloc申请空间失败");
			return;
		}

		capacity = n;
		size = 0;
	}

	void Push(int x)
	{
		//...
		a[size++] = x;
	}

	//...

private:
	// 成员变量
	int* a;
	int size;
	int capacity;
};

int main()
{

	return 0;
}