#define _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"

int Date::GetMonthDay(int year, int month) const
{
	const static int monthArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (month == 2
		&& ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
	{
		return 29;
	}

	return monthArray[month];
}


Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;

	// 检查日期是否合法
	if (month < 1 || month > 12
		|| day < 1 || day > GetMonthDay(year, month))
	{
		cout << "非法日期" << endl;
		// exit(-1);
	}
}

//void Date::Print(const Date* this) 
void Date::Print() const
{
	cout << _year << "年" << _month << "月" << _day << "日" << endl;
}

//  
// d1 = d3
// d1 = d1
// Date& operator=(const Date& d);
//Date& Date::operator=(const Date& d)
//{
//	if (this != &d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	return *this;
//}

// Date* this
bool Date::operator<(const Date& d) const
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

bool Date::operator==(const Date& d) const
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

// d1 <= d2
// const Date* this
bool Date::operator<=(const Date& d) const
{
	return *this < d || *this == d;
}

bool Date::operator>(const Date& d) const
{
	return !(*this <= d);
}

bool Date::operator>=(const Date& d) const
{
	return !(*this < d);
}

bool Date::operator!=(const Date& d) const
{
	return !(*this == d);
}

// 2023 7 27
Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		return *this -= (-day);
	}

	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		++_month;

		if (_month == 13)
		{
			++_year;
			_month = 1;
		}
	}

	return *this;
}

// d1 + 100
Date Date::operator+(int day) const
{
	Date tmp(*this);

	tmp += day;

	return tmp;
}

// d1 += 100
//Date& Date::operator+=(int day)
//{
//	//Date ret = *this + day;
//	//*this = ret;
//	*this = *this + day;
//
//	return *this;
//}
//
//// d1 + 100
//Date Date::operator+(int day)
//{
//	// 等价的，都是拷贝构造
//	//Date tmp(*this);
//	Date tmp = *this;
//
//	tmp._day += day;
//	while (tmp._day > GetMonthDay(tmp._year, tmp._month))
//	{
//		// 月进位
//		tmp._day -= GetMonthDay(tmp._year, tmp._month);
//		++_month;
//
//		// 月满了
//		if (tmp._month == 13)
//		{
//			++tmp._year;
//			tmp._month = 1;
//		}
//	}
//
//	return tmp;
//}

Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += (-day);
	}

	_day -= day;

	while (_day <= 0)
	{
		--_month;
		if (_month == 0)
		{
			--_year;
			_month = 12;
		}

		_day += GetMonthDay(_year, _month);
	}

	return *this;
}

Date Date::operator-(int day) const
{
	Date tmp(*this);

	tmp -= day;

	return tmp;
}


Date& Date::operator++()
{
	*this += 1;
	return *this;
}

Date Date::operator++(int)
{
	Date tmp(*this);

	*this += 1;

	return tmp;
}


Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

Date Date::operator--(int)
{
	Date tmp(*this);

	*this -= 1;

	return tmp;
}

// d1 - d2
int Date::operator-(const Date& d) const
{
	Date max = *this;
	Date min = d;
	int flag = 1;

	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}

	int n = 0;
	while (min != max)
	{
		++min;
		++n;
	}

	return n * flag;
}

//void Date::operator<<(ostream& out)
//{
//	out << _year << "/" << _month << "/" << _day << endl;
//}

ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "/" << d._month << "/" << d._day << endl;

	return out;
}

istream& operator>>(istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}