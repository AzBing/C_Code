#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

//int main() {
//    char arr[10001];
//    gets(arr);
//    int left = 0;
//    int right = strlen(arr) - 1;
//    while (left < right)
//    {
//        char tmp = arr[left];
//        arr[left] = arr[right];
//        arr[right] = tmp;
//        left++;
//        right--;
//    }
//    printf("%s", arr);
//    return 0;
//}

//int main()
//{
//	int a = 0;
//	int n = 0;
//	scanf("%d %d", &a, &n);
//	int i = 0;
//	int k = 0;
//	int sum = 0;
//	for (i = 0; i < n; i++)
//	{
//		k = k * 10 + a;
//		sum += k;
//	}
//	printf("%d", sum);
//	return 0;
//}

//���0��100000֮������С�ˮ�ɻ������������
//��ˮ�ɻ�������ָһ��nλ�������λ���ֵ�n�η�֮��ȷ�õ��ڸ��������� : 153��1 ^ 3��5 ^ 3��3 ^ 3����153��һ����ˮ�ɻ�������

//int main()
//{
//	int i = 0;
//	for (i = 0; i <= 100000; i++)
//	{
//		int tmp = i;
//		int n = 1;
//		int sum = 0;
//		while (tmp/10)
//		{
//			n++;
//			tmp /= 10;
//		}
//		tmp = i;
//		while (tmp)
//		{
//			sum += pow(tmp % 10, n);
//			tmp /= 10;
//		}
//		if (sum == i)
//		{
//			printf("%d ", i);
//		}
//	}
//
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//	//�ϰ벿��
//	for (i = 0; i < n; i++)
//	{
//		int j = 0;
//		for (j = 0; j < n - 1 - i; j++)
//		{
//			printf(" ");
//		}
//		for (j = 0; j < 2 * i + 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	//�°벿��
//	for (i = 0; i < n-1; i++)
//	{
//		int j = 0;
//		for (j = 0; j <= i; j++)
//		{
//			printf(" ");
//		}
//		for (j = 0; j < 2 * (n - 1 - i) - 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//
//
//	return 0;
//}

//int main()
//{
//	int money = 0;
//	scanf("%d", &money);
//	int drinks = money;
//	int bottle = money;
//
//	while (bottle >= 2)
//	{
//		drinks += bottle / 2;
//		bottle = bottle / 2 + bottle % 2;
//	}
//	printf("%d", drinks);
//	return 0;
//}

//int my_strlen(char* ps)
//{
//	int count = 0;
//	while (*ps != '\0')
//	{
//		ps++;
//		count++;
//	}
//	return count;
//}
//int main()
//{
//
//	char arr[] = { "abcedf" };
//	int tmp = my_strlen(arr);
//	printf("%d", tmp);
//
//	return 0;
//}

//void my_strcpy(char* x, const char* y)
//{
//	while (*y != '\0')
//	{
//		*x++ = *y++;
//	}
//	*x = *y;
//}
//int main()
//{
//	char arr1[] = { "**********" };
//	char arr2[] = { "abcde" };
//
//	my_strcpy(arr1, arr2);
//	printf("%s", arr1);
//	
//	return 0;
//}

//void move(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left < right)
//	{
//		while ((left < right) && (arr[left] % 2 == 1))
//		{
//			left++;
//		}
//		while ((left < right) && (arr[right] % 2 == 0))
//		{
//			right--;
//		}
//		if (left < right)
//		{
//			int tmp = arr[left];
//			arr[left] = arr[right];
//			arr[right] = tmp;
//			left++;
//			right--;
//		}
//	}
//
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	move(arr, sz);
//	for(int i=0;i<sz;i++)
//		printf("%d ", arr[i]);
//	
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int j = 0;
//	int arr[9][9] = {0};
//	for (i = 0; i < 9; i++)
//	{
//		for (j = 0; j < 9; j++)
//		{
//			arr[i][j] = 1;
//		}	
//	}
//	for (i = 1; i < 9; i++)
//	{
//		for (j = 1; j < i; j++)
//		{
//			arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
//		}
//	}
//	for (i = 0; i < 9; i++)
//	{
//
//		for (j = 0; j <= i; j++)
//		{
//			printf("%d ", arr[i][j]);
//
//		}
//		printf("\n");
//	}
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	for (n = 'a'; n <= 'd'; n++)
//	{
//		if ((n != 'a') + (n == 'c') + ( n == 'd') + (n != 'd') == 3)
//			printf("%c", n);
//
//	}
//
//	return 0;
//}

//int main()
//{
//	int a, b, c, d, e = 0;
//	for (a = 1; a <= 5; a++)
//	{
//		for (b = 1; b <= 5; b++)
//		{
//			for (c = 1; c <= 5; c++)
//			{
//				for (d = 1; d <= 5; d++)
//				{
//					for (e = 1; e <= 5; e++)
//					{
//
//						if ((b == 2) + (a == 3) == 1
//							&& (b == 2) + (e == 4) == 1
//							&& (c == 1) + (d == 2) == 1
//							&& (c == 5) + (d == 3) == 1
//							&& (e == 4) + (a == 1) == 1)
//						{
//							if ((a * b * c * d * e) == 120)
//							{
//								printf("a=%d b=%d c=%d d=%d e=%d", a, b, c, d, e);
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}

//int main()
//{
//	int a = 20;
//	int b = -10;
//
//	return 0;
//}	

//int main()
//{
//	int n = 9;
//	float* pFloat = (float*)&n;
//	printf("n��ֵΪ��%d\n", n);
//	printf("*pFloat��ֵΪ��%f\n", *pFloat);
//	*pFloat = 9.0;
//	printf("num��ֵΪ��%d\n", n);
//	printf("*pFloat��ֵΪ��%f\n", *pFloat);
//	return 0;
//}