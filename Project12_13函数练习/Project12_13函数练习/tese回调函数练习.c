#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//void menu()
//{
//	printf("***********************************\n");
//	printf("******* 1.�ӷ�        2.���� *******\n");
//	printf("******* 3.�˷�        4.���� *******\n");
//	printf("************* 0.�˳� ***************\n");
//	printf("***********************************\n");
//}
//
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	int ret = 0;
//	int (*Aparr[])(int, int) = { 0, Add,Sub,Mul,Div };
//
//	do
//	{
//		menu();
//		printf("��ѡ��");
//		scanf("%d", &input);
//		if (input == 0)
//		{
//			printf("�˳�����\n");
//		}
//		if (input >= 1 && input <= 4)
//		{
//			printf("������������:>");
//			scanf("%d %d", &x, &y);
//			ret = Aparr[input](x, y);
//			printf("%d\n", ret);
//
//		}
//		else
//		{
//			printf("ѡ�����,����ѡ��\n");
//		}
//
//	} while (input);
//
//	return 0;
//}


//#include <stdlib.h>
//#include <string.h>
//ð������

//qsort
//int cmp_int(const void* e1, const void* e2)
//{
//	return (*(int*)e1 - *(int*)e2);
//}
//
//struct Stu
//{
//	char name[20];
//	int age;
//};
//int cmp_stu_by_name(const void* e1, const void* e2)
//{
//	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
//}

//void Swap(char* sude1, char* sude2,int width)
//{
//	int i = 0;
//	for (i = 0; i < width; i++)
//	{
//		char tmp = *sude1;
//		*sude1 = *sude2;
//		*sude2 = tmp;
//		*sude1++;
//		*sude2++;
//	}
//}
//
//void bubble_sort(void* base, int sz, int width, int(*cmp)(const void* e1, const void* e2))
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
//			{
//				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
//
//			}
//		}
//	}
//
//}
//void tese1()
//{
//	//int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	struct Stu s[] = { {"zhangshan",20},{"lisi",15},{"wangwu",30} };
//	int sz = sizeof(s) / sizeof(s[0]);
//
//	//bubble_sort(arr, sz);
//	qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
//
//}
//void tese2()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//int main()
//{
//	//tese2();
//	tese1();
//
//	return 0;
//}

#include <assert.h>
//ģ��ʵ�ֿ⺯��strlen
//int my_strlen(const  char *arr)
//{
//	int count = 0;
//	assert(arr);
//
//	while (*arr != '\0')
//	{
//		*arr++;
//		count++;
//	}
//	return count;
//}
//int main()
//{
//
//	char arr[] = "abcdef";
//	int tmp = my_strlen(arr);
//	printf("%d", tmp);
//	return 0;
//}
//ģ��ʵ�ֿ⺯��strcpy
//char* my_strcpy(char* arr1, const char* arr2)
//{
//	assert(arr2);
//	char* p = arr1;
//	while (*arr2 != '\0')
//	{
//		*arr1 = *arr2;
//		arr2++;
//		arr1++;
//	}
//	return p;
//}
//int main()
//{
//	char arr1[] = "xxxxxxxxxx";
//	char arr2[] = "abcde";
//	my_strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}
//ģ��ʵ�ֿ⺯��strcmp

//ģ��ʵ�ֿ⺯��strcat

//ģ��ʵ�ֿ⺯��strstr