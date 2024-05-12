#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

// 如何实现一个不能被继承的类？
// C++98 私有化父类的构造函数
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

// C++11 新增final，修饰父类，直接不能被继承
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
//	string _name; // 姓名
//};
//
//class Student : public Person
//{
//	friend void Display(const Person& p, const Student& s);
//protected:
//	int _stuNum; // 学号
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
//	string _name; // 姓名
//public:
//	static int _count; // 统计人的个数。
//};
//
//int Person::_count = 0;
//
//class Student : public Person
//{
//protected:
//	int _stuNum; // 学号
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
//	string _name; // 姓名
//	int _age;
//	int _tel;
//	// ...
//};
//class Student : virtual public Person
//{
//protected:
//	int _num; //学号
//};
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // 职工编号
//};
//
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};

//void Test()
//{
//	// 这样会有二义性无法明确知道访问的是哪一个
//	Assistant a;
//	a.Student::_name = "小张";
//	a.Teacher::_name = "老张";
//	a._name = "张三";
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