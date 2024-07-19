#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//
//void Swap(double& left, double& right)
//{
//	double temp = left;
//	left = right;
//	right = temp;
//}
//
//void Swap(char& left, char& right)
//{
//	char temp = left;
//	left = right;
//	right = temp;
//}

// 模板
// Type
//template<class T>
//template<typename T>
//template<typename T1, typename T2>

// 编译器用模板实例化生成对应的Swap函数

// 函数模板
//template<class T>
//void Swap(T& left, T& right)
//{
//	T temp = left;
//	left = right;
//	right = temp;
//}
//
//int main()
//{
//	int i = 0, j = 1;
//	Swap(i, j);
//
//	double x = 1.1, y = 2.2;
//	Swap(x, y);
//
//	return 0;
//}

// 类模板

//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 4)
//	{
//		cout << "Stack()" << endl;
//
//		_array = new DataType[capacity];
//		//_array = new char[0x7fffffff];
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
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//
//		delete[] _array;
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
//int main()
//{
//	Stack st1; // int
//	Stack st2; // double
//
//	return 0;
//}


template<class T>
class Stack
{
public:
	Stack(size_t capacity = 4)
	{
		cout << "Stack()" << endl;

		_array = new T[capacity];

		_capacity = capacity;
		_size = 0;
	}

	void Push(const T& data)
	{
		// CheckCapacity();
		_array[_size] = data;
		_size++;
	}

	~Stack()
	{
		cout << "~Stack()" << endl;

		delete[] _array;
		_array = nullptr;
		_size = _capacity = 0;
	}
private:
	T* _array;
	int _capacity;
	int _size;
};

//int main()
//{
//	Stack<int> st1; // int
//	Stack<double> st2; // double
//
//	st1.Push(1);
//	st1.Push(2);
//
//
//	st2.Push(1.2);
//	st2.Push(1.2);
//
//	return 0;
//}

template<class T>
T Add(const T& left, const T& right)
{
	return left + right;
}

int main()
{
	cout << Add(1, 2) << endl;

	//cout << Add(1.1, 2) << endl;

	cout << Add((int)1.1, 2) << endl;
	cout << Add(1.1, (double)2) << endl;

	// 显示实例化
	cout << Add<int>(1.1, 2) << endl;
	cout << Add<double>(1.1, 2) << endl;

	return 0;
}
