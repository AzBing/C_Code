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
//// 函数名修饰规则
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
//	int& b = a; // 引用
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

// c语言二级指针的玩法
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

// CPP，引用的玩法
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
//	// int& b; // 引用在定义时必须初始化
//	int a = 0;
//	int& b = a;
//	int& c = a;
//	int& d = b;
//
//	int x = 1;
//	// 赋值
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
//	// 这里打印的结果可能是1，也可能是随机值
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
// 值返回
A TestFunc1() { return a; }

// 引用返回
A& TestFunc2() { return a; }

void TestReturnByRefOrValue()
{
	// 以值作为函数的返回值类型
	size_t begin1 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc1();
	size_t end1 = clock();

	// 以引用作为函数的返回值类型
	size_t begin2 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc2();
	size_t end2 = clock();

	// 计算两个函数运算完成之后的时间
	cout << "TestFunc1 time:" << end1 - begin1 << endl;
	cout << "TestFunc2 time:" << end2 - begin2 << endl;
}

// 传引用传参（任何时候都可以用）
// 1、提高效率
// 2、输出型参数（形参的修改，影响的实参）

// 传引用返回（出了函数作用域对象还在才可以用）
// 1、提高效率
// 2、修改返回对象

//struct SeqList
//{
//	int a[10];
//	int size;
//};

// C的接口设计
// 读取第i个位置的值
//int SLAT(struct SeqList* ps, int i)
//{
//	assert(i < ps->size);
//	// ...
//	return ps->a[i];
//}
// 修改第i个位置的值
//void SLModify(struct SeqList* ps, int i, int x)
//{
//	assert(i < ps->size);
//
//	// ...
//	ps->a[i] = x;
//}

// CPP接口设计

// 读 or 修改第i个位置的值
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

// 升级成了类
//#define N 10
//struct SeqList
//{
//	// 成员函数
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
//	// 成员变量
//	int a[N];
//};
//
//int main()
//{
//	//struct SeqList s1; // 兼容c的用法
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


// 在引用的过程中
// 权限可以平移
// 权限可以缩小
// 权限不能放大

int func()
{
	int a = 0;

	return a;
}

int main()
{
	const int& ret = func();

	const int a = 0;

	// 权限的放大
	// int& b = a;

	//int b = a; 可以的，因为这里是赋值拷贝，b修改不影响a

	// 权限的平移
	const int& c = a;

	// 权限的缩小
	int x = 0;
	const int& y = x;

	int i = 0;
	const double& d = i;

	return 0;
}