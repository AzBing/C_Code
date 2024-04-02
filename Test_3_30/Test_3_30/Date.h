#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

class Date
{
public:
	// ��ȡĳ��ĳ�µ�����
	int GetMonthDay(int year, int month);

	// ȫȱʡ�Ĺ��캯��
	Date(int year, int month, int day);

	// �������캯��
	// d2(d1)
	Date(const Date& d);

	// ��ֵ���������
	// d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d);

	// ��������
	//~Date();

	void Print();

	// ����+=����
	Date& operator+=(int day);

	// ����+����
	Date operator+(int day);

	// ����-����
	Date operator-(int day);

	// ����-=����
	Date& operator-=(int day);

	// ����-���� ��������
	int operator-(const Date& d);

	// ǰ��++
	Date& operator++();

	// ����++
	Date operator++(int);

	// ǰ��--
	Date& operator--();

	// ����--
	Date operator--(int);

	bool operator>(const Date& d);
	bool operator==(const Date& d);
	bool operator >= (const Date& d);
	bool operator < (const Date& d);
	bool operator <= (const Date& d);
	bool operator != (const Date& d);

	

private:
	int _year;
	int _month;
	int _day;
};