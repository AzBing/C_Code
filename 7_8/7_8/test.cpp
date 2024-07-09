#define _CRT_SECURE_NO_WARNINGS 1
#include "Date.h"

void TestDate1()
{
	Date d1(2023, 7, 23);
	Date d2;

	d1.Print();
	d2.Print();

	Date d3(2010, 2, 29);
	d3.Print();

	Date d4(2023, 13, 29);
	d4.Print();
}

void TestDate2()
{
	Date d1(2023, 8, 6);
	// 拷贝构造，一个已经存在的对象去初始化另一个要创建对象
	Date d2(d1);

	d1.Print();
	d2.Print();

	Date d3(2023, 8, 13);
	// 赋值，两个已经存在对象进行拷贝
	//d1 = d3;  // d1.operator=(d3)
	d1 = d2 = d3;
	d1.Print();
	d2.Print();
	d3.Print();

	d1 = d1;

	int i, j;
	i = j = 10;
	cout << (j = 10) << endl;
}

void TestDate3()
{
	Date d1(2023, 7, 27);
	d1 += 20000;
	d1.Print();

	Date d2(2023, 7, 27);
	//Date ret = d2;
	//Date ret(d2 + 20000);
	// 拷贝构造
	//Date ret = d2 + 20000;

	Date ret;
	// 赋值
	ret = d2 + 20000;

	ret.Print();
}

void TestDate4()
{
	Date d1(2023, 7, 27);
	d1 -= 20000;
	d1.Print();

	Date d2(2023, 7, 27);
	d2 += -200;
	d2.Print();

	Date d3(2023, 7, 27);
	d3 -= -200;
	d3.Print();
}

void TestDate5()
{
	Date d1(2023, 7, 27);
	Date ret1 = d1++;
	//Date ret1 = d1.operator++(0);
	ret1.Print();
	d1.Print();

	Date ret2 = ++d1;
	//Date ret2 = d1.operator++();
	ret2.Print();
	d1.Print();
}

void TestDate6()
{
	Date d1(2023, 7, 27);
	Date d2(2003, 1, 1);

	cout << d1 - d2 << endl;
}

void TestDate7()
{
	const Date d1(2023, 7, 27);
	// d1.Print(&d1);
	d1.Print();

	Date d2(2023, 7, 27);
	// d2.Print(&d2);
	d2.Print();
}

int main()
{
	TestDate7();

	return 0;
}

//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 3)
//	{
//		cout << "Stack()" << endl;
//
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
//	Stack(const Stack& s)
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
//	Stack& operator=(const Stack& st)
//	{
//		if (this != &st)
//		{
//			// ...
//		}
//
//		return *this;
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

//class MyQueue
//{
//	// 构造析构
//	// 拷贝构造和赋值重写
//	// 都不需要写，默认生成的就可以用
//	Stack _st1;
//	Stack _st2;
//};

//void Func1(const Stack& st)
//{
//
//}
//
//Stack& Func2()
//{
//	Stack st;
//	return st;
//}
//
//int main()
//{
//	Stack st1;
//	Func1(st1);
//
//	Stack st2 = Func2();
//
//	return 0;
//}