#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<windows.h>
using namespace std;

class A
{
public:
	A()
	{
		cout << "A()" << endl;
	}

	~A()
	{
		cout << "~A()" << endl;
	}
};

//double Division(int len, int time)
//{
//	if (time == 0)
//	{
//		throw "��0����";
//	}
//	else
//	{
//		return (double)len / (double)time;
//	}
//}
//
//void Func()
//{
//	A aa;
//
//	try {
//		int len, time;
//		cin >> len >> time;
//		cout << Division(len, time) << endl;
//	}
//	catch (const char* s)
//	{
//		cout << s << endl;
//	}
//
//	cout << "xxxxxxxxxxxx" << endl;
//}
//
//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (const char* str)
//	{
//		cout << str << endl;
//	}
//
//	return 0;
//}

//double Division(int len, int time)
//{
//	if (time == 0)
//	{
//		throw "��0����";
//	}
//	else
//	{
//		return (double)len / (double)time;
//	}
//}
//
//void Func()
//{
//	A aa;
//
//	try {
//		int len, time;
//		cin >> len >> time;
//		cout << Division(len, time) << endl;
//	}
//	catch (const char s)
//	{
//		cout << s << endl;
//	}
//
//	cout << "xxxxxxxxxxxx" << endl;
//}
//
//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (const char* str)
//	{
//		cout << str << endl;
//	}
//
//	return 0;
//}

double Division(int len, int time)
{
	if (time == 0)
	{
		string s("��0����");
		throw s;
	}
	else
	{
		return (double)len / (double)time;
	}
}

void f1()
{
	throw 1;
}

void Func()
{
	A aa;

	try {
		int len, time;
		cin >> len >> time;
		cout << Division(len, time) << endl;
	}
	catch (const char s)
	{
		cout << s << endl;
	}

	f1();
	cout << "xxxxxxxxxxxx" << endl;
}

int main()
{

	try
	{
		Func();
	}
	catch (const string& s)
	{
		cout << s << endl;
	}
	catch (...)  // �ߵ�����˵������û�а��淶(Լ��)���쳣
	{
		cout << "δ֪�쳣" << endl;
	}


	return 0;
}
