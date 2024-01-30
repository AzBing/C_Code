#define _CRT_SECURE_NO_WARNINGS	
#include <stdio.h>


//三角形的判断
//int main() 
//{
//    int a, b, c;
//    while (scanf("%d %d %d", &a, &b, &c) != EOF)
//    {
//        if ((a + b) > c && (a + c) > b && (b + c) > a)
//        {
//            if (a == b && b == c && a == c)
//            {
//                printf("Equilateral triangle!\n");
//            }
//            else if (a == b || a == c || b == c)
//            {
//                printf("Isosceles triangle!\n");
//            }
//            else
//            {
//                printf("Ordinary triangle!\n");
//            }
//        }
//        else 
//        {
//            printf("Not a triangle!\n");
//        }
//
//    }
//    return 0;
//}



//int main() 
//{
//    int y, m, d;
//    int y1, m1, d1;
//    scanf("%d %d %d\n", &y, &m, &d);
//    scanf("%d %d %d", &y1, &m1, &d1);
//    if (y1 >= y)
//    {
//        printf("yes\n");
//    }
//    else if (y1 == y && m1 >= m)
//    {
//        printf("yes\n");
//    }
//    else if (y1 == y && m1 == m && d1 >= d) 
//    {
//        printf("yse\n");
//    }
//    else
//        printf("no\n");
//    return 0;
//}

#include <math.h>
//int main() {
//    double a, b, c;
//    while (scanf("%lf %lf %lf", &a, &b, &c) != EOF)
//    {
//        if (a != 0)
//        {
//            double disc = b * b - 4 * a * c;
//            if (disc > 0)
//            {
//                printf("x1=%.2lf;x2=%.2lf\n", (-b - sqrt(disc)) / (2 * a), (-b + sqrt(disc)) / (2 * a));
//            }
//            else if (disc < 0)
//            {
//                printf("x1=%.2lf-%.2lfi;x2=%.2lf+%.2lfi\n",
//                    (-b) / (2 * a),
//                    sqrt(-disc) / (2 * a),
//                    (-b) / (2 * a),
//                    sqrt(-disc) / (2 * a));
//            }
//            else {
//                if (b == 0)
//                {
//                    printf("x1=x2=0.00\n");
//                }
//                else {
//                    printf("x1=x2=%.2lf\n", (-b) / (2 * a));
//                }
//            }
//        }
//        else {
//            printf("Not quadratic equation\n");
//        }
//    }
//    return 0;
//}

//判断某年的某个月有多少天
//int main() 
//{
//    int y, n;
//    int arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//    while (scanf("%d %d", &y, &n) != EOF)
//    {
//        int day = arr[n - 1];
//        if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
//        {
//            if (n == 2)
//                day++;
//        }
//        printf("%d\n", day);
//    }
//    return 0;
//}

//int main()
//{
//    int a, b, c;
//    scanf("%d %d %d", &a, &b, &c);
//    if ((a + b + c) >= 180)
//    {
//        printf("NO\n");
//    }
//    else
//    {
//        printf("YES\n");
//    }
//    return 0;
//}



//int main()
//{
//    char ch[14] = { 0 };
//    int i = 0;
//    int j = 1;
//    int tmp = 0;
//    scanf("%s", ch);
//    for (i = 0; i < 11; i++)
//    {
//        if (ch[i] != '-')
//        {
//            tmp += (ch[i] - '0') * j;
//            j++;
//        }
//    }
//    int sum = tmp % 11;
//    if (sum == ch[12] - '0' || (sum == 10 && ch[12] == 'X'))
//    {
//        printf("Right\n");
//    }
//    else
//    {
//        if (sum == 10)
//        {
//            for (i = 0; i < 12; i++)
//            {
//                printf("%c", ch[i]);
//            }
//            printf("X");
//        }
//        else
//        {
//            for (i = 0; i < 12; i++)
//            {
//                printf("%c", ch[i]);
//            }
//            printf("%d", sum);
//        }
//
//    }
//    return 0;
//}



















