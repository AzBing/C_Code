#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

#include<assert.h>


//typedef int DataType;
//class Stack
//{
//public:
//	//Stack(size_t capacity)
//	//{
//	//	cout << "Stack()" << endl;
//
//	//	_array = (DataType*)malloc(sizeof(DataType) * capacity);
//	//	if (NULL == _array)
//	//	{
//	//		perror("malloc����ռ�ʧ��!!!");
//	//		return;
//	//	}
//
//	//	_capacity = capacity;
//	//	_size = 0;
//	//}
//
//	Stack(size_t capacity)
//		:_array((DataType*)malloc(sizeof(DataType) * capacity))
//		,_size(0)
//		,_capacity(capacity)
//	{
//		cout << "Stack()" << endl;
//		if (NULL == _array)
//		{
//			perror("malloc����ռ�ʧ��!!!");
//			return;
//		}
//
//		memset(_array, 0, sizeof(DataType) * _capacity);
//	}
//
//	// s1(s)
//	Stack(const Stack& s)
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
//	// ��������
//	DataType* _array;
//	int _capacity;
//	int _size;
//};
//
//class MyQueue
//{
//public:
//	MyQueue(int capacity = 10)
//		:_st1(capacity)
//		,_st2(capacity)
//	{}
//
//private:
//	Stack _st1;
//	Stack _st2;
//};
//
class A
{
public:
	A(int a = 0)
		:_a(a)
	{}
private:
	int _a;
};

class Date
{
public:
	// ��ʼ���б���ÿ����Ա����ĵط�
	// ������д��д��ÿ����Ա��Ҫ�߳�ʼ���б�
	Date(int year, int month, int day, int& i)
		: _year(year)
		, _month(month)
		,_a(1)
		,_refi(i)
	{
		// ��ֵ
		_day = day;
	}

	void func()
	{
		++_refi;
		++_refi;
	}

private:
	int _year;  // ÿ����Ա����
	int _month = 1;
	int _day = 1;
	// C++11֧�ָ�ȱʡֵ�����ȱʡֵ����ʼ���б�
	// �����ʼ���б�û����ʾ��ֵ���������ȱʡֵ
	// �����ʾ��ֵ�ˣ��Ͳ������ȱʡֵ

	// ���붨��ʱ��ʼ��
	const int _x = 10;
	int& _refi;
	A _a;
};

// ���ó�ʼ���б���ó�ʼ����ʼ����
// ��Щ����������Ҫ��ʼ���б�ͺ����������

int main()
{
	//MyQueue mq;

	int n = 0;
	Date d1(2023, 7, 28, n);
	d1.func();

	cout << n << endl;

	return 0;
}