#define _CRT_SECURE_NO_WARNINGS 1
#include "stack.hpp"

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