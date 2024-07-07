#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class A
{
public:
	A(int a = 0)
	{
		cout << "A(int a)" << endl;
		_a = a;
	}

	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};

//class Date
//{
//public:
//	/*Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}*/
//
//private:
//	// ��������
//	int _year = 1;
//	int _month;
//	int _day;
//
//	// �Զ�������
//	A _aa;
//};

// ���A���ṩĬ�Ϲ���
// ��Ҫ��ʼ���б���ܽ��
//int main()
//{
//	Date d1;
//	//Date d2(2022, 7, 21);
//
//	return 0;
//}
//class A
//{
//public:
//	A(int a = 0)
//	{
//		cout << "A(int a)" << endl;
//		_a = a;
//	}
//private:
//	int _a;
//};
//
//class Date
//{
//public:
//	/*Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}*/
//
//private:
//	// ��������
//	int _year = 1;
//	int _month;
//	int _day;
//
//	// �Զ�������
//	A _aa;
//};
//
//// ���A���ṩĬ�Ϲ���
//// ��Ҫ��ʼ���б���ܽ��
//int main()
//{
//	Date d1;
//	//Date d2(2022, 7, 21);
//
//	return 0;
//}

//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 3)
//	{
//		_array = (DataType*)malloc(sizeof(DataType) * capacity);
//		if (NULL == _array)
//		{
//			perror("malloc����ռ�ʧ��!!!");
//			return;
//		}
//
//		_capacity = capacity;
//		_size = 0;
//	}
//
//	void Push(DataType data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//
//	/*~Stack()
//	{
//		cout << "~Stack()" << endl;
//
//		free(_array);
//		_array = nullptr;
//		_size = _capacity = 0;
//	}*/
//private:
//	// ��������
//	DataType* _array;
//	int _capacity;
//	int _size;
//
//	// �Զ�������
//	A _aa;
//};
//
//void TestStack()
//{
//	Stack s;
//	s.Push(1);
//	s.Push(2);
//}
//
//int main()
//{
//	TestStack();
//
//	return 0;
//}

// �������� ��ֵ����(���������)

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
//	// Date d2(d1);
//	Date(Date& d)
//	{
//		cout << "Date(Date& d)" << endl;
//
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//	
//private:
//	// ��������
//	int _year;
//	int _month;
//	int _day;
//};
//
//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 3)
//	{
//		_array = (DataType*)malloc(sizeof(DataType) * capacity);
//		if (NULL == _array)
//		{
//			perror("malloc����ռ�ʧ��!!!");
//			return;
//		}
//
//		_capacity = capacity;
//		_size = 0;
//	}
//
//	// s1(s)
//	Stack(Stack& s)
//	{
//		cout << "Stack(Stack& s)" << endl;
//		// ���
//		_array = (DataType*)malloc(sizeof(DataType) * s._capacity);
//		if (NULL == _array)
//		{
//			perror("malloc����ռ�ʧ��!!!");
//			return;
//		}
//
//		memcpy(_array, s._array, sizeof(DataType) * s._size);
//		_size = s._size;
//		_capacity = s._capacity;
//	}
//
//	void Push(DataType data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//
//		free(_array);
//		_array = nullptr;
//		_size = _capacity = 0;
//	}
//private:
//	// ��������
//	DataType* _array;
//	int _capacity;
//	int _size;
//};
//
//void func1(Date d)
//{
//	d.Print();
//}
//
////void func2(Stack& s)
//
//// �����أ�sҪ����һЩ���ݣ�s�ĸı䣬��Ӱ��s1
//void func2(Stack s)
//{
//	s.Push(1);
//	s.Push(2);
//}
//
//int main()
//{
//	Date d1(2023, 7, 21);
//	func1(d1);
//
//	Stack s1;
//	func2(s1);
//
//	Stack s2(s1);
//
//	// ��������д���ǵȼ۵ģ����ǿ�������
//	Date d2(d1);
//	Date d3 = d1;
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

	// Date d2(d1);
	Date(const Date& d)
	{
		cout << "Date(Date& d)" << endl;

		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	void Print()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}

private:
	// ��������
	int _year;
	int _month;
	int _day;
};

typedef int DataType;
class Stack
{
public:
	Stack(size_t capacity = 3)
	{
		cout << "Stack()" << endl;

		_array = (DataType*)malloc(sizeof(DataType) * capacity);
		if (NULL == _array)
		{
			perror("malloc����ռ�ʧ��!!!");
			return;
		}

		_capacity = capacity;
		_size = 0;
	}

	// s1(s)
	Stack(const Stack& s)
	{
		cout << "Stack(Stack& s)" << endl;
		// ���
		_array = (DataType*)malloc(sizeof(DataType) * s._capacity);
		if (NULL == _array)
		{
			perror("malloc����ռ�ʧ��!!!");
			return;
		}

		memcpy(_array, s._array, sizeof(DataType) * s._size);
		_size = s._size;
		_capacity = s._capacity;
	}

	void Push(DataType data)
	{
		// CheckCapacity();
		_array[_size] = data;
		_size++;
	}

	~Stack()
	{
		cout << "~Stack()" << endl;

		free(_array);
		_array = nullptr;
		_size = _capacity = 0;
	}
private:
	// ��������
	DataType* _array;
	int _capacity;
	int _size;
};

class MyQueue
{
private:
	Stack _pushst;
	Stack _popst;
};

int main()
{
	// ���ǲ�д������Ĭ�����ɵĿ������죬��֮ǰ�Ĺ��캯�����Բ�һ��
	// 1���������ͣ� ֵ����
	// 2���Զ�������ͣ��������Ŀ���
	// �ܽ᣺Date����Ҫ����ʵ�ֿ������죬Ĭ�����ɾͿ�����
	//      Stack��Ҫ�����Լ�ʵ������Ŀ������죬Ĭ�����ɻ������
	Date d1(2023, 7, 21);
	Date d2 = d1;
    
	/*
	Stack st1;
	Stack st2(st1);
	*/

	// MyQueue����Ĭ�����ɵļ��������ǳ����ã�����Ӯ��
	MyQueue mq1;
	MyQueue mq2 = mq1;
	

	return 0;
}