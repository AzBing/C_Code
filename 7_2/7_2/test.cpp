#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

// C++����c���ԣ��ṹ�÷����Լ���ʹ��
// ͬʱstructҲ����������
//struct Stack
//{
//	// ��Ա����
//	void Init()
//	{
//		a = nullptr;
//		top = capacity = 0;
//	}
//
//	void Push(int x)
//	{
//		// ...
//	}
//
//	// ��Ա����
//	int* a;
//	int top;
//	int capacity;
//};
//
//void StackInit(struct Stack* ps)
//{
//	// ...
//}
//
//void StackPush(struct Stack* ps, int x)
//{
//
//}

//int main()
//{
//	struct Stack st1;
//	StackInit(&st1);
//	StackPush(&st1, 1);
//	StackPush(&st1, 2);
//
//
//	Stack st2;
//	st2.Init();
//	st2.Push(1);
//	st2.Push(2);
//	st2.Push(3);
//
//	return 0;
//}


//class Stack
//{
//public:
//	// ��Ա����
//	void Init()
//	{
//		a = nullptr;
//		top = capacity = 0;
//	}
//
//	void Push(int x)
//	{
//		if (top == capacity)
//		{
//			size_t newcapacity = capacity == 0 ? 4 : capacity * 2;
//			a = (int*)realloc(a, sizeof(int) * newcapacity);
//			capacity = newcapacity;
//		}
//
//		a[top++] = x;
//	}
//
//	int Top()
//	{
//		return a[top - 1];
//	}
//
//private:
//	// ��Ա����
//	int* a;
//	int top;
//	int capacity;
//};
//
//int main()
//{
//	Stack st;
//	st.Init();
//	st.Push(1);
//	st.Push(2);
//	st.Push(3);
//	st.Push(4);
//
//	//cout << st.a[st.top-1] << endl;
//
//	cout << st.Top() << endl;
//
//
//
//	return 0;
//}

//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;  // year_  mYear
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Stack st;
//	st.Init();
//	st.Push(1);
//	st.Push(2);
//	st.Push(3);
//	st.Push(4);
//
//	//cout << st.a[st.top-1] << endl;
//
//	cout << st.Top() << endl;
//
//	Date d;
//	d.Init(2022, 7, 19);
//
//	return 0;
//}

////////////////////////////////////////////////
// ʵ����

class Date
{
public:
	void Init(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void Print()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}

	//private:
	int _year;   // ����
	int _month;
	int _day;
};

int main()
{
	// ���忪�ռ�
	Date d1;
	d1.Init(2023, 7, 19);
	d1.Print();
	d1._year;

	Date d2;
	d2.Init(2023, 7, 19);
	d2.Print();
	d2._year;

	cout << sizeof(Date) << endl;
	cout << sizeof(d1) << endl;

	return 0;
}