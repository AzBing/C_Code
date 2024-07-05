#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
using namespace std;


//class Date
//{
//public:
//	// this在实参和形参位置不能显示写
//	// 但是在类里面可以显示的用
//	void Init(int year, int month, int day)
//	{
//		cout << this << endl;
//
//		//this->_year = year;
//		//this->_month = month;
//		//this->_day = day;
//
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << this << endl;
//
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//
//private:
//	int _year;   // 声明
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;
//	d1.Init(2023, 7, 20);
//	d1.Print();
//
//	Date d2;
//	d2.Init(2023, 7, 21);
//	d2.Print();
//
//	return 0;
//}

//1.下面程序编译运行结果是？  A、编译报错  B、运行崩溃  C、正常运行
//class A
//{
//public:
//	void Print()
//	{
//		//cout << _a << endl;
//		cout << "Print()" << endl;
//	}
//// private:
//	int _a;
//};

//int main()
//{
//	A* p = nullptr;
//	(*p).Print();
//	p->Print();
//
//
//	//p->_a = 1;
//
//	return 0;
//}

class A
{
public:
	void Print()
	{
		//this++;
		//cout << _a << endl;
		cout << "Print()" << endl;
	}
	// private:
	int _a;
};


class Date
{
public:
	/*Date()
	{
		cout << "Date()" << endl;
		_year = 1;
		_month = 1;
		_day = 1;
	}*/
	//Date(int year, int month, int day)
	//{
	//	_year = year;
	//	_month = month;
	//	_day = day;
	//}

	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	/*void Init(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}*/

	void Print()
	{
		//cout << this << endl;

		cout << _year << "/" << _month << "/" << _day << endl;
	}

private:
	int _year;   // 声明
	int _month;
	int _day;
};

class Stack
{
public:
	/*Stack()
	{
		a = nullptr;
		top = capacity = 0;
	}*/

	Stack(size_t n = 4)
	{
		if (n == 0)
		{
			a = nullptr;
			top = capacity = 0;
		}
		else
		{
			a = (int*)malloc(sizeof(int) * n);
			if(a == nullptr)
			{
				perror("realloc fail");
				exit(-1);
			}

			top = 0;
			capacity = n;
		}
	}

	// 成员函数
	//void Init()
	//{
	//	a = nullptr;
	//	top = capacity = 0;
	//}

	void Push(int x)
	{
		if (top == capacity)
		{
			size_t newcapacity = capacity == 0 ? 4 : capacity * 2;
			int* tmp = (int*)realloc(a, sizeof(int) * newcapacity);
			if (tmp == nullptr)
			{
				perror("realloc fail");
				exit(-1);
			}
			if (tmp == a)
			{
				cout << capacity << "原地扩容" << endl;
			}
			else
			{
				cout << capacity << "异地扩容" << endl;
			}

			a = tmp;
			capacity = newcapacity;
		}

		a[top++] = x;
	}

	int Top()
	{
		return a[top - 1];
	}

	void Pop()
	{
		assert(top > 0);
		--top;
	}

	void Destroy()
	{
		free(a);
		a = nullptr;
		top = capacity = 0;
	}

	bool Empty()
	{
		return top == 0;
	}
private:
	// 成员变量
	int* a;
	int top;
	int capacity;
};

int main()
{
	Stack st1;
	st1.Push(1);
	st1.Push(2);
	st1.Push(3);
	st1.Push(4);
	
	while (!st1.Empty())
	{
		cout << st1.Top() << " ";
		st1.Pop();
	}
	cout << endl;

	st1.Destroy();

	//Stack st2(1000);
	Stack st2;
	for (size_t i = 0; i < 1000; i++)
	{
		st2.Push(i);
	}

	while (!st2.Empty())
	{
		cout << st2.Top() << " ";
		st2.Pop();
	}
	cout << endl;

	st2.Destroy();


	// 不能这么写
	/*Date d1();
	d1.Print();*/

	Date d1;
	d1.Print();

	Date d2(2023, 7, 20);
	d2.Print();

	Date d3(2023);
	d3.Print();

	Date d4(2023, 7);
	d4.Print();

	return 0;
}