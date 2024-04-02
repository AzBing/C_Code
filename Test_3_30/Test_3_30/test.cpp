#define _CRT_SECURE_NO_WARNINGS 1
#include "Date.h"

void TestDate1()
{
	Date d1(2024, 3, 29);
	d1.Print();
	Date d2(2001, 12, 11);
	d2.Print();
	cout << d1 - d2 << endl;
	cout << d2 - d1 << endl;

}
void TestDate2()
{
	Date d1(2024, 3, 29);
	d1.Print();
	Date d2 = d1.operator+(1000);
	d2.Print();
	Date d3 = d1.operator-(500);
	d3.Print();

}



int main()
{
	TestDate2();

	return 0;
}