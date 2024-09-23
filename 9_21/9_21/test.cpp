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
//	string _name = "peter"; // ����
//	int _age = 18;  // ����
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
//	int _stuid; // ѧ��
//};
//
//class Teacher : public Person
//{
//protected:
//	int _jobid; // ����
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
//	string _name; // ����
//	string _sex;  // �Ա�
//	int	_age;	 // ����
//};
//
//class Student : public Person
//{
//public:
//	int _No; // ѧ��
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
//	string _name = "С����"; // ����
//	int _num = 111; 	   // ���֤��
//};
//
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " ����:" << _name << endl;
//		cout << " ���֤��:" << Person::_num << endl;
//		cout << " ѧ��:" << _num << endl;
//	}
//protected:
//	int _num = 999; // ѧ��
//};
//
//// ��������������ͬ����Ա����Ϊ�����Ƕ���������
//// Ĭ�����ֱ�ӷ���������ģ�����ͬ����Ա���ظ���ͬ����Ա
//// �̳��У�ͬ���ĳ�Ա��������������ͬ�͹������أ����ܲ����ͷ���ֵ
//
//// A:����fun���ɺ�������
//// B:����fun��������
//// C:���뱨��
//// D:���б���
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