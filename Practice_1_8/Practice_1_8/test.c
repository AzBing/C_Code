#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//����n�Ľ׳�
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


//����1!+2!+3!+4!+5!+6!..+n!
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


//���δӴ�С����
//int main()
//{
//	int a, b, c = 0;
// ��ȡÿ��ֵ
//	scanf("%d %d %d", &a, &b, &c);
// �Ƚ�������
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
// ���������
//	printf("%d %d %d\n",a, b, c);
//
//	return 0;
//}
//��ӡ1-100֮��3�ı���
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
//��ʮ���������ֵ
//int main()
//{
//	int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
//	int i = 0;
// ѭ������ÿ����
//	for (i = 0; i < 10; i++)
//	{
		//�Ƚ�ÿ����
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
//��100��200֮�������
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
//1000��2000��֮�������
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
//����1/1-1/2+1/3-1/4+1/5-1/6...1/99-1/100
// ����1
//int main()
//{
//	double max = 0;
//	int i = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		//�ж�����������ż��
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
//����2
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


//�������������Լ��
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


//��д������һ�� 1�� 100 �����������г��ֶ��ٸ�����9
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
//����Ļ�����9 * 9�˷��ھ���


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
//���ֲ��ң������
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
//			printf("�ҵ����±���:%d\n", mid);
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
//		printf("û�ҵ�\n");
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

//��������Ϸ
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
//		printf("�������:>");
//		scanf("%d", &max);
//		if (max > ret)
//		{
//			printf("�´���\n");
//		}
//		else if (max < ret)
//		{
//			printf("��С��\n");
//		}
//		else
//		{
//			printf("��ϲ��¶���\n");
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
//		printf("��ѡ��:>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("�˳���Ϸ\n");
//			break;
//		default:
//			printf("ѡ�����������ѡ��\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}
