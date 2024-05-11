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
	string _name; // ����
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

	// ���ڶ�̬��ԭ����������ͳһ�ᱻ�����destructor
	// �����������������������
	// Ϊ�˱�֤������ȫ�����Ӻ�
	// ����������������Ҫ��ʾ���ã�����������������ʱ���Զ����ø�������
	// ��֤���Ӻ�
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
	Student s1("����", 18);
	Student s2(s1);

	Student s3("����", 19);
	s1 = s3;


	return 0;
}