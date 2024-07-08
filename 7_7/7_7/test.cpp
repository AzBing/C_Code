#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//
//	// d1 < d2  
//	// d1.operator<(d2)
//	bool operator<(const Date& d)
//	{
//		if (_year < d._year)
//		{
//			return true;
//		}
//		else if (_year == d._year && _month < d._month)
//		{
//			return true;
//		}
//		else if (_year == d._year && _month == d._month && _day < d._day)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//
//private:
//	// 内置类型
//	int _year;
//	int _month;
//	int _day;
//};
//
////bool riqixiaoyu(const Date& x1, const Date& x2)
////bool Compare1(const Date& x1, const Date& x2)
//
//// 运算符重载
////bool operator<(const Date& x1, const Date& x2)
////{
////	if (x1._year < x2._year)
////	{
////		return true;
////	}
////	else if (x1._year == x2._year && x1._month < x2._month)
////	{
////		return true;
////	}
////	else if (x1._year == x2._year && x1._month == x2._month && x1._day < x2._day)
////	{
////		return true;
////	}
////	else
////	{
////		return false;
////	}
////}
////
////int main()
////{
////	Date d1(2023, 7, 21);
////	Date d2(2022, 8, 21);
////	//d1 < d2;
////	//cout << riqixiaoyu(d1, d2) << endl;
////	//cout << Compare1(d1, d2) << endl;
////	cout << (d1 < d2) << endl;
////	cout << (operator<(d1, d2)) << endl;
////
////	int i = 1, j = 2;
////	bool ret1 =  i < j;
////
////	bool ret2 = d1 < d2;
////
////
////	return 0;
////}
//
//int main()
//{
//	Date d1(2023, 7, 21);
//	Date d2(2022, 8, 21);
//	cout << (d1 < d2) << endl;
//	cout << (d1.operator<(d2)) << endl;
//
//
//	return 0;
//}

class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void Print()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}

	// d1 < d2  
	// d1.operator<(d2)
	bool operator<(const Date& d)
	{
		if (_year < d._year)
		{
			return true;
		}
		else if (_year == d._year && _month < d._month)
		{
			return true;
		}
		else if (_year == d._year && _month == d._month && _day < d._day)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator==(const Date& d)
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}

	// d1 <= d2
	bool operator<=(const Date& d)
	{
		return *this < d || *this == d;
	}

	bool operator>(const Date& d)
	{
		return !(*this <= d);
	}

	bool operator>=(const Date& d)
	{
		return !(*this < d);
	}

	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}

	int GetMonthDay(int year, int month)
	{
		int monthArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		if (month == 2
			&& ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			return 29;
		}

		return monthArray[month];
	}

	Date& operator+=(int day)
	{
		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			// 月进位
			_day -= GetMonthDay(_year, _month);
			++_month;

			// 月满了
			if (_month == 13)
			{
				++_year;
				_month = 1;
			}
		}

		return *this;
	}

	Date operator+(int day)
	{
		Date tmp(*this);
		tmp += day;
		return tmp;

		//tmp._day += day;
		//while (tmp._day > GetMonthDay(tmp._year, tmp._month))
		//{
		//	// 月进位
		//	tmp._day -= GetMonthDay(tmp._year, tmp._month);
		//	++_month;

		//	// 月满了
		//	if (tmp._month == 13)
		//	{
		//		++tmp._year;
		//		tmp._month = 1;
		//	}
		//}
		//return tmp;
	}

private:
	// 内置类型
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2023, 7, 21);
	Date d2(2022, 8, 21);
	cout << (d1 < d2) << endl;
	// cout << (d1.operator<(d2)) << endl;
	cout << (d1 == d2) << endl;

	/*Date ret = d1 += 50;
	ret.Print();
	d1.Print()*/

	Date ret = d1 + 50;
	ret.Print();
	d1.Print();

	return 0;
}
