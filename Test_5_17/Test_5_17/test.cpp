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
//	static int _count;//通过static成员变量统计人的个数
//protected:
//	string _name;
//};
//int Person::_count = 0;//初始化count
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
//	cout << Student::_count << endl;//最后的输出数值为3，也就是说我们创建了三个对象
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
//	//基类对象
//	Base b1;
//	Base b2;
//	//派生类对象
//	Derive d1;
//	Derive d2;
//	//去派生类对象虚函数表
//	cout << "虚函数表的地址" << *(int*)&d1 << endl;//找到虚函数表的地址
//	int a = 0;//栈上创建的对象
//	int* p1 = &a;
//	int* p2 = new int();//堆上创建的对象
//	const char* p3 = "hello";
//	printf("栈变量:%p\n", p1);
//	printf("堆变量:%p\n", p2);
//	printf("代码段常量:%p\n", p3);
//	printf("虚函数地址:%p\n", &Derive::Func2);
//	printf("普通函数:%p\n", Print);
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
	virtual void Fun1() { cout << "Derive---Fun1" << endl; }//重写了Fun1
	virtual void Fun3() { cout << "Derive---Fun3" << endl; }
	virtual void Fun4() { cout << "Derive---Fun4" << endl; }
};
//int main()
//{
//	Derive d1;
//	Derive b1;
//	return 0;
//}

typedef void(*pFun)();//对函数指针重新起名字
void PrintVFTable(pFun* pTable)
{
	for (size_t i = 0; pTable[i] != 0; ++i)
	{
		printf("第%i个虚函数的地址:%p", i, pTable[i]);
		pFun f = pTable[i];//调用虚表中的虚函数
		f();
	}
}
// 1.先取b的地址，强转成一个int * 的指针
// 2.再解引用取值，就取到了b对象头4bytes的值，这个值就是指向虚表的指针
// 3.再强转成pFun*，因为虚表就是一个存pFun类型(虚函数指针类型)的数组。
// 4.虚表指针传递给PrintVTable进行打印虚表
// 5.需要说明的是这个打印虚表的代码经常会崩溃，因为编译器有时对虚表的处理不干净，虚表最
//后面没有放nullptr，导致越界，这是编译器的问题。我们只需要点目录栏的-生成-清理解决方案，再
//编译就好了。
int main()
{
	Derive d1;
	Base b1;
	PrintVFTable((pFun*)(*(int*)&d1));//取出对象的前四个字节找到虚表
	PrintVFTable((pFun*)(*(int*)&b1)); //打印Base的续表
	return 0;
}

