#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<list>
#include<vector>
#include<string>
using namespace std;

#include"list.h"
#include"vector.h"

//int main()
//{
//	lis::list<int> lt;
//	lt.push_back(1);
//	lt.push_back(2);
//	lt.push_back(3);
//	lt.push_back(4);
//
//	lis::list<int>::iterator it = lt.begin();
//	while (it != lt.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	lis::list<int>::reverse_iterator rit = lt.rbegin();
//	while (rit != lt.rend())
//	{
//		//*rit += 1;
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//
//	return 0;
//}

//void func(const vet::vector<int>& lt)
//{
//	vet::vector<int>::const_reverse_iterator rit = lt.rbegin();
//	while (rit != lt.rend())
//	{
//		//*rit += 1;
//
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//}
//
//int main()
//{
//	vet::vector<int> lt;
//	lt.push_back(1);
//	lt.push_back(2);
//	lt.push_back(3);
//	lt.push_back(4);
//	lt.push_back(5);
//	lt.push_back(6);
//
//	vet::vector<int>::iterator it = lt.begin();
//	while (it != lt.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	vet::vector<int>::reverse_iterator rit = lt.rbegin();
//	while (rit != lt.rend())
//	{
//		//*rit += 1;
//
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//
//	func(lt);
//	return 0;
//}

template<class T1, class T2>
class Data
{
public:
	Data() { cout << "Data<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};

template<>
class Data<int, int>
{
public:
	Data() { cout << "Data<int, int>" << endl; }
private:
	int _d1;
	char _d2;
};

template <class T1>
class Data<T1, int>
{
public:
	Data() { cout << "Data<T1, int>" << endl; }
private:
	T1 _d1;
	int _d2;
};

template <typename T1, typename T2>
class Data <T1*, T2*>
{
public:
	Data() { cout << "Data<T1*, T2*>" << endl; }

private:
	T1 _d1;
	T2 _d2;
};

template <typename T1, typename T2>
class Data <T1&, T2&>
{
public:
	Data()
	{
		cout << "Data<T1&, T2&>" << endl;
	}
};

//int main()
//{
//	Data<int, int> d1;
//	Data<double, int> d2;
//	Data<double*, int*> d3;
//	Data<double&, int&> d4;
//
//	return 0;
//}

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	bool operator<(const Date& d) const
	{
		return (_year < d._year) ||
			(_year == d._year && _month < d._month) ||
			(_year == d._year && _month == d._month && _day < d._day);
	}

	bool operator>(const Date& d) const
	{
		return (_year > d._year) ||
			(_year == d._year && _month > d._month) ||
			(_year == d._year && _month == d._month && _day > d._day);
	}

	friend ostream& operator<<(ostream& _cout, const Date& d);
private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}

// 函数模板
//template<class T>
//bool Less(T left, T right)
//{
//	return left < right;
//}
//
//// 特化一下
//template<>
//bool Less<Date*>(Date* left, Date* right)
//{
//	return *left < *right;
//}
//
//int main()
//{
//	Date* d1 = new Date(2023, 10, 8);
//	Date* d2 = new Date(2023, 10, 9);
//	cout << Less(d1, d2) << endl;
//
//	return 0;
//}

//template<class T>
//bool Less(const T& left, const T& right)
//{
//	return left < right;
//}
//
//// 特化一下
//template<>
//bool Less<Date*>(Date* const & left,  Date* const & right)
//{
//	return *left < *right;
//}
//
//int main()
//{
//	Date* d1 = new Date(2023, 10, 8);
//	Date* d2 = new Date(2023, 10, 9);
//	cout << Less(d1, d2) << endl;
//
//	//const int* p1;
//	//int* const p2;
//
//
//	return 0;
//}

// 类模板用特化
// 函数模板可以不用特化

template<class T>
bool Less(const T& left, const T& right)
{
	return left < right;
}

bool Less(Date* left, Date* right)
{
	return *left < *right;
}

int main()
{
	Date* d1 = new Date(2023, 10, 8);
	Date* d2 = new Date(2023, 10, 9);
	cout << Less(d1, d2) << endl;
	cout << Less(1, 2) << endl;

	//const int* p1;
	//int* const p2;

	return 0;
}
