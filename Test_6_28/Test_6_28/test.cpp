#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

// 请设计一个类，只能在栈上创建对象
class StackOnly
{
public:
	static StackOnly CreateObj()
	{
		StackOnly obj;
		return obj;
	}

	//11：30
	//StackOnly(const StackOnly&) = delete;

	void* operator new(size_t size) = delete;

	// 实现类专属的operator new
	// new这个类对象时，operator new就会调用这个，不会调全局的
	/*void* operator new(size_t size)
	{
		cout << "void* operator new(size_t size)" << endl;
		return malloc(size);
	}*/
private:
	StackOnly()
	{
		cout << "StackOnly()" << endl;
	}
};

//int main()
//{
//	StackOnly obj = StackOnly::CreateObj();
//	//StackOnly* ptr = new StackOnly;
//
//	//StackOnly* ptr = new StackOnly(obj);
//
//	//int i = (int)obj;
//
//	return 0;
//}

//int main()
//{
//	// 相近类型用static_cast->意义相似的类型
//	double d = 12.34;
//	int a = static_cast<int>(d);
//	cout << a << endl;
//
//	// 有一定的关联，但是意义不相似的的类型用reinterpret_cast 
//	int* ptr = reinterpret_cast<int*>(a);
//
//	return 0;
//}

//void main()
//{
//	volatile const int a = 2;
//	//int* p = const_cast<int*>(&a);
//	int* p = (int*)&a;
//	*p = 3;
//
//	cout << a << endl;
//	cout << *p << endl;
//
//	cout << &a << endl;
//	cout << typeid(&a).name() << endl;
//	cout << (void*)&a << endl;
//	printf("%p\n", &a);
//	cout << p << endl;
//
//	char ch = 'x';
//	cout << (void*)&ch << endl;
//}

//void insert(size_t pos, char ch)
//{
//	int end = 10;
//	while (end >= pos)
//	{
//		cout << end << endl;
//		--end;
//	}
//}
//
//int main()
//{
//	insert(5, 'x');
//	insert(0, 'x');
//
//	return 0;
//}

class A
{
public:
	virtual void f() {}

	int _a = 0;
};

class B : public A
{

public:
	int _b = 1;
};

//int main()
//{
//	B objb;
//	A obja = objb;
//	A& ra = objb;
//
//	double d = 1.1;
//	const int& i = d;
//
//	return 0;
//}

//void fun(A* pa)
//{
//	//  向下转换：直接转换是不安全的
//	// 如果pa是指向父类A对象，存在越界问题
//	B* ptr = (B*)pa;
//	ptr->_a++;
//	ptr->_b++;
//}

void fun(A* pa)
{
	//  向下转换：直接转换是不安全的
	// 如果pa是指向父类A对象，存在越界问题
	B* ptr = dynamic_cast<B*>(pa);
	if (ptr)
	{
		ptr->_a++;
		ptr->_b++;
	}
	else
	{
		cout << "转换失败" << endl;
	}
}

int main()
{
	// 向下转换规则：父类对象不能转换成子类对象，但是父类指针和引用可以转换子类指针和引用
	B b1;
	int x = 0;
	A a;
	int y = 0;
	B b;
	fun(&a);
	fun(&b);

	return 0;
}
