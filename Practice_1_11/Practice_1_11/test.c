#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//�ú�����year�ж��ǲ�������
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
//		printf("%d������", year);
//	}
//	else
//	{
//		printf("%d��������",year);
//	}
//	return 0;
//}
//�ú�����ʵ�ֽ�����������
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
//�ú���ʵ��9*9�˷��ھ���
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
//�ǵݹ�ʵ��
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
////�ݹ�ʵ��
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
