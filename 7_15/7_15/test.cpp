#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//// �ۻ������˶��ٸ�����  
//int n = 0;
//
//// ����ʹ�õĻ��ж��ٸ�����
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
//	// ���ܱ����������޸�
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
//	// ��̬��Ա�������ص㣺û��thisָ��
//	static int GetM()
//	{
//		return m;
//	}
//
//	// ...
//
//	static void Print()
//	{
//		// x++; // ���ܷ��ʷǾ�̬����Ϊû��this
//
//		cout << m <<" " << n << endl;
//	}
//
//private:
//	// ��̬��Ա������������A��������������
//	// ����
//	// �ۻ������˶��ٸ�����  
//	static int n;
//	// ����ʹ�õĻ��ж��ٸ�����
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
//// ����
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
//	// ���ܱ����������޸�
//	A();
//	cout << n << " " << m << endl;
//
//	Func(aa1);
//	cout << n << " " << m << endl;
//
//	return 0;
//}

// ��Ԫ����
// ��Ԫ��
// �ܲ�����Ԫ�Ͳ�Ҫ��

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

// 1��B����A����ͷ����޶��������ƣ���ʵ������������������
// 2���ڲ���Ĭ�Ͼ����ⲿ�����Ԫ��
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