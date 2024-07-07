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
//	// 内置类型
//	int _year = 1;
//	int _month;
//	int _day;
//
//	// 自定义类型
//	A _aa;
//};

// 如果A不提供默认构造
// 需要初始化列表才能解决
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
//	// 内置类型
//	int _year = 1;
//	int _month;
//	int _day;
//
//	// 自定义类型
//	A _aa;
//};
//
//// 如果A不提供默认构造
//// 需要初始化列表才能解决
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
//			perror("malloc申请空间失败!!!");
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
//	// 内置类型
//	DataType* _array;
//	int _capacity;
//	int _size;
//
//	// 自定义类型
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

// 拷贝构造 赋值重载(运算符重载)

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
//	// 内置类型
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
//			perror("malloc申请空间失败!!!");
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
//		// 深拷贝
//		_array = (DataType*)malloc(sizeof(DataType) * s._capacity);
//		if (NULL == _array)
//		{
//			perror("malloc申请空间失败!!!");
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
//	// 内置类型
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
//// 期望呢，s要插入一些数据，s的改变，不影响s1
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
//	// 以下两个写法是等价的，都是拷贝构造
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
	// 内置类型
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
			perror("malloc申请空间失败!!!");
			return;
		}

		_capacity = capacity;
		_size = 0;
	}

	// s1(s)
	Stack(const Stack& s)
	{
		cout << "Stack(Stack& s)" << endl;
		// 深拷贝
		_array = (DataType*)malloc(sizeof(DataType) * s._capacity);
		if (NULL == _array)
		{
			perror("malloc申请空间失败!!!");
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
	// 内置类型
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
	// 我们不写，编译默认生成的拷贝构造，跟之前的构造函数特性不一样
	// 1、内置类型， 值拷贝
	// 2、自定义的类型，调用他的拷贝
	// 总结：Date不需要我们实现拷贝构造，默认生成就可以用
	//      Stack需要我们自己实现深拷贝的拷贝构造，默认生成会出问题
	Date d1(2023, 7, 21);
	Date d2 = d1;
    
	/*
	Stack st1;
	Stack st2(st1);
	*/

	// MyQueue对于默认生成的几个函数非常受用，人生赢家
	MyQueue mq1;
	MyQueue mq2 = mq1;
	

	return 0;
}