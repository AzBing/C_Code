#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//int main() 
//{
//    int i = 0;
//    int j = 0;
//    for (i = 10000; i < 100000; i++)
//    {
//        int x = 0;
//        for (j = 10; j <= 10000; j *= 10)
//        {
//            x += (i / j) * (i % j);
//        }
//        if (x == i)
//        {
//            printf("%d ", i);
//        }
//    }
//    return 0;
//}


//int main() 
//{
//    int arr[7] = { 0 };
//    while (~scanf("%d %d %d %d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5], &arr[6])) 
//    {
//        int min = arr[0];
//        int max = arr[1];
//        for (int i = 0; i < 7; i++)
//        {
//            if (arr[i] > max)//最高分
//            {
//                max = arr[i];
//            }
//            if (arr[i] < min)//最低分
//            {
//                min = arr[i];
//            }
//        }
//        int ret = 0;
//        for (int i = 0; i < 7; i++)
//        {
//            if (arr[i]<max && arr[i] > min)
//            {
//                ret += arr[i];
//            }
//        }
//        printf("%.2lf\n", (double)ret / 5.0);
//    }
//    return 0;
//}


//将一组数字反向打印出来

//int main() 
//{
//    int n = 0;
//    scanf("%d", &n);
//    while (n)
//    {
//        printf("%d", n % 10);
//        n /= 10;
//    }
//
//    return 0;
//}

//int main()
//{
//    int n;
//    int arr[100] = { 0 };
//    int count = 0;
//    scanf("%d", &n);
//
//    while (n)
//    {
//        count++;
//        arr[count] = n % 6;
//        n /= 6;
//    }
//
//    for (int i = count; i > 0; i--)
//    {
//        printf("%d", arr[i]);
//    }
//
//    return 0;
//}

//int main()
//{
//    int n = 0;//发放金币天数
//    int a = 0;
//    int sum = 0;//收到金币数
//    scanf("%d", &n);
//    int i = 0;
//    for (i = 0;; i++)
//    {
//        int j = 0;
//        for (j = 1; j <= i; j++)
//        {
//            sum += i;
//            a++;
//            if (a == n)
//                break;
//        }
//        if (a == n)
//            break;
//    }
//    printf("%d\n", sum);
//    return 0;
//}

<<<<<<< HEAD
//������
=======
//回文数
>>>>>>> be59ccb464a728cabb553f8230defa66a4f9b4ee
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    for (int i = 1; i < n; i++)
//    {
//        int tmp = 0;
//        int sum = i;
//        while (sum)
//        {
//            tmp = tmp * 10 + sum % 10;
//            sum /= 10;
//        }
//        if (tmp == i)
//        {
//            printf("%d\n", i);
//        }
//    }
//    return 0;
//}

//int main() 
//{
//    int n = 0;
//    while (~scanf("%d\n", &n))
//    {
//        for (int i = 0; i < n; i++)
//        {
//            printf("*");
//        }
//        printf("\n");
//    }
//    return 0;
//}

//int main()
//{
//    int n = 0;
//    while (~scanf("%d", &n))
//    {
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                printf("* ");
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}
//int main()
//{
//    int n = 0;
//    while (~scanf("%d", &n))
//    {
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j <= i; j++)
//            {
//                 printf("* ");
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}

//int main()
//{
//    int n = 0;
//    while (~scanf("%d", &n))
//    {
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < n - i; j++)
//            {
//                printf("* ");
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}

//int main()
//{
//    int n = 0;
//    while (~scanf("%d", &n))
//    {
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < n - i; j++)
//            {
//                printf("  ");
//            }
//            for (int j = 0; j <= i; j++)
//            {
//                printf("* ");
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}

//int main()
//{
//    int n = 0;
//    while (~scanf("%d", &n))
//    {
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < n - i - 1; j++)
//            {
//                printf(" ");
//            }
//            for (int j = 0; j <= i; j++)
//            {
//                printf("* ");
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}

//int main()
//{
//    int n = 0;
//    while (~scanf("%d", &n))
//    {
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < i; j++)
//            {
//                printf(" ");
//            }
//            for (int j = 0; j < n - i; j++)
//            {
//                printf("* ");
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}


