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

//int main() {
//    double a, b;
//    char c;
//    while (scanf("%lf %c %lf", &a, &c, &b) != EOF) {
//        if (c != '+' && c != '-' && c != '*' && c != '/') {
//            printf("Invalid operation!\n");
//        }
//        else {
//            if (c == '/') {
//                if (b == 0.0) {
//                    printf("Wrong!Division by zero!\n");
//                }
//                else {
//                    printf("%.4lf%c%.4lf=%.4lf", a, c, b, a / b);
//                }
//            }
//            else {
//                if (c == '+') {
//                    printf("%.4lf%c%.4lf=%.4lf", a, c, b, a + b);
//                }
//                else if (c == '-') {
//                    printf("%.4lf%c%.4lf=%.4lf", a, c, b, a - b);
//                }
//                else {
//                    printf("%.4lf%c%.4lf=%.4lf", a, c, b, a * b);
//                }
//            }
//        }
//    }
//    return 0;
//}


//int main() 
//{
//    int n = 0;
//    scanf("%d", &n);
//    int i = 0;
//    int count1 = 0;
//    int count2 = 0;
//    for (i = 0; i < n; i++)
//    {
//        if (i % 2 == 0)
//        {
//            count1++;
//        }
//        else 
//        {
//            count2++;
//        }
//    }
//    printf("%d %d", count1, count2);
//    return 0;
//}

//质数
//int main() 
// {
//    int i = 0;
//    int j = 2;
//    int ret = 0;
//    for (i = 100; i < 1000; i++)
//    {
//        for (j = 2; j <= sqrt(i); j++)
//        {
//            if (i % j == 0)
//            {
//                break;
//            }
//        }
//        if (j > sqrt(i))
//        {
//            ret++;
//        }
//    }
//    printf("%d", ret);
//    return 0;
//}

//乘法口诀表
//int main() 
//{
//    int i = 0;
//    int j = 0;
//
//    for (i = 1; j <= 9; i++)
//    {
//        for (j = 1; j <= i; j++)
//        {
//            printf("%d*%d=%2d ", j, i, j * i);
//        }
//        printf("\n");
//    }
//    return 0;
//}

//int main() 
//{
//    int n = 0;
//    int ret = 0;
//    scanf("%d", &n);
//    for (int i = 1; i <= n; i++)
//    {
//        if (i % 2 == 0)
//        {
//            ret -= i;
//        }
//        else {
//            ret += i;
//        }
//
//    }
//    printf("%d", ret);
//    return 0;
//}

//int main() 
//{
//    int n = 0;
//    double sum = 0;
//    scanf("%d", &n);
//    for (int i = 1; i <= n; i++)
//    {
//        sum = sum + 1.0 / i;
//    }
//    printf("%.6lf", sum);
//    return 0;
//}


//int main() 
//{
//    int n = 0;
//    int i = 0;
//    int sum = 0;
//    double ret = 0;
//    scanf("%d", &n);
//    for (i = 1; i <= n; i++)
//    {
//        sum += pow(-1, (i - 1)) * (2 * i - 1);
//        ret += 1.0 / sum;
//    }
//    printf("%.3lf", ret);
//    return 0;
//}

//int main()
//{
//    int n = 0;
//    int count = 0;
//    scanf("%d", &n);
//    while (n != 1)
//    {
//        if (n % 2 == 0)
//        {
//            n = n / 2;
//            count++;
//            if (n == 1)
//            {
//                break;
//            }
//        }
//        else {
//            n = n * 3 + 1;
//            count++;
//        }
//    }
//    printf("%d", count);
//    return 0;
//}


//int main()
//{
//    int n = 0;
//    int i = 0;
//    int count = 0;
//    for (i = 1; i < 2020; i++)
//    {
//        n = i;
//        while (n)
//        {
//            if (n % 10 == 9)
//            {
//                count++;
//                break;
//            }
//            n /= 10;
//        }
//    }
//    printf("%d", count);
//    return 0;
//}













