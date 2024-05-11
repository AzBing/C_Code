#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

template<class T>
T Add(const T& left, const T& right);

void func();


template<class T>
class Stack
{
public:
	void Push(const T& x);
	void Pop();
private:
	T* _a = nullptr;
	int _top = 0;
	int _capacity = 0;
};

template<class T>
T Add(const T& left, const T& right)
{
	cout << "T Add(const T& left, const T& right)" << endl;
	return left + right;
}

void func()
{
	cout << "void func()" << endl;
}

template<class T>
void Stack<T>::Push(const T& x)
{
	cout << "void Stack<T>::Push(const T& x)" << endl;
}

template<class T>
void Stack<T>::Pop()
{
	cout << "void Pop()" << endl;
}