#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//class Date
//{
//public:
//	Date(int year, int month, int day)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//// �������Ĺ��캯��
//class A
//{
//public:
//	explicit A(int a)
//		:_a1(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//
//	//explicit A(int a1, int a2)
//	A(int a1, int a2)
//		:_a1(a1)
//		, _a2(a2)
//	{}
//
//	A(const A& aa)
//		:_a1(aa._a1)
//	{
//		cout << "A(const A& aa)" << endl;
//	}
//
//private:
//	int _a2;
//	int _a1;
//};

//int main()
//{
//	// ���������캯�� C++98
//	A aa1(1);  // ���캯��
//	//A aa2 = 1; // ��ʽ����ת��   ����+����+�Ż�->����
//	//const A& ref = 10;
//
//
//	// ��������캯�� C++11
//	A aa2(1, 1);
//	A aa3 = { 2, 2 };
//	const A &ref = { 2, 2 };
//
//	int i = 1;
//	double d = i; // ��ʽ����ת��
//
//	return 0;
//}
//using std::cout;
//using std::endl;
//
//// ʵ��һ���࣬��������д������˶��ٸ������
//int count = 0;
//
//class A
//{
//public:
//	A(int a = 0)
//	{
//		++count;
//	}
//
//	A(const A& aa)
//	{
//		++count;
//	}
//};
//
//void func(A a)
//{}
//
//int main()
//{
//	A aa1;
//	A aa2(aa1);
//	func(aa1);
//	A aa3 = 1;
//
//	count++;
//	count++;
//	count++;
//
//	cout << count << endl;
//
//	return 0;
//}