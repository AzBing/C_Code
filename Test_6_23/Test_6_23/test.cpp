#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

template<class T>
class SmartPtr
{
public:
	// RAII
	SmartPtr(T* ptr)
		:_ptr(ptr)
	{}

	~SmartPtr()
	{
		delete[] _ptr;
		cout << "delete[] " << _ptr << endl;
	}
private:
	T* _ptr;
};

double Division(int a, int b)
{
	// ��b == 0ʱ�׳��쳣
	if (b == 0)
	{
		throw invalid_argument("Division by zero condition!");
	}

	return (double)a / (double)b;
}

void Func()
{
	// RAII
	SmartPtr<int> sp1(new int[10]);
	SmartPtr<double> sp2(new double[10]);

	int len, time;
	cin >> len >> time;
	cout << Division(len, time) << endl;
}

int main()
{
	try
	{
		Func();
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}

	return 0;
}
