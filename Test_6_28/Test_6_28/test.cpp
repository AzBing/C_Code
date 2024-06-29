#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

// �����һ���ֻ࣬����ջ�ϴ�������
class StackOnly
{
public:
	static StackOnly CreateObj()
	{
		StackOnly obj;
		return obj;
	}

	//11��30
	//StackOnly(const StackOnly&) = delete;

	void* operator new(size_t size) = delete;

	// ʵ����ר����operator new
	// new��������ʱ��operator new�ͻ��������������ȫ�ֵ�
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
//	// ���������static_cast->�������Ƶ�����
//	double d = 12.34;
//	int a = static_cast<int>(d);
//	cout << a << endl;
//
//	// ��һ���Ĺ������������岻���Ƶĵ�������reinterpret_cast 
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
//	//  ����ת����ֱ��ת���ǲ���ȫ��
//	// ���pa��ָ����A���󣬴���Խ������
//	B* ptr = (B*)pa;
//	ptr->_a++;
//	ptr->_b++;
//}

void fun(A* pa)
{
	//  ����ת����ֱ��ת���ǲ���ȫ��
	// ���pa��ָ����A���󣬴���Խ������
	B* ptr = dynamic_cast<B*>(pa);
	if (ptr)
	{
		ptr->_a++;
		ptr->_b++;
	}
	else
	{
		cout << "ת��ʧ��" << endl;
	}
}

int main()
{
	// ����ת�����򣺸��������ת����������󣬵��Ǹ���ָ������ÿ���ת������ָ�������
	B b1;
	int x = 0;
	A a;
	int y = 0;
	B b;
	fun(&a);
	fun(&b);

	return 0;
}
