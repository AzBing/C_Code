#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
using namespace std;

class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1)
	{
		cout << "Date(int year = 1, int month = 1, int day = 1)" << endl;

		_year = year;
		_month = month;
		_day = day;
	}

	/*Date()
	{
		_month = 2;
		_day = 2;
	}*/

	void Print()
	{
		//cout << this << endl;

		cout << _year << "/" << _month << "/" << _day << endl;
	}

	~Date()
	{
		cout << "~Date()" << endl;
	}

private:
	int _year = 1;   // 声明给的缺省值
	int _month = 1;
	int _day = 1;
};

class Stack
{
public:
	Stack(size_t n = 4)
	{
		cout << "Stack(size_t n = 4)" << endl;

		if (n == 0)
		{
			a = nullptr;
			top = capacity = 0;
		}
		else
		{
			a = (int*)malloc(sizeof(int) * n);
			if (a == nullptr)
			{
				perror("realloc fail");
				exit(-1);
			}

			top = 0;
			capacity = n;
		}
	}

	~Stack()
	{
		cout << "~Stack()" << endl;
		free(a);
		a = nullptr;
		top = capacity = 0;
	}

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

// 两个栈实现一个队列
class MyQueue
{
private:
	Stack _pushst;
	Stack _popst;

	//Date* _ptr;
	//int _size;
};

// 构造函数，也是默认成员函数，我们不写，编译器会自动生成
// 编译生成的默认构造的特点：
// 1、我们不写才会生成，我们写了任意一个构造函数就不会生成了
// 2、内置类型的成员不会处理（C++11，声明支持给缺省值）
// 3、自定义类型的成员才会处理，回去调用这个成员的默认构造函数

// 总结：一般情况都需要我们自己写构造函数，决定初始化方式
// 成员变量全是自定义类型，可以考虑不写构造函数

//int main()
//{
//	// 构造函数，也是默认成员函数，我们不写，编译器会自动生成
//	Date d1;
//	d1.Print();
//
//	// MyQueue mq;
//
//	return 0;
//}


bool isValid(const char* s) {
	Stack st;
	while (*s)
	{
		if (*s == '[' || *s == '(' || *s == '{')
		{
			st.Push(*s);
			++s;
		}
		else
		{
			// 不匹配
			if (st.Empty())
				return false;

			char top = st.Top();
			st.Pop();

			// 不匹配
			if ((*s == ']' && top != '[')
				|| (*s == ')' && top != '(')
				|| (*s == '}' && top == '{'))
			{
				return false;
			}

			++s;
		}
	}

	return st.Empty();
}

int main()
{
	// 后定义，先析构
	Date d1;
	Date d2;

	Stack st1;
	Stack st2;

	MyQueue mq;

	cout << isValid("[[]]()()") << endl;
	cout << isValid("[[]]]") << endl;


	return 0;
}
