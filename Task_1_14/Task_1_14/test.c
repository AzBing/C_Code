#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//int main() {
//    int n, y, r;
//    scanf("%d %d %d", &n, &y, &r);
//    int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//    int tmp = 0;
//    if ((n % 4 == 0) && (n % 100 != 0) || (n % 400 == 0))
//    {
//        arr[2] = 29;
//    }
//    for (int i = 1; i < y; i++)
//    {
//        tmp += arr[i];
//    }
//    tmp += r;
//    printf("%d", tmp);
//    return 0;
//}

//int main()
//{
//	char a[] = { "\\123456\123456\t" };
//	printf("%d", strlen(a));
//	return 0;
//}

//int f(int n)
//{
//	static int i = 1;
//	if (n >= 5)
//		return n;
//	n = n + i;
//	i++;
//	return f(n);
//	
//}
//int main()
//{
//	int a = 3;
//	printf("%d\n", (a += a -= a * a));
//	return 0;
//}

//int find_num(int arr[3][3], int * px, int * py,int k)
//{
//	int x = 0;
//	int y = *py - 1;
//	while (x <= *px - 1 && y >= 0)
//	{
//		if (k < arr[x][y])
//		{
//			y--;
//		}
//		else if (k > arr[x][y])
//		{
//			x++;
//		}
//		else
//		{
//			*px = x;
//			*py = y;
//			return 1;
//		}
//
//	}
//	*px = -1;
//	*py = -1;
//	return 0;
//
//}
//
//int main()
//{
//	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
//	int a = 3;
//	int b = 3;
//	int k = 0;
//	scanf("%d", &k);
//	int ret = find_num(arr, &a, &b, k);
//	if (ret == 1)
//	{
//		printf("%d %d", a, b);
//	}
//	else
//		printf("’“≤ªµΩ\n");
//
//	return 0;
//}

//void left_rotate(char arr[], int k)
//{
//	int sz = strlen(arr);
//	int i = 0;
//	k %= sz;
//	for (i = 0; i < k; i++)
//	{
//		//1
//		char tmp = arr[0];
//		//2
//		int j = 0;
//		for (j = 0; j < sz - 1; j++)
//		{
//			arr[j] = arr[j + 1];
//		}
//		//3
//		arr[sz - 1] = tmp;
//	}
//}
//
//
//int main()
//{
//	char arr[] = { "abcedf" };
//	int k = 0;
//	scanf("%d", &k);
//	left_rotate(arr, k);
//	printf("%s", arr);
//
//	return 0;
//}