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
	int _year = 1;   // ��������ȱʡֵ
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
				cout << capacity << "ԭ������" << endl;
			}
			else
			{
				cout << capacity << "�������" << endl;
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
	// ��Ա����
	int* a;
	int top;
	int capacity;
};

// ����ջʵ��һ������
class MyQueue
{
private:
	Stack _pushst;
	Stack _popst;

	//Date* _ptr;
	//int _size;
};

// ���캯����Ҳ��Ĭ�ϳ�Ա���������ǲ�д�����������Զ�����
// �������ɵ�Ĭ�Ϲ�����ص㣺
// 1�����ǲ�д�Ż����ɣ�����д������һ�����캯���Ͳ���������
// 2���������͵ĳ�Ա���ᴦ��C++11������֧�ָ�ȱʡֵ��
// 3���Զ������͵ĳ�Ա�Żᴦ����ȥ���������Ա��Ĭ�Ϲ��캯��

// �ܽ᣺һ���������Ҫ�����Լ�д���캯����������ʼ����ʽ
// ��Ա����ȫ���Զ������ͣ����Կ��ǲ�д���캯��

//int main()
//{
//	// ���캯����Ҳ��Ĭ�ϳ�Ա���������ǲ�д�����������Զ�����
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
			// ��ƥ��
			if (st.Empty())
				return false;

			char top = st.Top();
			st.Pop();

			// ��ƥ��
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
	// ���壬������
	Date d1;
	Date d2;

	Stack st1;
	Stack st2;

	MyQueue mq;

	cout << isValid("[[]]()()") << endl;
	cout << isValid("[[]]]") << endl;


	return 0;
}
