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
//	// ����������������ֻ����һ��
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
//	// �ڲ��� -- ��A�Ƕ�����ֻ����A����������
//	// B��������A����Ԫ
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
////	A aa1 = 1; // ����+�������� -�� �Ż�Ϊֱ�ӹ���
////	func1(aa1); // ���Ż�
////	func1(2); // ����+�������� -�� �Ż�Ϊֱ�ӹ���
////	func1(A(3)); // ����+�������� -�� �Ż�Ϊֱ�ӹ���
////
////	cout << "----------------------------------" << endl;
////
////	func2(aa1);  // ���Ż�
////	func2(2);    // ���Ż�
////	func2(A(3)); // ���Ż�
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

//���̽��C++����ģ��

int main()
{
	func3();

	A aa1 = func3(); // ��������+��������  -- �Ż�Ϊһ����������

	cout << "****" << endl;
	A aa2;
	aa2 = func3();  // �����Ż�

	cout << "---------------------------" << endl;
	func4(); // ����+�������� -- �Ż�Ϊ����
	A aa3 = func4(); // ����+��������+��������  -- �Ż�Ϊ����

	return 0;
}