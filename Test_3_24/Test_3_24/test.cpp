#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//int main()
//{
//	int a = 1;
//
//
//	cout << a << endl;
//	return 0;
//}
// C++兼容c语法
//#include<stdio.h>
//
//int main()
//{
//	printf("hello world\n");
//
//	return 0;
//}

//#include <iostream>
////using namespace std;
//
//int main()
//{
//	std::cout << "hello world" << std::endl;
//
//	//printf("hello world\n");
//
//	return 0;
//}

//#include<stdio.h>
//#include <stdlib.h>
//
//// 我们自己定义和库里面的名字冲突
//// 项目组，多个人之间定义的名字冲突
//int rand = 10;
//
//// C语言没办法解决类似这样的命名冲突问题，所以C++提出了namespace来解决
//int main()
//{
//	printf("%d\n", rand);
//
//	return 0;
//}


//#include<stdio.h>
//#include <stdlib.h>
//
//// 域
//// 局部域/全局域：1、使用  2、生命周期
////int a = 2;
//
//void f1()
//{
//	int a = 0;
//	printf("%d\n", a);
//	printf("%d\n",::a);  // ::域作用限定符
//}
//
//void f2()
//{
//	int a = 1;
//}
//
//int main()
//{
//	printf("%d\n", a);
//	f1();
//
//	return 0;
//}

//#include "List.h"
//#include "Queue.h"
//
////int main()
////{
////	struct AQueue::Node node1;
////	struct BList::Node node2;
////
////	AQueue::min++;
////	BList::min++;
////
////
////
////	return 0;
////}
//
//int main()
//{
//	struct bit::A::Node node1;
//	struct bit::B::Node node2;
//
//	bit::A::min++;
//	bit::B::min++;
//
//	return 0;
//}

//#include <iostream>
//#include "Queue.h"
//using namespace bit;
////using namespace std;
//
//// 1、指定命名空间访问
//// 2、全局展开. 一般情况，不建议全局展开的。
//// 3、部分
//
//int main()
//{
//	struct Queue q;
//	QueueInit(&q);
//	QueuePush(&q, 1);
//	QueuePush(&q, 2);
//
//	std::cout << "1111";
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//// 实际开发的项目工程
//// 1、指定命名空间访问
//// 3、常用部分展开
//
//// 小的程序，日常练习，不太会出现冲突
//// 2、全局展开.一般情况，不建议全局展开的。
//
//// 常用展开
//using std::cout;
//using std::endl;
//
//
//int main()
//{
//	cout << "1111" << endl;
//	cout << "1111" << endl;
//	cout << "1111" << endl;
//	cout << "1111" << endl;
//
//	int i = 0;
//	std::cin >> i;
//
//	return 0;
//}


#include<iostream>
using namespace std;

//int main()
//{
//	// << 流插入
//	// endl '\n'
//	cout << "hello world" << endl;
//	cout << "hello world" << '\n';
//
//	// 自动识别类型
//	//int n = 0;
//	//cin >> n;
//
//	//double* a = (double*)malloc(sizeof(double)*n);
//	//if (a == NULL)
//	//{
//	//	perror("malloc fail");
//	//	exit(-1);
//	//}
//
//	//for (int i = 0; i < n; ++i)
//	//{
//	//	cin >> a[i];
//	//}
//
//	//for (int i = 0; i < n; ++i)
//	//{
//	//	//cout << a[i] << " ";
//	//	printf("%.2f ", a[i]);
//	//}
//	//cout << endl;
//
//	char name[10] = "张三";
//	int age = 18;
//	//...
//
//	cout << "姓名：" << name << endl;
//	cout << "年龄：" << age << endl;
//
//	printf("姓名：%s\n年龄：%d\n", name, age);
//
//	return 0;
//}

//////////////////////////////////////////////////////////////////////

//void Func(int a = 0)
//{
//	cout << a << endl;
//}
//
//int main()
//{
//	Func(1);
//	Func();
//
//	return 0;
//}

// 全缺省
//void Func(int a = 10, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//	cout << endl;
//}
//
//int main()
//{
//	// 使用缺省值，必须从右往左连续使用
//	Func(1, 2, 3);
//	Func(1, 2);
//	Func(1);
//	Func();
//
//	//Func(,2,);
//	//Func(, , 3);
//
//	return 0;
//}

// 半缺省
// 必须从右往左连续缺省
void Func(int a, int b = 10, int c = 20)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}

struct Stack
{
	int* a;
	int top;
	int capacity;
};

void StackInit(struct Stack* ps, int defaultCapacity = 4)
{
	ps->a = (int*)malloc(sizeof(int) * defaultCapacity);
	if (ps->a == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	ps->top = 0;
	ps->capacity = defaultCapacity;
}

int main()
{
	// 使用缺省值，必须从右往左连续使用
	Func(1, 2, 3);
	Func(1, 2);
	Func(1);

	Stack st1; // 最多要存100个数
	StackInit(&st1, 100);

	Stack st2; // 不知道多少数据
	StackInit(&st2);

	return 0;
}

