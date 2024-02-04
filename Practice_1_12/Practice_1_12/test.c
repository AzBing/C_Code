#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//int my_strlen(char* p)
//{
//	int count = 0;
//	while (*p != '\0')
//	{
//		p++;
//		count++;
//	}
//	return count;
//}
//
//int main()
//{
//	char arr[] = { "abcd" };
//	int ret = my_strlen(arr);
//	printf("%d", ret);
//
//	return 0;
//}

//int my_strlen(char* p)
//{
//	if (*p == '\0')
//	{
//		return 0;
//	}
//	return 1 + my_strlen(p + 1);
//}
//
//int main()
//{
//	char arr[] = { "abcdef" };
//	int ret = my_strlen(arr);
//	printf("%d", ret);
//
//	return 0;
//}

//void reverse_string(char arr[], int a)
//{
//	int left = 0;
//	int right = a - 1;
//
//	while (left < right)
//	{
//		char tmp = arr[right];
//		arr[right] = arr[left];
//		arr[left] = tmp;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	char arr[] = { "abcedf" };
//	int sz = sizeof(arr) / sizeof(arr[0]) - 1;
//	printf("%s\n", arr);
//	reverse_string(arr, sz);
//	printf("%s\n", arr);
//
//	return 0;
//}
//void reverse_string(char* str)
//{
//	int len = strlen(str);
//	char tmp = *str;//1
//	*str = *(str + len - 1);//2
//	*(str + len - 1) = '\0';//3
//	if (strlen(str + 1) >= 2)
//		reverse_string(str + 1);
//	*(str + len - 1) = tmp;
//}
//
//int main()
//{
//	char arr[] = { "abcdef" };
//	reverse_string(arr);
//	int sz = strlen(arr);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%c", arr[i]);
//	}
//	return 0;
//}

//int DigitSum(n)
//{
//	if (n > 9)
//		return DigitSum(n / 10) + n % 10;
//	else
//		return n;
//
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int tmp = DigitSum(n);
//	printf("%d", tmp);
//	return 0;
//}

//int Pow(int n, int k)
//{
//	if (k > 0)
//		return n * Pow(n, k - 1);
//	else if (k == 0)
//	{
//		return 1;
//	}
//}
//
//int main()
//{
//	int n = 0;
//	int k = 0;
//	scanf("%d %d", &n, &k);
//	int ret = Pow(n, k);
//	printf("%d", ret);
//	return 0;
//}
//int Fun(int tmp)
//{
//	int a = 1;
//	int b = 1;
//	if (tmp > 2)
//		return Fun(tmp - 1) + Fun(tmp - 2);
//	else
//		return 1;
//
//}
//int main()
//{
//	int tmp = 1;
//	scanf("%d", &tmp);
//	int max = Fun(tmp);
//	printf("%d", max);
//
//	return 0;
//}
//void bubbling_sort(int arr[], int x)
//{
//	int i = 0;
//	for (i = 0; i < x; i++)
//	{
//		int j = 0;
//		for (j = 0; j < x - i; j++)
//		{
//			if (arr[j] < arr[j + 1])
//			{
//				int tmp = arr[j + 1];
//				arr[j + 1] = arr[j];
//				arr[j] = tmp;
//			}
//		}
//	}
//}
//int main()
//{
//	int arr[] = { 1,3,5,7,9,0,2,4,6,8 };
//	int sz = sizeof(arr) / sizeof(arr[0]) - 1;
//	bubbling_sort(arr, sz);
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//
//	}
//	return 0;
//}

//void init(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		arr[i] = 0;
//	}
//}
//void print(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//void reverse(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left < right)
//	{
//		int tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr, sz);
//	reverse(arr, sz);
//	print(arr, sz);
//	init(arr, sz);
//	print(arr, sz);
//
//	return 0;
//}
//#include <stdlib.h>
//int main()
//{
//	char arr1[] = { "abcedf" };
//	char arr2[] = { "ghijkl" };
//	char arr3[7];
//	printf("%s\n", arr1);
//	printf("%s\n", arr2);
//	strcpy(arr3, arr1);
//	strcpy(arr1, arr2);
//	strcpy(arr2, arr3);
//	printf("%s\n", arr1);
//	printf("%s\n", arr2);
//	return 0;
//}
//int main()
//{
//    char str[] = "hello bit";
//    printf("%d %d\n", sizeof(str), strlen(str));
//    return 0;
//}
//int main()
//{
//	int a, b, c;
//	a = 5;
//	c = ++a;//6
//	b = ++c, c++, ++a, a++;// 8 8,7
//	b += a++ + c;//8+7+8
//	printf("a = %d b = %d c = %d\n", a, b, c);
//	return 0;
//}
//0111 1100 1111
//1000 1111 1011

//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int i = 31;
//	while (i >= 0)
//	{
//		printf("%d ", (a >> i) & 1);
//		i--;
//	}
//	printf("\n");
//	printf("偶数位:");
//	for (i = 30; i >= 0; i -= 2)
//	{
//		printf("%d ", (a >> i) & 1);
//	}
//	printf("\n");
//	printf("奇数位:");
//	for (i = 31; i >= 0; i -= 2)
//	{
//		printf("%d ", (a >> i) & 1);
//	}
//	return 0;
//}

//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//
//    int i = 0;
//    int count = 0;
//    for (i=0 ; i<32; i++)
//    {
//        if (((n >> i) & 1) == 1)
//            count++;
//    }
//    printf("%d", count);
//    return 0;
//}

//int main()
//{
//    int n = 10;
//    int i = 0;
//    int mask;
//    int count = 0;
//    while (i <= 31)
//    {
//        mask = 1 << i;
//        if (n & mask)
//            count++;
//        i++;
//    }
//    printf("%d", count);
//    return 0;
//}

//int main()
//{
//	int a = 10;
//	int b = 20;
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("%d %d", a, b);
//	return 0;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	a = a + b;
//	b = a - b;
//	a = a - b;
//	printf("%d %d", a, b);
//	return 0;
//}
//int i;
//int main()
//{
//    i--;
//    if (i > sizeof(i))
//    {
//        printf(">\n");
//    }
//    else
//    {
//        printf("<\n");
//    }
//    return 0;
//}
//int main()
//{
//    int i = 1;
//    int ret = (++i) + (++i) + (++i);
//    printf("ret = %d\n", ret);
//    return 0;
//}

// 1000 8
// 0111 7

// 1111 15
// 1110 14

// 1110 14
// 1101 13

// 1100 12
// 1011 11

// 1000 8
// 0111 7
 
// 0000 0

//void print(int arr[], int s)
//{
//	
//	for (int i = 0; i < s; i++)
//	{
//		printf("%d ", *(arr + i));
//		
//	}
//
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr,sz);
//
//	return 0;
//}
