#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//int main()
//{
//	int m, n;
//	printf("Enter m,n;\n");
//	scanf("%d%d", &m, &n);
//	while (m != n)           //1
//	{
//		while (m > n)m = m - n; //2
//		while (n > m)n = n - m; //3
//	}
//	printf("m=%d\n", m);
//	return 0;
//}


//int main()
//{
//	char c;
//	int v0 = 0, v1 = 0, v2 = 0;
//		do
//		{
//			switch (c = getchar())
//			{
//			case'a':case'A':
//			case'e':case'E':
//			case'i':case'I':
//			case'o':case'O':
//			case'u':case'U':v1 += 1;
//			default: v0 += 1; v2 += 1;
//			}
//		} while (c != '\n');
//		printf("v0=%d,v1=%d,v2=%d\n", v0, v1, v2);
//
//	return 0;
//}


//int main()
//{
//	int n = 4;
//	int i = 0;
//	int j = 0;
//	int tmp = 0;
//	for (i = 0; i < n - 1; i++)
//	{
//		for (j = n; j > i; j--)
//		{
//			tmp++;
//		}
//	}
//	printf("%d", tmp);
//	return 0;
//}


//int main()
//{
//	int a = 1;
//	for (int i = 0; i || i++ < 5;)
//	{
//		a++;
//	}
//	printf("%d", a);
//	return 0;
//}
//int fun(int x)
//{
//	return (x == 1) ? 1 : (x + fun(x - 1));
//}
//
//int main()
//{
//	int x = 10;
//	int tmp = fun(x);
//	printf("%d", tmp);
//	return 0;
//}

////模拟实现strlen
//#include <assert.h>
//int my_strlen(const char* str)
//{
//	assert(str);
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//
//int my_strlen(const char* str)
//{
//	assert(str);
//	while (*str != '\0')
//	{
//		return 1 + my_strlen(str + 1);
//	}
//	return 0;
//}


//int my_strlen(const char* str)
//{
//	assert(str);
//	char* ps = str;
//	while (*ps != '\0')
//	{
//		ps++;
//	}
//	return(ps - str);
//}
//
//int main()
//{
//	char arr1[] = { "abcdef" };
//	int sz = my_strlen(arr1);
//	printf("%d", sz);
//	return 0;
//}

////模拟实现strcpy
//char my_strcpy(char* arr1, const char* arr2)
//{
//	assert(arr1 && arr2);
//	char* ps = arr1;
//	while (*arr1++ = *arr2++)
//	{
//		;
//	}
//	return ps;
//}
//
//int main()
//{
//	char arr1[] = { "xxxxxxxxxx" };
//	char arr2[] = { "abc def" };
//	my_strcpy(arr1, arr2);
//	printf("%s", arr1);
//
//	return 0;
//}

////模拟实现strcat
//char* my_strcat(char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	char* ps = str1;
//	while (*str1)
//	{
//		str1++;
//	}
//	while (*str1++ = *str2++)
//	{
//		;
//	}
//	return ps;
//}
//
//int main()
//{
//	char arr1[20] = { "hello " };
//	char arr2[] = { "world" };
//	my_strcat(arr1, arr2);
//	printf("%s", arr1);
//	return 0;
//}

////模拟实现strcmp
//
//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//			return 0;
//
//		str1++;
//		str2++;
//	}
//	return (*str1 - *str2);
//}
//
//int main()
//{
//	int sz = my_strcmp("aaab", "aaac");
//	printf("%d", sz);
//	return 0;
//}

////模拟实现strstr
//char* my_strstr(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	char* cp = str1;
//	char* s2 = str2;
//	char* s1 = cp;
//	while (*cp)
//	{
//		s1 = cp;
//		s2 = str2;
//		while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//		{
//			return cp;
//		}
//
//		cp++;
//	}
//	return NULL;
//}
//
//int main()
//{
//	char arr1[] = "abcccdef";
//	char arr2[] = "ccde";
//	char* ret = my_strstr(arr1, arr2);
//	if (ret != NULL)
//	{
//		printf("%s\n",ret);
//	}
//	else
//		printf("找不到\n");
//
//	return 0;
//}


////模拟实现memmove
//void* my_memmove(void* dest, const void* src, size_t num)
//{
//	char* tmp = dest;
//	if (dest < src)
//	{
//		//从前向后拷贝
//		while(num--)
//		{
//			*((char*)dest) = *((char*)src);
//			dest = (char*)dest + 1;
//			src = (char*)src + 1;
//		}
//	}
//	else
//	{
//		//从后向前拷贝
//		while (num--)
//		{
//			*((char*)dest + num) = *((char*)src + num);
//
//		}
//	}
//	return tmp;
//}
//
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//	my_memmove(arr1 + 2, arr1, 20);
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	return 0;
//}


////模拟实现memcpy
//void* my_memcpy(void* dest, const void* src, size_t num)
//{
//	char* tmp = dest;
//	while (num--)
//	{
//		*((char*)dest) = *((char*)src);
//		dest = (char*)dest + 1;
//		src = (char*)src + 1;
//	}
//	
//	return tmp;
//}
//
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[] = { 2,3,4,5,6,7 };
//	my_memcpy(arr1, arr2, 20);
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	return 0;
//}