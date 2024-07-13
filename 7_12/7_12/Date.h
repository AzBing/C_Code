#pragma once
#include<iostream>
using namespace std;

class Date
{
	// ��Ԫ����
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);

public:
	int GetMonthDay(int year, int month) const;
	Date(int year = 1, int month = 1, int day = 1);
	void Print() const;

	// �ܽ�һ�£�ֻ���������Լ�const���ڲ����漰�޸ĳ�Ա�Ķ���ֻ������
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

	// ��������
	// ���������
	// ++d1 -> d1.operator++()
	Date& operator++();
	// d1++ -> d1.operator++(0)
	// ��һ��int����������ռλ����ǰ��++���ɺ������ؽ�������
	// ���ʺ���++���ã��������������⴦��
	Date operator++(int);
	Date& operator--();
	Date operator--(int);

	int operator-(const Date& d) const;

	// �ճ��Զ����ɵľͿ���
	// ���뱻ȡ����Ч��ַ
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