#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//计算n的阶乘
//int main()
//{
//	int n = 0;
//	int i = 0;
//	int ret = 1;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		ret = ret * i;
//		
//	}
//	printf("%d ", ret);
//	return 0;
//}


//计算1!+2!+3!+4!+5!+6!..+n!
//int main()
//{
//	int n = 0;
//	int i = 0;
//	int ret = 1;
//	int sum = 0;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		ret *= i;
//		sum += ret;
//	}
//	printf("%d ", sum);
//	return 0;
//}


//依次从大到小排序
//int main()
//{
//	int a, b, c = 0;
// 获取每个值
//	scanf("%d %d %d", &a, &b, &c);
// 比较三个数
//	if (a < b)
//	{
//		int tmp = a;
//		a = b;
//		b = tmp;
//	}
//	if (a < c)
//	{
//		int tmp = a;
//		a = c;
//		c = tmp;
//	}
//	if (b < c)
//	{
//		int tmp = b;
//		b = c;
//		c = tmp;
//	}
// 最后进行输出
//	printf("%d %d %d\n",a, b, c);
//
//	return 0;
//}
//打印1-100之间3的倍数
//int main()
//{
//	int i = 0;
//	for (i = 1; i < 100; i++)
//	{
//		if (i % 3 == 0)
//		{
//			printf("%d ", i);
//
//		}
//	}
//
//	return 0;
//}


//int main()
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		if (i = 5)
//			printf("%d ", i);
//	}
//	return 0;
//}


//int main() {
//	int x = 3;
//	int y = 3;
//	switch (x % 2) {
//	case 1:
//		switch (y)
//		{
//		case 0:
//			printf("first");
//		case 1:
//			printf("second");
//			break;
//		default: printf("hello");
//		}
//	case 2:
//		printf("third");
//	}
//	return 0;
//}
//求十个数中最大值
//int main()
//{
//	int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
//	int i = 0;
// 循环遍历每个数
//	for (i = 0; i < 10; i++)
//	{
		//比较每个数
//		if (arr[i] < arr[i + 1])
//		{
//			arr[i]++;
//		}
//		else
//		{
//			printf("%d", arr[i]);
//			break;
//		}
//	}
//	return 0;
//}
//求100到200之间的素数
//int main()
//{
//	int i = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		int j = 0;
//		for (j = 2; j < i; j++)
//		{
//			if (i % j == 0)
//			{
//				break;
//			}
//		}
//		if (i == j)
//		{
//			printf("%d ", i);
//		}
//	}
//
//	return 0;
//}
//1000到2000年之间的闰年
//int main()
//{
//
//	int i = 0;
//	for (i = 1000; i <= 2000; i++)
//	{
//		if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
//		{
//			printf("%d ", i);
//
//		}
//
//	}
//
//	return 0;
//}
//计算1/1-1/2+1/3-1/4+1/5-1/6...1/99-1/100
// 方案1
//int main()
//{
//	double max = 0;
//	int i = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		//判断是奇数还是偶数
//		if (i % 2 == 0)
//		{
//			max -= 1.0 / i;
//		}
//		else
//		{
//			max += 1.0 / i;
//		}
//	}
//	printf("%lf ", max);
//
//	return 0;
//}
//方案2
//int main()
//{
//	double sum = 0;
//	int flag = 1;
//	double i = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		sum += (1 / i) * (flag);
//		flag = -flag;
//	}
//	printf("%lf ", sum);
//
//	return 0;
//}


//求两个数中最大公约数
//int main()
//{
//	int a, b = 0;
//	int tmp = 0;
//	scanf("%d %d", &a, &b);
//	while (tmp = a % b)
//	{
//		a = b;
//		b = tmp;
//
//	}
//	printf("%d ", b);
//	return 0;
//}


//编写程序数一下 1到 100 的所有整数中出现多少个数字9
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i / 10 == 9 || i % 10 == 9)
//		{
//			count++;
//		}
//	}
//	printf("%d", count);
//	return 0;
//}
//在屏幕上输出9 * 9乘法口诀表


//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 1; i < 10; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%2d ", i, j, i * j);
//
//		}
//		printf("\n");
//	}
//
//	return 0;
//}
//二分查找，有序版
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int right = sizeof(arr) / sizeof(arr[0]) - 1;
//	int left = 0;
//	int k = 9;
//	int flag = 0;
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] == k)
//		{
//			flag = 1;
//			printf("找到了下标是:%d\n", mid);
//			break;
//		}
//		else if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			right = mid - 1;
//		}
//	}
//	if (flag == 0)
//	{
//		printf("没找到\n");
//	}
//	return 0;
//}


//int is_prime(int x, int y)
//{
//	for (x = 100; x <= y; x++)
//	{
//		int j = 0;
//		for (j = 2; j < x; j++)
//		{
//			if (x % j == 0)
//			{
//				break;
//			}
//		}
//		if (x == j)
//		{
//			printf("%d ", x);
//		}
//	}
//}
//	
//int main()
//{
//	int i = 100;
//	int j = 200;
//	
//
//	int tmp = is_prime(i, j);
//	return 0;
//}

//猜数字游戏
//void meun()
//{
//	printf("*******************\n");
//	printf("** 1.play 0.exit **\n");
//	printf("*******************\n");
//}
//
//void game()
//{
//	int ret = rand(NULL) % 100 + 1;
//
//	int max = 0;
//
//	while (1)
//	{
//		printf("请猜数字:>");
//		scanf("%d", &max);
//		if (max > ret)
//		{
//			printf("猜大了\n");
//		}
//		else if (max < ret)
//		{
//			printf("猜小了\n");
//		}
//		else
//		{
//			printf("恭喜你猜对了\n");
//			break;
//		}
//	}
//}
//
//int main()
//{
//	int input = 0;
//	srand((unsigned int)rand(NULL));
//	do
//	{
//
//		meun();
//		printf("请选择:>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("退出游戏\n");
//			break;
//		default:
//			printf("选择错误，请重新选择\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}
