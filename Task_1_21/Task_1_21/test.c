#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include <assert.h>

//int main()
//{
//	int ret = atoi("123");
//	printf("%d ", ret);
//	return 0;
//}

//ģ��ʵ��ctrcat

//char* my_strcat(char* p1, const char* p2)
//{
//
//	char* str = p1;
//	while (*p1)
//	{
//		p1++;
//	}
//	while (*p1++ = *p2++);
//
//	return str;
//}
//
//int main()
//{
//	char arr1[20] = { "hello " };
//	char arr2[] = { "world" };
//	
//	printf("%s\n",my_strcat(arr1,arr2));
//
//	return 0;
//}

//ģ��ʵ��strncat
//char* my_strcat(char* p1, const char* p2, size_t num)
//{
//
//	char* str = p1;
//
//	while (*p1)
//	{
//		p1++;
//	}
//	while (num != 0 && *p2 != '\0')
//	{
//		*p1++ = *p2++;
//		num--;
//	}
//	*p1 = '\0';
//
//	return str;
//}
//
//int main()
//{
//	char arr1[20] = { "hello " };
//	char arr2[] = { "world" };
//	
//	printf("%s\n", my_strcat(arr1, arr2,7));
//
//	return 0;
//}

//strcpy
//
//char* my_strcpy(char* dest, const char* src)
//{
//	char* ret = dest;
//	while (*dest++ = *src++);
//
//		return ret;
//}
//int main()
//{
//	char arr1[20] = { "xxxxxxxxxx" };
//	char arr2[] = { "hello" };
//
//	printf("%s\n", my_strcpy(arr1, arr2));
//	return 0;
//}

//ģ��ʵ��strncpy

//char* my_strncpy(char* dest, const char* src, size_t num)
//{
//	assert(dest && src);
//	char* ret = dest;
//	while (num-- && (*dest++ = *src++))
//	{
//		;
//
//	}
//	*dest = '\0';
//	return ret;
//}
//
//int main()
//{
//	char arr1[20] = { "xxxxxxxxxx" };
//	char arr2[] = { "hello" };
//
//	printf("%s\n", my_strncpy(arr1, arr2,3));
//	return 0;
//}

//#include <ctype.h>
//
//enum
//{
//	VALID,
//	INVALID
//}s = INVALID;
//
//int my_atoi(const char* str)
//{
//	//�����ж��Ƿ�Ϊ���ַ���/��ָ��
//	if (*str == NULL)
//	{
//		return 0;
//	}
//	if (*str == '\0')
//	{
//		return 0;
//	}
//	int flag = 1;
//	//�жϿո�
//	while (isspace(*str))
//	{
//		str++;
//	}
//	//�ж�������
//	if (*str == '+')
//	{
//		str++;
//	}
//	else if (*str == '-')
//	{
//		flag = -1;
//		str++;
//	}
//	//���������ַ�
//	long long ret = 0;
//	while (*str != '\0')
//	{
//
//		if (isdigit(*str))
//		{
//			ret = ret * 10 + (*str - '0') * flag;
//			if (ret < INT_MIN || ret > INT_MAX)
//			{
//				return (int)ret;
//			}
//		}
//		else
//		{
//			return (int)ret;
//		}
//		str++;
//
//	}
//	if (*str == '\0')
//	{
//		s = VALID;
//		return (int)ret;
//	}
//
//}
//
//int main()
//{
//	int ret = my_atoi("  -123");
//	if (s == VALID)
//	{
//		printf("�Ϸ�ת��:%d\n", ret);
//	}
//	else
//	{
//		printf("�Ƿ�ת��:%d\n", ret);
//	}
//	return 0;
//}







