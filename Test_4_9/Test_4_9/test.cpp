#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//int main()
//{
//	//int* p1 = new int;  // �����ʼ��
//	int* p1 = new int(10); // ����һ��int����ʼ��10
//	int* p3 = new int[10]; // ����10��int������
//	int* p4 = new int[10] {1, 2, 3, 4};
//
//	int* p2 = (int*)malloc(sizeof(int));
//	if (p2 == nullptr)
//	{
//		perror("malloc fail");
//	}
//
//	return 0;
//}

class A
{
public:
	A(int a = 0)
		: _a(a)
	{
		cout << "A():" << this << endl;
	}

	~A()
	{
		cout << "~A():" << this << endl;
	}
private:
	int _a;
};

class Stack
{
public:
	Stack()
	{
		cout << "Stack()" << endl;
		_a = new int[4];
		_top = 0;
		_capacity = 4;
	}

	~Stack()
	{
		cout << "~Stack()" << endl;
		delete[] _a;
		_top = _capacity = 0;
	}

private:
	int* _a;
	int _top;
	int _capacity;
};

// ƥ��ʹ�ã���Ҫ���棬�������ǲ�ȷ��
int main()
{
	// new/delete �� malloc/free��������� new/delete���ڡ��Զ������͡����˿��ռ仹����ù��캯������������
	A* p1 = (A*)malloc(sizeof(A));
	A* p2 = new A(1);
	free(p1);
	delete p2;

	// ���������Ǽ�����һ����
	int* p3 = (int*)malloc(sizeof(int)); // C
	int* p4 = new int;
	free(p3);
	delete p4;
	//delete p3;
	//free(p4);

	A* p5 = (A*)malloc(sizeof(A)* 10);
	A* p6 = new A[10];
	delete p5;
	delete[] p6;

	return 0;
}

//int main()
//{
//	// ʧ�������쳣
//	//int* p1 = (int*)operator new(sizeof(int*));
//
//	//// ʧ�ܷ���nullptr
//	//int* p2 = (int*)malloc(sizeof(int*));
//	//if (p2 == nullptr)
//	//{
//	//	perror("malloc fail");
//	//}
//
//	// ����ռ� operator new -> ��װmalloc
//	// ���ù��캯��
//	A* p5 = new A;
//
//	// �ȵ�����������
//	// ��operator delete p5ָ��Ŀռ�
//	// operator delete -> free
//	delete p5;
//
//	// ����ռ� operator new[] ->perator new-> ��װmalloc
//	// ����10�ι��캯��
//	A* p6 = new A[10];
//	
//	// �ȵ���10����������
//	// ��operator delete[] p6ָ��Ŀռ�
//	delete[] p6;
//
//
//	int* p7 = new int[10];
//	free(p7);  // �����ͷ�
//
//	A* p8 = new A;
//	//free(p8); // �ٵ�������������
//	delete p8;
//
//	Stack st;
//
//	Stack* pst = new Stack;
//	//delete pst;
//	free(pst); // �ٵ������������� -- ���ڴ�й©
//
//	// ���ۣ�new/mallocϵ�� ���ڵײ�ʵ�ֻ����й������档��ƥ��ʹ��
//	// ���������⣬����û���⣬������һ��ƥ��ʹ��
//
//	A* p9 = new A[10];
//	//free(p9);
//	//delete p9;
//	delete[] p9;
//
//	return 0;
//}
//int main()
//{
//	size_t size = 0;
//	while (1)
//	{
//		int* p1 = (int*)malloc(1024 * 1024 * 4);
//		if (p1 == nullptr)
//		{
//			break;
//		}
//
//		size += 1024 * 1024 * 4;
//		cout << p1 << endl;
//	}
//
//	cout << size << endl;
//	cout << size / 1024 / 1024 << "MB" << endl;
//
//
//	return 0;
//}


//int main()
//{
//	size_t size = 0;
//
//	try
//	{
//		while (1)
//		{
//			int* p1 = new int[1024 * 1024 * 4];
//			size += 1024 * 1024 * 4;
//			cout << p1 << endl;
//		}
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	cout << size << endl;
//	cout << size / 1024 / 1024 << "MB" << endl;
//
//
//	return 0;
//}

//int main()
//{
//	A aa;
//
//	A* p1 = (A*)malloc(sizeof(A));
//	if (p1 == nullptr)
//	{
//		perror("malloc fail");
//	}
//
//	// ��һ�����еĿռ��ʼ�� -- ����new
//	//new(p1)A;
//	new(p1)A(1);
//
//	A* p2 = new A;
//
//	p1->~A();
//	free(p1);
//
//	delete p2;
//
//
//	return 0;
//}

//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//
//void Swap(double& left, double& right)
//{
//	double temp = left;
//	left = right;
//	right = temp;
//}