//int main()
//{
//    int n = 0;
//    while (~scanf("%d", &n))
//    {
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < n - i; j++)
//            {
//                printf(" ");
//            }
//            for (int j = 0; j <= i; j++)
//            {
//                printf("* ");
//            }
//            printf("\n");
//        }
//        for (int i = 0; i < n + 1; i++)
//        {
//            for (int j = 0; j < i; j++)
//            {
//                printf(" ");
//            }
//            for (int j = 0; j < n + 1 - i; j++)
//            {
//                printf("* ");
//            }
//            printf("\n");
//        }
//
//    }
//    return 0;
//}

//int main()
//{
//    int n = 0;
//    while (~scanf("%d", &n))
//    {
//        for (int i = 0; i <= n; i++)
//        {
//            for (int j = 0; j <= n - i; j++)
//            {
//                printf("* ");
//            }
//            for (int j = 0; j < i; j++)
//            {
//                printf(" ");
//            }
//            printf("\n");
//        }
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < i+2; j++)
//            {
//                printf("* ");
//            }
//            for (int j = 0; j <= i; j++)
//            {
//                printf(" ");
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}

//int main()
//{
//    int n = 0;
//    while (~scanf("%d", &n))
//    {
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < n - i; j++)
//            {
//                printf("  ");
//            }
//            for (int j = 0; j < i + 1; j++)
//            {
//                printf("*");
//            }
//            printf("\n");
//        }
//        for (int i = 0; i < n + 1; i++)
//        {
//            for (int j = 0; j < i; j++)
//            {
//                printf("  ");
//            }
//            for (int j = 0; j < n + 1 - i; j++)
//            {
//                printf("*");
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}

//int main()
//{
//    int n = 0;
//    while (~scanf("%d", &n))
//    {
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < i; j++)
//            {
//                printf(" ");
//            }
//            for (int j = 0; j < n - n + 1; j++)
//            {
//                printf("*");
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}

//int main()
//{
//    int n = 0;
//    while (~scanf("%d", &n))
//    {
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < n - i - 1; j++)
//            {
//                printf(" ");
//            }
//            for (int j = 0; j < n - n + 1; j++)
//            {
//                printf("*");
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}

//int main() 
//{
//    int n = 0;
//    int x = 0;
//    int count = 0;
//    scanf("%d %d", &n, &x);
//    for (int i = 1; i <= n; i++)
//    {
//        int ret = i;
//        while (ret)
//        {
//            if (ret % 10 == x)
//            {
//                count++;               
//            }
//            ret /= 10;
//        }
//    }
//    printf("%d\n", count);
//    return 0;
//}

//int main()
//{
//    int arr[10] = { 0 };
//    for (int i = 0; i < 10; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    for (int i = 9; i >= 0; i--)
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}

//int main()
//{
//    int n = 0;
//    scanf("%d\n", &n);
//    int arr[50] = { 0 };
//    int ret = 0;
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%d", &arr[i]);
//        ret += arr[i];
//    }
//    printf("%d", ret);
//    return 0;
//}

//int main()
//{
//    int n = 0;
//    scanf("%d\n", &n);
//    int arr[20] = { 0 };
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    int ret1 = arr[0];
//    int ret2 = arr[1];
//    for (int i = 0; i < n; i++)
//    {
//        if (arr[i] > ret2)
//        {
//            ret2 = arr[i];
//        }
//        else if (arr[i] < ret1)
//        {
//            ret1 = arr[i];
//        }
//    }
//    printf("%d", ret2 - ret1);
//    return 0;
//}


//int main() {
//    int n = 0;
//    scanf("%d", &n);
//    int arr[6] = { 0 };
//    int i = 0;
//    int j = 0;
//    int ret = 0;
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < n - 1 - i; j++)
//        {
//            if (arr[j] < arr[j + 1])
//            {
//                ret = arr[j + 1];
//                arr[j + 1] = arr[j];
//                arr[j] = ret;
//            }
//        }
//    }
//    for (i = 0; i < 5; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}
<<<<<<< HEAD




=======
>>>>>>> be59ccb464a728cabb553f8230defa66a4f9b4ee




