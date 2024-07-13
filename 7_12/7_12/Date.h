#pragma once
#include<iostream>
using namespace std;

class Date
{
	// 友元声明
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);

public:
	int GetMonthDay(int year, int month) const;
	Date(int year = 1, int month = 1, int day = 1);
	void Print() const;

	// 总结一下：只读函数可以加const，内部不涉及修改成员的都是只读函数
	bool operator<(const Date& d) const;
	bool operator==(const Date& d) const;
	bool operator<=(const Date& d) const;
	bool operator>(const Date& d) const;
	bool operator>=(const Date& d) const;
	bool operator!=(const Date& d) const;

	Date& operator+=(int day);
	Date operator+(int day) const;
	Date& operator-=(int day);
	Date operator-(int day) const;

	// 函数重载
	// 运算符重载
	// ++d1 -> d1.operator++()
	Date& operator++();
	// d1++ -> d1.operator++(0)
	// 加一个int参数，进行占位，跟前置++构成函数重载进行区分
	// 本质后置++调用，编译器进行特殊处理
	Date operator++(int);
	Date& operator--();
	Date operator--(int);

	int operator-(const Date& d) const;

	// 日常自动生成的就可以
	// 不想被取到有效地址
	//Date* operator&()
	//{
	//	// return (Date*)0x01202;
	//	return nullptr;
	//}

	//const Date* operator&() const
	//{
	//	return this;
	//}

	//void operator<<(ostream& out);
private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& out, const Date& d);
istream& operator>>(istream& in, Date& d);