#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Base1 {
public:
	virtual void func1() { cout << "Base1::func1" << endl; }
	virtual void func2() { cout << "Base1::func2" << endl; }
private:
	int b1;
};

class Base2 {
public:
	virtual void func1() { cout << "Base2::func1" << endl; }
	virtual void func2() { cout << "Base2::func2" << endl; }
private:
	int b2;
};

class Derive : public Base1, public Base2 {
public:
	virtual void func1() 
	{ 
		cout << "Derive::func1" << endl;
	}

	virtual void func3() { cout << "Derive::func3" << endl; }
private:
	int d1;
};

int main()
{
	//Derive d;
	//PrintVFT((VFUNC*)(*(int*)&d));

	////PrintVFT((VFUNC*)(*(int*)((char*)&d+sizeof(Base1))));
	//Base2* ptr = &d;
	//PrintVFT((VFUNC*)(*(int*)ptr));

	Derive d;
	Base1* p1 = &d;
	p1->func1();

	Base2* p2 = &d;
	p2->func1();

	return 0;
}


//class A
//{
//public:
//  A() 
//      :m_iVal(0) 
//  { 
//      test(); 
//  }
//
//  virtual void func() 
//  { 
//      std::cout << m_iVal << ' ';
//  }
//  void test()
//  {
//      func();
//  }
//public:
//  int m_iVal;
//};
//
//
//
//class B : public A
//{
//public:
//    B() 
//    { 
//        test();
//    }
//    virtual void func()
//    {
//        ++m_iVal;
//        std::cout << m_iVal << ' ';
//    }
//
//};
//
//int main()
//{
//    A* p = new B;
//    p->test();
//
//    return 0;
//
//}