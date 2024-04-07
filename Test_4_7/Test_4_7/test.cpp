#include<iostream>
using namespace std;

//class Sum
//{
//public:
//	Sum()
//	{
//		_sum += _i;
//		++_i;
//	}
//
//	static int GetSum()
//	{
//		return _sum;
//	}
//private:
//	static int _i;
//	static int _sum;
//};
//
//int Sum::_i = 1;
//int Sum::_sum = 0;
//
//class Solution {
//public:
//	int Sum_Solution(int n) {
//		//Sum a[n];
//		Sum* ptr = new Sum[n];
//
//		return Sum::GetSum();
//	}
//
//	~Solution()
//	{
//		cout << "~Solution()" << endl;
//	}
//};
//
//A func()
//{
//	int n;
//	cin >> n;
//	int ret = Solution().Sum_Solution(n);
//
//	//A retA(ret);
//	//return retA;
//	return A(ret);
//}
//
//int main()
//{
//	/*Solution s;
//	cout << s.Sum_Solution(10) << endl;*/
//
//	cout << Solution().Sum_Solution(10) << endl;
//
//	//Solution s1();
//
//	// 匿名对象，生命周期只在这一行
//	Solution();
//	Sum();
//
//	return 0;
//}

//class A
//{
//private:
//	static int k;
//	int h = 1;
////public:
//	// 内部类 -- 跟A是独立，只是受A的类域限制
//	// B天生就是A的友元
//	class B
//	{
//	public:
//		void foo(const A& a)
//		{
//			cout << k << endl;//OK
//			cout << a.h << endl;//OK
//		}
//	private:
//		int b = 2;
//	};
//};
//
//int A::k = 1;
//
//int main()
//{
//	A aa;
//	cout << sizeof(aa) << endl;
//
//	//A::B bb;
//
//	return 0;
//}

class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A(int a)" << endl;
	}

	A(const A& aa)
		:_a(aa._a)
	{
		cout << "A(const A& aa)" << endl;
	}

	A& operator=(const A& aa)
	{
		cout << "A& operator=(const A& aa)" << endl;

		if (this != &aa)
		{
			_a = aa._a;
		}

		return *this;
	}

	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};

void func1(A aa)
{

}

void func2(const A& aa)
{

}
//
////int main()
////{
////	A aa1 = 1; // 构造+拷贝构造 -》 优化为直接构造
////	func1(aa1); // 无优化
////	func1(2); // 构造+拷贝构造 -》 优化为直接构造
////	func1(A(3)); // 构造+拷贝构造 -》 优化为直接构造
////
////	cout << "----------------------------------" << endl;
////
////	func2(aa1);  // 无优化
////	func2(2);    // 无优化
////	func2(A(3)); // 无优化
////
////
////	return 0;
////}
//
A func3()
{
	A aa;
	return aa; 
}

A func4()
{
	return A();
}

//深度探索C++对象模型

int main()
{
	func3();

	A aa1 = func3(); // 拷贝构造+拷贝构造  -- 优化为一个拷贝构造

	cout << "****" << endl;
	A aa2;
	aa2 = func3();  // 不能优化

	cout << "---------------------------" << endl;
	func4(); // 构造+拷贝构造 -- 优化为构造
	A aa3 = func4(); // 构造+拷贝构造+拷贝构造  -- 优化为构造

	return 0;
}