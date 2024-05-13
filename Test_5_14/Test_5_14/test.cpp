#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//class A
//{
//public:
//	void func()
//	{}
//protected:
//	int _a;
//};
//
//class B : public A
//{
//public:
//	void f()
//	{
//		func();
//		_a++;
//	}
//protected:
//	int _b;
//};
//
//// ���
//class C
//{
//public:
//	void func()
//	{}
//protected:
//	int _c;
//};
//
//class D
//{
//public:
//	void f()
//	{
//		_c.func();
//		//_c._a++;
//	}
//protected:
//	C _c;
//	int _d;
//};
//
//int main()
//{
//	cout << sizeof(D) << endl;
//	cout << sizeof(B) << endl;
//
//	D dd;
//	//dd.func();
//
//	B bb;
//	bb.func();
//
//	return 0;
//}

//class Base1 { public:  int _b1; };
//class Base2 { public:  int _b2; };
//class Derive : public Base1, public Base2 { public: int _d; };
//
//int main() {
//	Derive d;
//	Base1* p1 = &d;
//	Base2* p2 = &d;
//	Derive* p3 = &d;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class A {
//public:
//	A(const char* s) { cout << s << endl; }
//	~A() {}
//};
//
////class B :virtual public A
//class B : public A
//{
//public:
//	B(const char* s1, const char* s2) :A(s1) { cout << s2 << endl; }
//};
//
//class C : public A
//{
//public:
//	C(const char* s1, const char* s2) :A(s1) { cout << s2 << endl; }
//};
//
//class D : public C, public B
//{
//public:
//	//D(const char* s1, const char* s2, const char* s3, const char* s4) 
//	//	:B(s1, s2)
//	//	, C(s1, s3)
//	//	, A(s1)
//	//{
//	//	cout << s4 << endl;
//	//}
//
//	D(const char* s1, const char* s2, const char* s3, const char* s4)
//		:B(s1, s2)
//		, C(s1, s3)
//	{
//		cout << s4 << endl;
//	}
//};
//
//int main() {
//	D* p = new D("class A", "class B", "class C", "class D");
//	delete p;
//	return 0;
//}


class A
{
public:
	void func()
	{}
protected:
	int _a;
};

class B : public A
{
public:
	void f()
	{
		func();
		_a++;
	}
protected:
	int _b;
};

class Person {
public:
	virtual A* BuyTicket()
	{
		cout << "Person��Ʊ-ȫ��" << endl;
		return nullptr;
	}

	virtual ~Person()
	{
		cout << "~Person()" << endl;
	}
};

class Student : public Person {
public:
	virtual B* BuyTicket()
	{
		cout << "Student��Ʊ-���" << endl;
		return nullptr;
	}

	/*ע�⣺����д�����麯��ʱ����������麯���ڲ���virtual�ؼ���ʱ����ȻҲ���Թ�����д(��Ϊ�̳к������麯�����̳������������������ɱ����麯������),���Ǹ���д�����Ǻܹ淶������������ʹ��*/
	/*void BuyTicket() { cout << "��Ʊ-���" << endl; }*/

	~Student()
	{
		cout << "~Student()" << endl;
	}
};

// ��̬������:
// 1���麯����д
// 2�������ָ���������ȥ�����麯��
// 
// �麯����д
// ���Ӽ̳й�ϵ�������麯������ͬ(������/����/����)
// virtualֻ�����γ�Ա
// ��ͬ(������/����/����)�����⣺Э��->����ֵ���Բ�ͬ�����Ǳ����Ǹ������ϵ��ָ���������
// ��������д���麯���������Բ���virtual(���鶼����)

//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//
//int main()
//{
//	Person ps;
//	Student st;
//
//	Func(ps);
//	Func(st);
//
//	return 0;
//}

int main()
{
	Person* p = new Person;

	// �������麯����������ȷ������������
	// p->destrutor() + operator delete(p)
	delete p;

	p = new Student;

	// p->destrutor() + operator delete(p)
	delete p;

	return 0;
}
