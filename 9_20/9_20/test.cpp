#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.hpp"

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

class Person
{
protected:
	string _name; // 姓名
	string _sex;  // 性别
	int	_age;	 // 年龄
};

class Student : public Person
{
public:
	int _No; // 学号
};

int main()
{
	double d = 2.2;
	int i = d;
	const int& r = d;

	string str = "xxxx";
	const string& rstr = "xxxx";

	Student s;
	Person p = s;
	Person& rp = s;

	return 0;
}

