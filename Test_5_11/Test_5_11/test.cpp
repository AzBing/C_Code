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
	string _name = "С����"; // ����
	int _num = 111; 	   // ���֤��
};

class Student : public Person
{
public:
	void Print()
	{
		cout << " ����:" << _name << endl;
		cout << " ���֤��:" << Person::_num << endl;
		cout << " ѧ��:" << _num << endl;
	}
protected:
	int _num = 999; // ѧ��
};

// ��������������ͬ����Ա����Ϊ�����Ƕ���������
// Ĭ�����ֱ�ӷ���������ģ�����ͬ����Ա���ظ���ͬ����Ա
// �̳��У�ͬ���ĳ�Ա��������������ͬ�͹������أ����ܲ����ͷ���ֵ

// A:����fun���ɺ�������
// B:����fun��������
// C:���뱨��
// D:���б���
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
