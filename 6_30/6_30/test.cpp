#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using namespace std;

//void func(int i, double d)
////int func(double d, int i)
//{
//	cout << "void func(int i, double d)" << endl;
//	//return 0;
//}
//
//void func(double d, int i)
//{
//	cout << "void func(double d, int i)" << endl;
//}
//
//// ���������ι���
//int main()
//{
//	//func(1, 1.1);   // call  _Z4funcid(?)
//
//
//	func(1.1, 1);   // call  _Z4funcdi(?)
//
//	return 0;
//}


//int main()
//{
//	int a = 0;
//	int& b = a; // ����
//
//	cout << &a << endl;
//	cout << &b << endl;
//
//	b++;
//	a++;
//
//	return 0;
//}



//  struct TreeNode {
//      int val;
//      struct TreeNode *left;
//      struct TreeNode *right;
//  };
// 
// /**
//  * Note: The returned array must be malloced, assume caller calls free().
//  */
//
//int TreeSize(struct TreeNode* root)
//{
//    if (root == NULL)
//        return 0;
//    else
//        return TreeSize(root->left) + TreeSize(root->right) + 1;
//}
//
//void _preorderTraversal(struct TreeNode* root, int* a, int& ri)
//{
//    if (root == NULL)
//        return;
//
//    printf("[%d] %d ", ri, root->val);
//    a[ri] = root->val;
//    ++ri;
//    _preorderTraversal(root->left, a, ri);
//    _preorderTraversal(root->right, a, ri);
//}
//
//int* preorderTraversal(struct TreeNode* root, int& returnSize) {
//    int size = TreeSize(root);
//    int* a = (int*)malloc(sizeof(int) * size);
//    int i = 0;
//    _preorderTraversal(root, a, i);
//
//    returnSize = size;
//
//    return a;
//}
//
//void swap(int& x1, int& x2)
//{
//    int tmp = x1;
//    x1 = x2;
//    x2 = tmp;
//}
//
//int main()
//{
//    int size;
//    preorderTraversal(nullptr, size);
//
//    int x = 0, y = 1;
//    swap(x, y);
//
//	return 0;
//}
//
//typedef struct ListNode{
//    int val;
//    struct ListNode* next;
//}ListNode, *PListNode;

// c���Զ���ָ����淨
//void PushBack(ListNode** pphead, int x)
//{
//    ListNode* newnode;
//    if (*pphead == NULL)
//    {
//        *pphead = newnode;
//    }
//    else
//    {
//
//    }
//}
//
//int main()
//{
//    ListNode* plist = NULL;
//    PushBack(&plist, 1);
//    PushBack(&plist, 2);
//    PushBack(&plist, 3);
//
//    return 0;
//}

//typedef struct ListNode {
//    int val;
//    struct ListNode* next;
//}ListNode, *PListNode;

// CPP�����õ��淨
//void PushBack(ListNode*& phead, int x)
////void PushBack(PListNode& phead, int x)
//{
//    ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
//    // ...
//    if (phead == NULL)
//    {
//        phead = newnode;
//    }
//    else
//    {
//
//    }
//}
//
//int main()
//{
//    ListNode* plist = NULL;
//    PushBack(plist, 1);
//    PushBack(plist, 2);
//    PushBack(plist, 3);
//
//    return 0;
//}

//int main()
//{
//	// int& b; // �����ڶ���ʱ�����ʼ��
//	int a = 0;
//	int& b = a;
//	int& c = a;
//	int& d = b;
//
//	int x = 1;
//	// ��ֵ
//	b = x;
//
//	return 0;
//}

//int& Count()
//{
//	int n = 0;
//	n++;
//	
//	// ...
//	return n;
//}
//
//int main()
//{
//	int ret = Count();
//	// �����ӡ�Ľ��������1��Ҳ���������ֵ
//	cout << ret << endl;
//	cout << ret << endl;
//
//
//	//int a = 0;
//	//int& b = a;
//	//int& c = a;
//	//int& d = b;
//
//	////int x = a;
//	//int x = b;
//
//
//	return 0;
//}


