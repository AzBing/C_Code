#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

//void Find_dog2(char arr[], int sz, int* pd1, int* pd2)
//{
//	//先将所以数字异或在一起
//	int i = 0;
//	int pos = 0;
//	int ret = 0;
//	for (i = 0; i < sz; i++)
//	{
//		ret ^= arr[i];
//	}
//	//计算ret第几位是1
//	for (i = 0; i < 32; i++)
//	{
//		if (((ret >> i) & 1) == 1)
//		{
//			pos = i;
//			break;
//		}
//	}
//	//找数组中元素的第pos位为1的异或
//	for (i = 0; i < sz; i++)
//	{
//		if (((arr[i] >> pos) & 1) == 1)
//		{
//			*pd1 ^= arr[i];
//		}
//	}
//
//	*pd2 = ret ^ *pd1;
//
//
//}
//int main()
//{
//	char arr[] = { 1,2,3,4,5,1,2,3,4,6 };
//	int dog1 = 0;
//	int dog2 = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	Find_dog2(arr, sz, &dog1, &dog2);
//	printf("%d %d", dog1, dog2);
//
//	return 0;
//}

//交换二进制位中的奇偶位

//#define SWAP(n) (n=((n&0xaaaaaaaa)>>1)+((n&0x55555555)<<1))
//
//int main()
//{
//	int n = 5;
//	SWAP(n);
//	printf("%d", n);
//
//	return 0;
//}

//struct S
//{
//	char a;
//	int b;
//	char c;
//};
//
//#define OFFSETOF(type,member) (size_t)&(((type*)0)->member)
//
//int main()
//{
//	printf("%d\n", OFFSETOF(struct S, a));
//	printf("%d\n", OFFSETOF(struct S, b));
//	printf("%d\n", OFFSETOF(struct S, c));
//
//	return 0;
//}


//int main() 
//{
//    int n = 0;
//    while (scanf("%d", &n) != EOF) 
//    {
//        int ret = 0;
//        int flag = 0;
//        float aver = 0;
//        int digit = 0;
//        while (scanf("%d", &digit) != EOF) 
//        {
//            if (digit < 0) 
//            {
//                ret++;
//            }
//            if (digit > 0) 
//            {
//                flag++;
//                aver += digit;
//            }
//        }
//        printf("%d ", ret);
//        if (flag == 0) 
//        {
//            printf("0.0\n");
//        }
//        else 
//        {
//            printf("%.1f\n", aver / flag);
//        }
//    }
//    return 0;
//}


//int momeNum(int* arr, int sz)
//{
//	int right = *arr;
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		arr++;
//		if (*arr < right)
//		{
//			right = *arr;
//		}
//		
//	}
//	return right;
//
//}
//
//int main()
//{
//	int arr[] = { 4,3 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret = momeNum(arr, sz);
//	printf("%d\n", ret);
//	return 0;
//}

//int* arr1, * arr2, i;
//arr1 = (int*)calloc(numsSize, sizeof(int));
//arr2 = (int*)malloc(sizeof(int) * 2);
//for (i = 0; i < numsSize; i++)
//{
//    arr1[nums[i] - 1] += 1;
//}
//for (i = 0; i < numsSize; i++)
//{
//    if (arr1[i] == 2)
//    {
//        arr2[0] = i + 1;
//    }
//    else if (arr1[i] == 0)
//    {
//        arr2[1] = i + 1;
//    }
//}
//*returnSize = 2;
//return arr2;

