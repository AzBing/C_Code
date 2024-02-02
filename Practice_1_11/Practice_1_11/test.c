#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//用函数来year判断是不是闰年
//int LeapYear(int year)
//{
//	int i;
//	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
//	{
//		i = 1;
//	}
//	else
//	{
//		i = 0;
//	}
//	return i;
//}
//
//int main()
//{
//	int year = 0;
//	scanf("%d", &year);
//	int tmp = LeapYear(year);
//	if (tmp != 0)
//	{
//		printf("%d是闰年", year);
//	}
//	else
//	{
//		printf("%d不是闰年",year);
//	}
//	return 0;
//}
//用函数来实现交换两个整数
//void swap(int* a, int* b)
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//
//int main()
//{
//	int x = 0;
//	int y = 0;
//	scanf("%d %d", &x, &y);
//	swap(&x, &y);
//	printf("%d %d", x, y);
//	return 0;
//}
//用函数实现9*9乘法口诀表
//void Multiply(int i)
//{
//	int x = 0;
//	int y = 0;
//	for (x = 1; x <= i; x++)
//	{
//		for (y = 1; y <= x; y++)
//		{
//			printf("%d*%d=%d ", x, y, x * y);
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int i = 0;
//	scanf("%d", &i);
//	Multiply(i);
//
//	return 0;
//}

//void Fun(int i)
//{
//	if (i > 9)
//	{
//		Fun(i / 10);
//	}
//	printf("%d ", i % 10);
//}
//int main()
//{
//	int a = 1234;
//	Fun(a);
//
//	return 0;
//}
//非递归实现
//int main()
//{
//	int i, n;
//	int k = 1;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		k *= i;
//	}
//	printf("%d ", k);
//
//	return 0;
//}
////递归实现
//int Funs(int n)
//{
//	int k = n;
//	if (n > 1)
//	{
//		k = k * Funs(n - 1);
//	}
//	return k;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = Funs(n);
//	printf("%d", ret);
//	return 0;
//}
