#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using namespace std;

class Date
{
public:
	void Init(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void Print()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}

//private:
	int _year;   // 声明
	int _month;
	int _day;
};

class A1 {
public:
	void f1() {}
private:
	char _ch;
	int _a;
};

// 类中仅有成员函数
class A2 {
public:
	void f2() {}
};

// 类中什么都没有---空类
class A3
{};

//int main()
//{
//	cout << sizeof(A1) << endl;
//
//	// 分配1byte，不存储数据，只是占位，表示对象存在过
//	cout << sizeof(A2) << endl;
//	cout << sizeof(A3) << endl;
//
//	A2 aa2;
//	A2 aaa2;
//	cout << &aa2 << endl;
//	cout << &aaa2 << endl;
//
//	cout << sizeof(Date) << endl;
//	Date d1;
//	Date d2;
//
//	d1.Print();
//	d2.Print();
//
//	d1._year = 1;
//	d2._year = 2;
//
//	return 0;
//}
//int main()
//{
//	cout << sizeof(A1) << endl;
//
//	 分配1byte，不存储数据，只是占位，表示对象存在过
//	cout << sizeof(A2) << endl;
//	cout << sizeof(A3) << endl;
//
//	A2 aa2;
//	A2 aaa2;
//	cout << &aa2 << endl;
//	cout << &aaa2 << endl;
//
//	cout << sizeof(Date) << endl;
//	Date d1;
//	Date d2;
//
//	d1.Print();
//	d2.Print();
//
//	d1._year = 1;
//	d2._year = 2;
//
//	return 0;
//}int main()
//{
//	cout << sizeof(A1) << endl;
//
//	 分配1byte，不存储数据，只是占位，表示对象存在过
//	cout << sizeof(A2) << endl;
//	cout << sizeof(A3) << endl;
//
//	A2 aa2;
//	A2 aaa2;
//	cout << &aa2 << endl;
//	cout << &aaa2 << endl;
//
//	cout << sizeof(Date) << endl;
//	Date d1;
//	Date d2;
//
//	d1.Print();
//	d2.Print();
//
//	d1._year = 1;
//	d2._year = 2;
//
//	return 0;
//}
//int main()
//{
//	cout << sizeof(A1) << endl;
//
//	// 分配1byte，不存储数据，只是占位，表示对象存在过
//	cout << sizeof(A2) << endl;
//	cout << sizeof(A3) << endl;
//
//	A2 aa2;
//	A2 aaa2;
//	cout << &aa2 << endl;
//	cout << &aaa2 << endl;
//
//	cout << sizeof(Date) << endl;
//	Date d1;
//	Date d2;
//
//	d1.Print();
//	d2.Print();
//
//	d1._year = 1;
//	d2._year = 2;
//
//	return 0;
//}
int main()
{
	cout << sizeof(A1) << endl;

	// 分配1byte，不存储数据，只是占位，表示对象存在过
	cout << sizeof(A2) << endl;
	cout << sizeof(A3) << endl;

	A2 aa2;
	A2 aaa2;
	cout << &aa2 << endl;
	cout << &aaa2 << endl;

	cout << sizeof(Date) << endl;
	Date d1;
	Date d2;

	d1.Print();
	d2.Print();

	d1._year = 1;
	d2._year = 2;

	return 0;
}