//int is_code(char arr[], int sz)
//{
//    int i = 0;
//    int count1 = 0;
//    int count2 = 0;
//    int count3 = 0;
//    if (sz < 8)
//    {
//        return 0;
//    }
//    if (arr[0] <= '9' && arr[0] >= '0')
//    {
//        return 0;
//    }
//    for (i = 0; i < sz - 1; i++)
//    {
//        if (arr[i] < '0' || arr[i]>'9' && arr[i] < 'A' || arr[i]>'Z' && arr[i] < 'a' || arr[i]>'z')
//        {
//            return 0;
//        }
//        if (arr[i] <= 'Z' && arr[i] >= 'A')
//        {
//            count1++;
//        }
//        if (arr[i] <= 'z' && arr[i] >= 'a')
//        {
//            count2++;
//        }
//        if (arr[i] >= '0' && arr[i] <= '9')
//        {
//            count3++;
//        }
//    }
//    if (count1 == sz && count2 == sz && count3 == sz)
//    {
//        return 0;
//    }
//    else
//    {
//        return 1;
//    }
//}
//
//int main() {
//    int n = 0;
//    scanf("%d", &n);
//    char arr[101] = { 0 };
//    int len = 0;
//    int ret = 0;
//    while (n)
//    {
//        scanf("%s", arr);
//        len = strlen(arr);
//        ret = is_code(arr, len);
//        if (ret == 0)
//        {
//            printf("NO\n");
//        }
//        else
//        {
//            printf("YES\n");
//        }
//        n--;
//    }
//    return 0;
//}

//int GetNumberOfK(int* nums, int numsLen, int k)
//{
//    int i = 0;
//    int count = 0;
//    for (i = 0; i < numsLen; i++)
//    {
//        if (nums[i] == k)
//        {
//            count++;
//        }
//        
//    }
//    return count;
//}
//
//int main()
//{
//    int arr[] = { 3 };
//    int k = 3;
//    int sz = sizeof(arr) / sizeof(arr[0]);
//    int ret = GetNumberOfK(arr, sz, k);
//    printf("%d\n", ret);
//    
//    return 0;
//}


//int bin_count(int a, int b)
//{
//	int count = 0;
//	int num = a ^ b;
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if ((num >> i) & 1)
//		{
//			count++;
//		}
//	}
//	return count;
//}
//int main()
//{
//	int a = 1;
//	int b = 2;
//	int ret = bin_count(a, b);
//	printf("%d\n", ret);
//	return 0;
//}

//int dominantIndex(int* nums, int numsSize) {
//    int i = 0;
//    int max = 0;
//    int del = 0;
//    int ret = 0;
//    for (i = 0; i < numsSize; i++)
//    {
//        if (nums[i] > max)
//        {
//            del = max;
//            ret = i;
//            max = nums[i];
//        }
//        else if (nums[i] > del)
//        {
//            del = nums[i];
//        }
//    }
//    if ((del * 2) <= max)
//    {
//        return ret;
//    }
//    return -1;
//}
//int main()
//{
//    int arr[] = { 1,18,7 };
//    int sz = sizeof(arr) / sizeof(arr[0]);
//    int sum = dominantIndex(arr, sz);
//    printf("%d\n", sum);
//    return 0;
//}


//#include <string.h>
//int main() {
//    char arr[1024] = { 0 };
//    while (gets(arr))
//    {
//        int i = 0;
//        int j = 0;
//        int len = strlen(arr);
//        for (i = 0; i < len; i++)
//        {
//            for (j = 1; j < len - i; j++)
//            {
//                if (arr[j] < arr[j - 1])
//                {
//                    char ch = arr[j - 1];
//                    arr[j - 1] = arr[j];
//                    arr[j] = ch;
//                }
//            }
//        }
//        printf("%s\n", arr);
//    }
//
//    return 0;
//}



//int main()
//{
//	char arr[10] = '5';
//
//
//	return 0;
//}

#include <string.h>
//int main() {
//    char arr[500] = { 0 };
//    char apy[128] = { 0 };
//    int count = 0;
//    while (scanf("%s", arr) != EOF)
//    {
//        int i = 0;
//        int sz = strlen(arr);
//        for (i = 0; i < sz; i++)
//        {
//            if (apy[arr[i]] == 0)
//            {
//                count++;
//                apy[arr[i]] = 1;
//            }
//        }
//    }
//    printf("%d", count);
//    return 0;
//}


