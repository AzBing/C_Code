#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//#include<iostream>
//using namespace std;
//
//class Person {
//public:
//	virtual void BuyTicket() { cout << "Person::买票-全价" << endl; }
//
//	virtual ~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//};
//
//class Student : public Person {
//public:
//	// 重载
//	// 隐藏/重定义
//	// 虚函数重写
//	void BuyTicket() { cout << "Student::买票-半价" << endl; }
//
//	~Student()
//	{
//		cout << "~Student()" << endl;
//	}
//};

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

//void Func(Person* p)
//{
//	p->BuyTicket();
//}
//
//int main()
//{
//	/*Person ps;
//	Student st;
//
//	Func(&ps);
//	Func(&st);*/
//
//	Person* ptr = new Person;
//	delete ptr;
//
//	ptr = new Student;
//	delete ptr;
//
//	return 0;
//}

//class A
//{
//public:
//	virtual void func(int val = 1) { std::cout << "A->" << val << std::endl; }
//	virtual void test() { func(); }
//};
//
//class B : public A
//{
//public:
//	void func(int val = 0) { std::cout << "B->" << val << std::endl; }
//};
//
//int main(int argc, char* argv[])
//{
//	B* p = new B;
//	//p->test();
//	p->func();
//
//	return 0;
//}

// final 修饰类，不能被继承
// final 修饰虚函数，不能被重写
//class Car
//{
//public:
//	virtual void Drive() final {}
//};
//
//class Benz :public Car
//{
//public:
//	virtual void Drive() { cout << "Benz-舒适" << endl; }
//};

//class Car {
//public:
//	virtual void Drive() {}
//};
//
//class Benz :public Car {
//public:
//	// override修饰派生类的虚函数
//	// 检查是否完成重写
//	virtual void Drive() override { cout << "Benz-舒适" << endl; }
//};
//
//int main()
//{
//
//	return 0;
//}
//
//class Car
//{
//public:
//	// 纯虚函数
//	// 1、间接强制去派生类去重写
//	// 2、抽象类-不能实例化出对象
//	virtual void Drive() = 0;
//
//	void func()
//	{
//		cout << "void func()" << endl;
//	}
//};
//
//class Benz :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "Benz-舒适" << endl;
//	}
//};
//
//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "BMW-操控" << endl;
//	}
//};
//
//void func(Car* ptr)
//{
//	ptr->Drive();
//}

//int main()
//{
//	func(new Benz);
//	func(new BMW);
//
//	return 0;
//}

//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//
//	virtual void Func2()
//	{
//		cout << "Func2()" << endl;
//	}
//
//	void Func3()
//	{
//		cout << "Func3()" << endl;
//	}
//private:
//	int _b = 1;
//	char _ch;
//};
//
//int main()
//{
//	cout << sizeof(Base) << endl;
//	Base b;
//
//	return 0;
//}

class Person {
public:
	virtual void BuyTicket() { cout << "买票-全价" << endl; }
	virtual void func(){}

private:
	int a = 0;
};

class Student : public Person {
public:
	// 如果子类不重写虚函数，父类和子类对象的虚表是否一样？
	//virtual void BuyTicket() { cout << "买票-半价" << endl; }

private:
	int b = 1;
};

void Func(Person ptr)
{
	ptr.BuyTicket();
}

int main()
{
	Person p1;
	Person p2;
	Person p3;

	Student s1;
	Student s2;

	//Func(p);
	//Func(s);

	return 0;
}

