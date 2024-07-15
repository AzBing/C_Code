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
//	//		perror("malloc申请空间失败!!!");
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
//			perror("malloc申请空间失败!!!");
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
//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{}
//private:
//	int _a;
//};
//
//class Date
//{
//public:
//	// 初始化列表是每个成员定义的地方
//	// 不管你写不写，每个成员都要走初始化列表
//	Date(int year, int month, int day, int& i)
//		: _year(year)
//		, _month(month)
//		,_a(1)
//		,_refi(i)
//	{
//		// 赋值
//		_day = day;
//	}
//
//	void func()
//	{
//		++_refi;
//		++_refi;
//	}
//
//private:
//	int _year;  // 每个成员声明
//	int _month = 1;
//	int _day = 1;
//	// C++11支持给缺省值，这个缺省值给初始化列表
//	// 如果初始化列表没有显示给值，就用这个缺省值
//	// 如果显示给值了，就不用这个缺省值
//
//	// 必须定义时初始化
//	const int _x = 10;
//	int& _refi;
//	A _a;
//};

// 能用初始化列表就用初始化初始化列
// 有些场景还是需要初始化列表和函数体混着用

//int main()
//{
//	//MyQueue mq;
//
//	int n = 0;
//	Date d1(2023, 7, 28, n);
//	d1.func();
//
//	cout << n << endl;
//
//	return 0;
//}

class A
{
public:
	explicit A(int i)
		//A(int i)
		:_a(i)
	{
		cout << "A(int i)" << endl;
	}

	A(const A& aa)
		:_a(aa._a)
	{
		cout << "A(const A& aa)" << endl;
	}

	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};

class B
{
public:
	B(int b1, int b2)
		//explicit B(int b1, int b2)
		:_b1(b1)
		, _b2(b2)
	{
		cout << "B(int b1, int b2)" << endl;
	}
private:
	int _b1;
	int _b2;
};

struct SeqList
{
public:
	void PushBack(const A& x)
	{
		// ... 扩容
		_a[_size++] = x;
	}

	size_t size() const
	{
		return _size;
	}

	// 读
	const A& operator[](size_t i) const
	{
		assert(i < _size);

		return _a[i];
	}

	// 读/写
	A& operator[](size_t i)
	{
		assert(i < _size);

		return _a[i];
	}

private:
	// C++11
	A* _a = (A*)malloc(sizeof(A) * 10);
	size_t _size = 0;
	size_t _capacity = 0;
};

class Solution {
public:
	int Sum_Solution(int n) {
		// ...
		return n;
	}
private:
};

int main()
{
	//A aa1(1);

	//// 单参数构造函数的隐式类型转换
	//// 用2调用A构造函数生成一个临时对象，再用这个对象去拷贝构造aa2
	//// 编译器会再优化，优化用2直接构造 
	//A aa2 = 2;

	//const A& ref1 = 2;

	/*SeqList s;
	A aa3(3);
	s.PushBack(aa3);

	s.PushBack(4);

	double d = 1.1;
	int i = d;
	const int& j = d;*/

	// C++11 支持多参数的隐式类型转换
	B bb1(1, 1);
	B bb2 = { 2, 2 };
	const B& ref2 = { 3,3 };

	// 有名对象 特点：生命周期在当前局部域
	A aa6(6);

	// 匿名对象。特点：生命周期只在这一行
	A(7);


	SeqList s;

	A aa7(7);
	s.PushBack(aa7);

	s.PushBack(A(8));

	Solution sl;
	sl.Sum_Solution(10);

	Solution().Sum_Solution(100);

	//Date d1(2023, 7, 28);
	//cout << d1;
	//cout << Date(2023, 7, 28);

	return 0;
}
