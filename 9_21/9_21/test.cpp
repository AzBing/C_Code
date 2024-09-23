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
//
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

//class Person
//{
//protected:
//	string _name = "小李子"; // 姓名
//	int _num = 111; 	   // 身份证号
//};
//
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " 姓名:" << _name << endl;
//		cout << " 身份证号:" << Person::_num << endl;
//		cout << " 学号:" << _num << endl;
//	}
//protected:
//	int _num = 999; // 学号
//};
//
//// 父类和子类可以有同名成员，因为他们是独立作用域
//// 默认情况直接访问是子类的，子类同名成员隐藏父类同名成员
//// 继承中，同名的成员函数，函数名相同就构成隐藏，不管参数和返回值
//
//// A:两个fun构成函数重载
//// B:两个fun构成隐藏
//// C:编译报错
//// D:运行报错
//class A
//{
//public:
//	void fun()
//	{
//		cout << "func()" << endl;
//	}
//};
//
//class B : public A
//{
//public:
//	void fun(int i)
//	{
//		cout << "func(int i)->" << i << endl;
//	}
//};
//
//void Test()
//{
//	B b;
//	b.fun(10);
//	b.A::fun();
//};

//int main()
//{
//	Student s;
//	s.Print();
//	Test();
//
//	return 0;
//}

class Person
{
public:
	Person(const char* name = "peter")
		: _name(name)
	{
		cout << "Person()" << endl;
	}

	Person(const Person& p)
		: _name(p._name)
	{
		cout << "Person(const Person& p)" << endl;
	}

	Person& operator=(const Person& p)
	{
		cout << "Person operator=(const Person& p)" << endl;
		if (this != &p)
			_name = p._name;

		return *this;
	}

	~Person()
	{
		cout << "~Person()" << endl;
	}
protected:
	string _name; // 姓名
};

class Student : public Person
{
public:
	Student(const char* name, int id)
		:_id(id)
		, Person(name)
	{
		cout << "Student(const char* name, int id)" << endl;
	}

	Student(const Student& s)
		:Person(s)
		, _id(s._id)
	{
		cout << "Student(const Student& s)" << endl;
	}

	Student& operator=(const Student& s)
	{
		if (&s != this)
		{
			Person::operator=(s);
			_id = s._id;
		}

		cout << "Student& operator=(const Student& s)" << endl;

		return *this;
	}

	// 由于多态的原因，析构函数统一会被处理成destructor
	// 父子类的析构函数构成隐藏
	// 为了保证析构安全，先子后父
	// 父类析构函数不需要显示调用，子类析构函数结束时会自动调用父类析构
	// 保证先子后父
	~Student()
	{
		//Person::~Person();
		cout << "~Student()" << endl;
	}

protected:
	int _id;
};

int main()
{
	Student s1("张三", 18);
	Student s2(s1);

	Student s3("李四", 19);
	s1 = s3;


	return 0;
}