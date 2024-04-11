#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

// 泛型编程 -- 模板
//template<class T>
//template<typename T>
//void Swap(T& x, T& y)
//{
//	T tmp = x;
//	x = y;
//	y = tmp;
//}
//
//template<class X, class Y>
//void Func()
//{
//
//}
//
//int main()
//{
//	int a = 1, b = 2;
//	//Swap(a, b);
//	swap(a, b);
//
//	double c = 1.1, d = 2.22;
//	//Swap(a, b);
//	swap(c, d);
//
//	return 0;
//}

//template<class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.11, d2 = 20.22;
//	// 实参传递给形参，自动推演模板类型
//	cout << Add(a1, a2) << endl;
//	cout << Add(d1, d2) << endl;
//	cout << Add(a1, (int)d1) << endl;
//	cout << Add((double)a1, d1) << endl;
//
//	// 显示实例化
//	cout << Add<int>(a1, d1) << endl;
//	cout << Add<double>(a1, d1) << endl;
//
//	return 0;
//}

// 专门处理int的加法函数
int Add(int left, int right)
{
	return left + right;
}

// 通用加法函数
template<class T>
T Add(T left, T right)
{
	return left + right;
}


// 通用加法函数
//template<class T1, class T2>
//T1 Add(T1 left, T2 right)
//{
//	return left + right;
//}

//int main()
//{
//	int a = 1, b = 2;
//	Add(a, b);
//
//	Add<int>(a, b);
//
//	Add(1, 2.2);
//
//	return 0;
//}

//typedef double STDataType;
//class Stackint
//{
//private:
//	STDataType* _a;
//	size_t _top;
//	size_t _capacity;
//};
//
//int main()
//{
//	Stack st1; // int
//	Stack st2; // double
//
//
//	return 0;
//}

template<class T>
class Stack
{
public:
	Stack(int capaicty = 4)
	{
		_a = new T[capaicty];
		_top = 0;
		_capacity = capaicty;
	}

	~Stack()
	{
		delete[] _a;
		_capacity = _top = 0;
	}

private:
	T* _a;
	size_t _top;
	size_t _capacity;
};

int main()
{
	Stack<int> st1; // int
	Stack<double> st2; // double

	/*vector<int> v;
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}*/

	return 0;
}