//int& Count()
//{
//	// int a[1000];
//	int n = 0;
//	n++;
//
//	// ...
//	return n;
//}
//
//int main()
//{
//	int& ret = Count();
//	cout << ret << endl;
//	cout << ret << endl;
//
//	return 0;
//}

//int& Add(int a, int b)
//{
//    int c = a + b;
//    return c;
//}
//
//int main()
//{
//    int& ret = Add(1, 2);
//    Add(3, 4);
//    cout << "Add(1, 2) is :" << ret << endl;
//}

#include <time.h>
struct A { int a[10000]; };

A a;
// ֵ����
A TestFunc1() { return a; }

// ���÷���
A& TestFunc2() { return a; }

void TestReturnByRefOrValue()
{
	// ��ֵ��Ϊ�����ķ���ֵ����
	size_t begin1 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc1();
	size_t end1 = clock();

	// ��������Ϊ�����ķ���ֵ����
	size_t begin2 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc2();
	size_t end2 = clock();

	// �������������������֮���ʱ��
	cout << "TestFunc1 time:" << end1 - begin1 << endl;
	cout << "TestFunc2 time:" << end2 - begin2 << endl;
}

// �����ô��Σ��κ�ʱ�򶼿����ã�
// 1�����Ч��
// 2������Ͳ������βε��޸ģ�Ӱ���ʵ�Σ�

// �����÷��أ����˺�������������ڲſ����ã�
// 1�����Ч��
// 2���޸ķ��ض���

//struct SeqList
//{
//	int a[10];
//	int size;
//};

// C�Ľӿ����
// ��ȡ��i��λ�õ�ֵ
//int SLAT(struct SeqList* ps, int i)
//{
//	assert(i < ps->size);
//	// ...
//	return ps->a[i];
//}
// �޸ĵ�i��λ�õ�ֵ
//void SLModify(struct SeqList* ps, int i, int x)
//{
//	assert(i < ps->size);
//
//	// ...
//	ps->a[i] = x;
//}

// CPP�ӿ����

// �� or �޸ĵ�i��λ�õ�ֵ
//int& SLAT(struct SeqList& ps, int i)
//{
//	assert(i < ps.size);
//	// ...
//	return (ps.a[i]);
//}

//int main()
//{
//	struct SeqList s;
//	s.size = 3;
//	// ...
//	SLAT(s, 0) = 10;
//	SLAT(s, 1) = 20;
//	SLAT(s, 2) = 30;
//	cout << SLAT(s, 0) << endl;
//	cout << SLAT(s, 1) << endl;
//	cout << SLAT(s, 2) << endl;
//
//	return 0;
//}

// ����������
//#define N 10
//struct SeqList
//{
//	// ��Ա����
//	int& at(int i)
//	{
//		assert(i < N);
//		return a[i];
//	}
//
//	int& operator[](int i)
//	{
//		assert(i < N);
//		return a[i];
//	}
//
//	// ��Ա����
//	int a[N];
//};
//
//int main()
//{
//	//struct SeqList s1; // ����c���÷�
//	SeqList s2;
//	
//	for (size_t i = 0; i < N; i++)
//	{
//		//s2.at(i) = i;
//		s2[i] = i;
//		//s2.operator[](i) = i;
//	}
//
//	for (size_t i = 0; i < N; i++)
//	{
//		//cout << s2.at(i) << " ";
//		cout << s2[i] << " ";
//	}
//	cout << endl;
//
//	return 0;
//}


// �����õĹ�����
// Ȩ�޿���ƽ��
// Ȩ�޿�����С
// Ȩ�޲��ܷŴ�

int func()
{
	int a = 0;

	return a;
}

int main()
{
	const int& ret = func();

	const int a = 0;

	// Ȩ�޵ķŴ�
	// int& b = a;

	//int b = a; ���Եģ���Ϊ�����Ǹ�ֵ������b�޸Ĳ�Ӱ��a

	// Ȩ�޵�ƽ��
	const int& c = a;

	// Ȩ�޵���С
	int x = 0;
	const int& y = x;

	int i = 0;
	const double& d = i;

	return 0;
}