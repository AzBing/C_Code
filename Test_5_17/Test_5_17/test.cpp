#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


//class Person
//{
//public:
//	Person()
//	{
//		++_count;
//	}
//public:
//	static int _count;//ͨ��static��Ա����ͳ���˵ĸ���
//protected:
//	string _name;
//};
//int Person::_count = 0;//��ʼ��count
//
//class Student :public Person
//{
//protected:
//	int _id;
//};
//
//int main()
//{
//	Student s1;
//	Student s2;
//	Student s3;
//	cout << Student::_count << endl;//���������ֵΪ3��Ҳ����˵���Ǵ�������������
//	cout << &Person::_count << endl;
//	cout << &Student::_count << endl;
//	return 0;
//}

//#include<iostream>
//#include<stdio.h>
//using namespace std;
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Base" << endl;
//	}
//	virtual void Func2()
//	{
//		cout << "Func2" << endl;
//	}
//	void Func3()
//	{
//		cout << "Func3" << endl;
//	}
//	int _b = 0;
//};
//class Derive :public Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << " Derive" << endl;
//	}
//	virtual void Func4()
//	{
//		cout << "Func4" << endl;
//	}
//	int _d = 0;
//};
//typedef void(*pFun)();
//void PrintFTB(pFun table[])
//{
//
//}
//void Print()
//{
//	//�������
//	Base b1;
//	Base b2;
//	//���������
//	Derive d1;
//	Derive d2;
//	//ȥ����������麯����
//	cout << "�麯����ĵ�ַ" << *(int*)&d1 << endl;//�ҵ��麯����ĵ�ַ
//	int a = 0;//ջ�ϴ����Ķ���
//	int* p1 = &a;
//	int* p2 = new int();//���ϴ����Ķ���
//	const char* p3 = "hello";
//	printf("ջ����:%p\n", p1);
//	printf("�ѱ���:%p\n", p2);
//	printf("����γ���:%p\n", p3);
//	printf("�麯����ַ:%p\n", &Derive::Func2);
//	printf("��ͨ����:%p\n", Print);
//}
//int main()
//{
//	Derive d1;
//	Base b1;
//	Print();
//	return 0;
//}


#include<iostream>
#include<stdio.h>
using namespace std;
class Base
{
public:
	virtual void Fun1() { cout << "Base---Fun1" << endl; }
	virtual void Fun2() { cout << "Base---Fun2" << endl; }
};
class Derive :public Base
{
public:
	virtual void Fun1() { cout << "Derive---Fun1" << endl; }//��д��Fun1
	virtual void Fun3() { cout << "Derive---Fun3" << endl; }
	virtual void Fun4() { cout << "Derive---Fun4" << endl; }
};
//int main()
//{
//	Derive d1;
//	Derive b1;
//	return 0;
//}

typedef void(*pFun)();//�Ժ���ָ������������
void PrintVFTable(pFun* pTable)
{
	for (size_t i = 0; pTable[i] != 0; ++i)
	{
		printf("��%i���麯���ĵ�ַ:%p", i, pTable[i]);
		pFun f = pTable[i];//��������е��麯��
		f();
	}
}
// 1.��ȡb�ĵ�ַ��ǿת��һ��int * ��ָ��
// 2.�ٽ�����ȡֵ����ȡ����b����ͷ4bytes��ֵ�����ֵ����ָ������ָ��
// 3.��ǿת��pFun*����Ϊ������һ����pFun����(�麯��ָ������)�����顣
// 4.���ָ�봫�ݸ�PrintVTable���д�ӡ���
// 5.��Ҫ˵�����������ӡ���Ĵ��뾭�����������Ϊ��������ʱ�����Ĵ����ɾ��������
//����û�з�nullptr������Խ�磬���Ǳ����������⡣����ֻ��Ҫ��Ŀ¼����-����-��������������
//����ͺ��ˡ�
int main()
{
	Derive d1;
	Base b1;
	PrintVFTable((pFun*)(*(int*)&d1));//ȡ�������ǰ�ĸ��ֽ��ҵ����
	PrintVFTable((pFun*)(*(int*)&b1)); //��ӡBase������
	return 0;
}

