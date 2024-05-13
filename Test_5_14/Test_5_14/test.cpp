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
//// 组合
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
		cout << "Person买票-全价" << endl;
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
		cout << "Student买票-半价" << endl;
		return nullptr;
	}

	/*注意：在重写基类虚函数时，派生类的虚函数在不加virtual关键字时，虽然也可以构成重写(因为继承后基类的虚函数被继承下来了在派生类依旧保持虚函数属性),但是该种写法不是很规范，不建议这样使用*/
	/*void BuyTicket() { cout << "买票-半价" << endl; }*/

	~Student()
	{
		cout << "~Student()" << endl;
	}
};

// 多态的条件:
// 1、虚函数重写
// 2、父类的指针或者引用去调用虚函数
// 
// 虚函数重写
// 父子继承关系的两个虚函数，三同(函数名/参数/返回)
// virtual只能修饰成员
// 三同(函数名/参数/返回)的例外：协变->返回值可以不同，但是必须是父子类关系的指针或者引用
// 派生类重写的虚函数函数可以不加virtual(建议都加上)

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

	// 析构是虚函数，才能正确调用析构函数
	// p->destrutor() + operator delete(p)
	delete p;

	p = new Student;

	// p->destrutor() + operator delete(p)
	delete p;

	return 0;
}
