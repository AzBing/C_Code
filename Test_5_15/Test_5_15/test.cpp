#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//#include<iostream>
//using namespace std;
//
//class Person {
//public:
//	virtual void BuyTicket() { cout << "Person::��Ʊ-ȫ��" << endl; }
//
//	virtual ~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//};
//
//class Student : public Person {
//public:
//	// ����
//	// ����/�ض���
//	// �麯����д
//	void BuyTicket() { cout << "Student::��Ʊ-���" << endl; }
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

// final �����࣬���ܱ��̳�
// final �����麯�������ܱ���д
//class Car
//{
//public:
//	virtual void Drive() final {}
//};
//
//class Benz :public Car
//{
//public:
//	virtual void Drive() { cout << "Benz-����" << endl; }
//};

//class Car {
//public:
//	virtual void Drive() {}
//};
//
//class Benz :public Car {
//public:
//	// override������������麯��
//	// ����Ƿ������д
//	virtual void Drive() override { cout << "Benz-����" << endl; }
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
//	// ���麯��
//	// 1�����ǿ��ȥ������ȥ��д
//	// 2��������-����ʵ����������
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
//		cout << "Benz-����" << endl;
//	}
//};
//
//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "BMW-�ٿ�" << endl;
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
	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
	virtual void func(){}

private:
	int a = 0;
};

class Student : public Person {
public:
	// ������಻��д�麯���������������������Ƿ�һ����
	//virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }

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

