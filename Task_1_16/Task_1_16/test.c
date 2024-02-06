#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


////排序整形类型
//int cmp_int(const void* p1, const void* p2)
//{
//	return (*(int *)p1 - *(int *)p2);
//}
//test1()
//{
//	int arr[] = { 1,3,5,7,9,0,2,4,6,8 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//	
//}
//
////按年龄排序结构体
//struct Stu
//{
//	char name[10];
//	int age;
//};
//
//int cmp_stu_age(const void* p1, const void* p2)
//{
//	return ((struct Stu*)p1)->age - ((struct Stu*)p2)->age;
//}
//
//test2()
//{
//	struct Stu arr[] = { {"zhang",21},{"wang",15},{"li",27} };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), cmp_stu_age);
//
//}
////按名字排序结构体
//int cmp_stu_name(const void* a1,const void* a2)
//{
//	return strcmp(((struct Stu*)a1)->name, ((struct Stu*)a2)->name);
//}
//test3()
//{
//	struct Stu arr[] = { {"zhang",21},{"wang",15},{"li",27} };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), cmp_stu_name);
//
//}
//int main()
//{
//	//test1();
//	//test2();
//	test3();
//
//	return 0;
//}

//模拟实现qsort函数
//int cmp_int(const void* s1, const void* s2)
//{
//	return (*(int*)s1 - *(int*)s2);
//}
//
//void Swap(char* buf1, char* buf2, int size)
//{
//	int i = 0;
//	char tmp = 0;
//	for (i = 0; i < size; i++)
//	{
//		tmp = *buf1;
//		*buf1 = *buf2;
//		*buf2 = tmp;
//		*buf1++;
//		*buf2--;
//	}
//}
//void my_qsort(void* base, int num, int size, int (*cmp)(const void*, const void*))
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < num - 1; i++)
//	{
//		for (j = 0; j < num - 1 - i; j++)
//		{
//			if (cmp((char*)base + j * size, (char*)base + (j + 1) * size) > 0)
//			{
//				Swap((char*)base + j * size, (char*)base + (j + 1) * size, size);
//			}
//		}
//	}
//}
//
//test1()
//{
//	int arr[] = { 1,3,5,7,9,0,2,4,6,8 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	my_qsort(arr, sz, sizeof(arr[0]), cmp_int);
//
//}
//
//int main()
//{
//	test1();
//
//	return 0;
//}

//int is_left_move(char arr1[], char arr2[])
//{
//	int len = strlen(arr1);
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		int j = 0;
//		char tmp = arr1[0];
//		for (j = 0; j < len - 1; j++)
//		{
//			arr1[j] = arr1[j + 1];
//		}
//		arr1[len - 1] = tmp;
//		if (strcmp(arr2, arr1) == 0)
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
//
//int main()
//{
//	char arr1[] = { "abcdef" };
//	char arr2[] = { "defabc" };
//	int tmp = is_left_move(arr1, arr2);
//	if (tmp == 1)
//	{
//		printf("OK\n");
//	}
//	else
//	{
//		printf("NO\n");
//	}
//
//
//	return 0;
//}






