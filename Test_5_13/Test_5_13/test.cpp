#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

// ���ʵ��һ�����ܱ��̳е��ࣿ
// C++98 ˽�л�����Ĺ��캯��
//class A
//{
//public:
//private:
//	A()
//	{}
//
//private:
//	int _a;
//	int _b;
//};
//
//class B : public A
//{
//public:
//	B()
//		:A()
//	{}
//};
//
//int main()
//{
//	B bb;
//
//	return 0;
//}

// C++11 ����final�����θ��ֱ࣬�Ӳ��ܱ��̳�
//class A  final
//{
//public:
//	A()
//	{}
//
//private:
//	int _a;
//	int _b;
//};
//
//class B : public A
//{
//public:
//};
//
//int main()
//{
//	B bb;
//
//	return 0;
//}

//class Student;
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // ����
//};
//
//class Student : public Person
//{
//	friend void Display(const Person& p, const Student& s);
//protected:
//	int _stuNum; // ѧ��
//};
//
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	cout << s._stuNum << endl;
//}
//
//int main()
//{
//	Person p;
//	Student s;
//	Display(p, s);
//
//	return 0;
//}

//class Person
//{
//public:
//	Person() { ++_count; }
//protected:
//	string _name; // ����
//public:
//	static int _count; // ͳ���˵ĸ�����
//};
//
//int Person::_count = 0;
//
//class Student : public Person
//{
//protected:
//	int _stuNum; // ѧ��
//};
//
//Student func()
//{
//	Student st;
//	return st;
//}
//
//int main()
//{
//	Person p;
//	Student s;
//	func();
//
//	cout << Student::_count << endl;
//
//	return 0;
//}

//class Person
//{
//public:
//	string _name; // ����
//	int _age;
//	int _tel;
//	// ...
//};
//class Student : virtual public Person
//{
//protected:
//	int _num; //ѧ��
//};
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // ְ�����
//};
//
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // ���޿γ�
//};

//void Test()
//{
//	// �������ж������޷���ȷ֪�����ʵ�����һ��
//	Assistant a;
//	a.Student::_name = "С��";
//	a.Teacher::_name = "����";
//	a._name = "����";
//}
//
//int main()
//{
//	Test();
//
//	return 0;
//}

class A
{
public:
	//int _a[100];
	int _a;
};

//class B : public A
class B : virtual public A
{
public:
	int _b;
};

//class C : public A
class C : virtual public A
{
public:
	int _c;
};

class D : public B, public C
{
public:
	int _d;
};

int main()
{
	D d;
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;
	d._a = 0;

	D dd;
	D ddd;

	B bb;
	bb._a = 1;
	bb._b = 2;

	cout << sizeof(D) << endl;

	return 0;
}