//int majorityElement(int* nums, int numsSize) {
//    int i = 0;
//    int count = 1;
//    int tmp = nums[0];
//    for (i = 1; i < numsSize; i++)
//    {
//        if (tmp == nums[i])
//        {
//            count++;
//        }
//        else
//        {
//            count--;
//        }
//        if (count == 0)
//        {
//            tmp = nums[i+1];
//        }
//    }
//    return tmp;
//}
//
//int main()
//{
//    int arr[] = { 2,2,1,1,1,2,1 };
//    int sz = sizeof(arr) / sizeof(arr[0]);
//    int ret = majorityElement(arr, sz);
//    printf("%d\n", ret);
//    return 0;
//}


//int main()
//{
//	int a[12] = { 1,2,3,4,5,6,7,8,9,10,11,12 }, * p[4], i;
//	for (i = 0; i < 4; i++)
//		p[i] = &a[i * 3];
//	printf("%d\n",p[3][2]);
//	return 0;
//}


//int is_self_divisor(int num)
//{
//    int tmp = num;
//    while (tmp > 0)
//    {
//        int cole = tmp % 10;
//        if (cole == 0 || num % cole != 0)
//        {
//            return 0;
//        }
//        tmp /= 10;
//    }
//    return 1;
//}
//
//int* selfDividingNumbers(int left, int right, int* returnSize) {
//    int* ret = (int*)calloc(1000, sizeof(int));
//    int sum = 0;
//    for (int i = left; i <= right; i++)
//    {
//        if (is_self_divisor(i))
//        {
//            ret[sum++] = i;
//        }
//    }
//    *returnSize = sum;
//    return ret;
//}

//int main()
//{
//	int x = -1;
//	int count = 0;
//	while (x)
//	{
//		count++;
//		x = x & (x - 1);//与运算
//	}
//	printf("%d", count);
//	return 0;
//}

//int main() 
//{
//    int num = 0;
//    while (scanf("%d", &num) != EOF)
//    {
//        if (num == 0)
//        {
//            printf("%d", num % 10);
//            continue;
//        }
//        while (num > 0)
//        {
//            printf("%d", num % 10);
//            num /= 10;
//        }
//        printf("\n");
//    }
//    return 0;
//}



//int main()
//{
//    char str[10001] = { 0 };
//    int tmp = 0;
//    while (gets(str) > 0)
//    {
//        char* ptr = str;
//        char* arr[10000] = { NULL };
//        while (*ptr != '\0')
//        {
//            if (('z' >= *ptr && *ptr >= 'a') || ('Z' >= *ptr && *ptr >= 'A'))
//            {
//                arr[tmp++] = ptr;
//                while (*ptr != '\0' && (('z' >= *ptr && *ptr >= 'a') || ('Z' >= *ptr && *ptr >= 'A')))
//                {
//                    ptr++;
//                }
//                continue;
//            }
//            *ptr = '\0';
//            ptr++;
//
//        }
//        for (int i = tmp - 1; i >= 0; i--)
//        {
//            printf("%s ", arr[i]);
//        }
//        printf("\n");
//    }
//    return 0;
//}

//int main()
//{
//	int x = 2014;
//	int n = 0;
//	while (x + 1)
//	{
//		n++;
//		x = x | (x + 1);
//	}
//	printf("%d", n);
//	return 0;
//}

//int main() 
//{
//    int n;
//    while (~scanf("%d", &n))
//    {
//        int num1 = 1;
//        int num2 = 1;
//        int ret = 0;
//        for (int i = 2; i < n; i++)
//        {
//            ret = num1 + num2;
//            num1 = num2;
//            num2 = ret;
//        }
//        printf("%d\n", ret);
//
//    }
//    return 0;
//}


//int main()
//{
//	double m, n;
//	while (~scanf("%lf %lf", &n, &m)) 
//	{
//		double sum = 0;
//		while (m-- > 0) {
//			sum += n;
//			n = sqrt(n);
//		}
//		printf("%.2lf\n", sum);
//	}
//	return 0;
//}


