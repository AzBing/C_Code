#define _CRT_SECURE_NO_WARNINGS 1
#include "stack.h"

//int main()
//{
//	Add(1, 2);  // call Add<int>(?)
//	func();     // call func(?)
//
//	Add(1.1, 2.2);  // call Add<double>(?)
//
//	Stack<int> st;
//	st.Push(1);
//	st.Pop();
//
//	Stack<double> stt;
//	stt.Push(1);
//}


//class Person
//{
////protected:
//public:
////private:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	string _name = "peter"; // 姓名
//	int _age = 18;  // 年龄
//};
//
//
//class Student : private Person
//{
//public:
//	void func()
//	{
//		Print();
//	}
//protected:
//	int _stuid; // 学号
//};
//
//class Teacher : public Person
//{
//protected:
//	int _jobid; // 工号
//};
//
//int main()
//{
//	Student s;
//	Teacher t;
//
//	//s.Print();
//	//t.Print();
//
//
//	return 0;
//}

//class Person
//{
//protected:
//	string _name; // 姓名
//	string _sex;  // 性别
//	int	_age;	 // 年龄
//};
//
//class Student : public Person
//{
//public:
//	int _No; // 学号
//};

//int main()
//{
//	double d = 2.2;
//	int i = d;
//	const int& r = d;
//
//	string str = "xxxx";
//	const string& rstr = "xxxx";
//
//	Student s;
//	Person p = s;
//	Person& rp = s;
//
//	return 0;
//}

class Person
{
protected:
	string _name = "小李子"; // 姓名
	int _num = 111; 	   // 身份证号
};

class Student : public Person
{
public:
	void Print()
	{
		cout << " 姓名:" << _name << endl;
		cout << " 身份证号:" << Person::_num << endl;
		cout << " 学号:" << _num << endl;
	}
protected:
	int _num = 999; // 学号
};

// 父类和子类可以有同名成员，因为他们是独立作用域
// 默认情况直接访问是子类的，子类同名成员隐藏父类同名成员
// 继承中，同名的成员函数，函数名相同就构成隐藏，不管参数和返回值

// A:两个fun构成函数重载
// B:两个fun构成隐藏
// C:编译报错
// D:运行报错
class A
{
public:
	void fun()
	{
		cout << "func()" << endl;
	}
};

class B : public A
{
public:
	void fun(int i)
	{
		cout << "func(int i)->" << i << endl;
	}
};

void Test()
{
	B b;
	b.fun(10);
	b.A::fun();
};

int main()
{
	Student s;
	s.Print();
	Test();

	return 0;
}
