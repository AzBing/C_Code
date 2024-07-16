#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//// 累积创建了多少个对象  
//int n = 0;
//
//// 正在使用的还有多少个对象
//int m = 0;
//
//class A
//{
//public:
//	A()
//	{
//		++n;
//		++m;
//	}
//
//	A(const A& t)
//	{
//		++n;
//		++m;
//	}
//
//	~A() 
//	{
//		--m;
//	}
//private:
//};
//
////A& Func(A& aa)
//A Func(A aa)
//{
//	return aa;
//}
//
//int main()
//{
//	A aa1;
//	A aa2;
//	cout << n << " " << m << endl;
//	
//	// 可能被外面随意修改
//	//--n;
//	//++m;
//	A();
//	cout << n << " " << m << endl;
//
//
//	Func(aa1);
//	cout << n << " " << m << endl;
//
//
//	return 0;
//}

//class A
//{
//public:
//	A()
//	{
//		cout << "A()" << endl;
//		++n;
//		++m;
//	}
//
//	A(const A& t)
//	{
//		++n;
//		++m;
//	}
//
//	~A()
//	{
//		--m;
//	}
//
//	// 静态成员函数的特点：没有this指针
//	static int GetM()
//	{
//		return m;
//	}
//
//	// ...
//
//	static void Print()
//	{
//		// x++; // 不能访问非静态，因为没有this
//
//		cout << m <<" " << n << endl;
//	}
//
//private:
//	// 静态成员变量属于所有A对象，属于整个类
//	// 声明
//	// 累积创建了多少个对象  
//	static int n;
//	// 正在使用的还有多少个对象
//	static int m;
//
//	int x = 0;
//};
//
////class SeqList
////{
////	int& operator[](int i)
////	{
////		return a[i];
////	}
////
////private:
////	int a[10];
////};
//
//// 定义
//int A::n = 0;
//int A::m = 0;
//
////A& Func(A& aa)
//A Func(A aa)
//{
//	return aa;
//}
//
//int main()
//{
//	A();
//	A();
//
//	A::Print();
//	++A::GetM();
//	A::Print();
//
//	A aa1;
//	Func(aa1);
//
//	aa1.Print();
//
//	return 0;
//}

//int main()
//{
//	A aa1;
//	A aa2;
//	cout << A::n << " " << A::m << endl;
//	cout << aa1.n << " " << aa2.m << endl;
//	A* ptr = nullptr;
//	cout << ptr->n << " " << ptr->m << endl;
//
//	// 可能被外面随意修改
//	A();
//	cout << n << " " << m << endl;
//
//	Func(aa1);
//	cout << n << " " << m << endl;
//
//	return 0;
//}

// 友元函数
// 友元类
// 能不用友元就不要用

//class B
//{
//private:
//	int _b;
//};
//
//class A
//{
//public:
//	
//private:
//	int _a;
//};

// 1、B类受A类域和访问限定符的限制，其实他们是两个独立的类
// 2、内部类默认就是外部类的友元类
class A
{
//public:
	class B
	{
	public:
		void FuncB()
		{
			A aa;
			aa._a = 1;
		}
	private:
		int _b;
	};

	void func()
	{
		B bb;
	}

private:
	int _a;
};


int main()
{
	cout << sizeof(A) << endl;

	A aa;
	//A::B bb1;

	return 0;
}