#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<deque>
#include<stack>
#include<queue>
#include<algorithm>
#include<array>
using namespace std;

#include"Priority_queue.h"

template<class T>
class Less
{
public:
    bool operator()(const T& x, const T& y)
    {
        return x < y;
    }
};

template<class T>
class Greater
{
public:
    bool operator()(const T& x, const T& y)
    {
        return x > y;
    }
};

void test_priority_queue()
{
    // 插入删除数据效率 logN
    //pq::priority_queue<int> q; // 大堆
    //pq::priority_queue<int, vector<int>, less<int>> q; // 大堆
    pq::priority_queue<int, vector<int>, greater<int>> q; // 小堆

    q.push(3);
    q.push(1);
    q.push(5);
    q.push(4);

    //pq::priority_queue<int> copy(q);

    while (!q.empty())
    {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;

    int a[] = { 1,2,6,2,1,5,9,4 };
    sort(a, a + 8, greater<int>());
    //greater<int> gt;
    //sort(a, a + 8, gt);
}

template<class T>
void Func(T x)
{
    cout << x << endl;
}

template<class T>
class A
{
private:
    T _a;
};

//int main()
//{
//    Func(1);
//    A<int> aa;
//
//    //vector<string> v = { "4","13","5","/","+" };
//    //cout << Solution().evalRPN(v) << endl;
//    //test_op1();
//    //test_op2();
//    //test_queue();
//
//    test_priority_queue();
//
//    //Less<int> less1; // 函数对象
//    //cout << less1(2, 3) << endl;
//    //cout << less1.operator()(2, 3) << endl;
//
//    //Less<double> less2; // 函数对象
//    //cout << less2(2.2, 3.3) << endl;
//
//	return 0;
//}

class Date
{
public:
    Date(int year = 1900, int month = 1, int day = 1)
        : _year(year)
        , _month(month)
        , _day(day)
    {}

    bool operator<(const Date& d) const
    {
        return (_year < d._year) ||
            (_year == d._year && _month < d._month) ||
            (_year == d._year && _month == d._month && _day < d._day);
    }

    bool operator>(const Date& d) const
    {
        return (_year > d._year) ||
            (_year == d._year && _month > d._month) ||
            (_year == d._year && _month == d._month && _day > d._day);
    }

    friend ostream& operator<<(ostream& _cout, const Date& d);
private:
    int _year;
    int _month;
    int _day;
};

ostream& operator<<(ostream& _cout, const Date& d)
{
    _cout << d._year << "-" << d._month << "-" << d._day;
    return _cout;
}

struct PDateCompare
{
    bool operator()(Date* p1, Date* p2)
    {
        return *p1 > *p2;
    }
};

//int main()
//{
//    pq::priority_queue<Date> q1;
//    q1.push(Date(2018, 10, 29));
//    q1.push(Date(2018, 10, 28));
//    q1.push(Date(2018, 10, 30));
//    cout << q1.top() << endl;
//
//    pq::priority_queue<Date*, vector<Date*>, PDateCompare> q2;
//    q2.push(new Date(2018, 10, 29));
//    q2.push(new Date(2018, 10, 28));
//    q2.push(new Date(2018, 10, 30));
//    cout << *(q2.top()) << endl;
//
//    return 0;
//}

//#define N 10000

// 类型模板参数
// 非类型模板参数 -- 只支持整形
template<class T, size_t N>
class Stack
{

private:
    T _a[N];
};

//int main()
//{
//    Stack<int, 10> st1;     // 10
//    Stack<double, 10000> st2;  // 10000
//
//    // C++11初衷期望大家去替代静态数组
//    // 鸡肋
//    array<int, 10> a1;
//    int a2[10];
//    cout << sizeof(a1) << endl;
//    cout << sizeof(a2) << endl;
//
//    a2[15] = 1; // 本质是指针解引用
//    //a1[15] = 1; // 本质是一个函数调用
//
//    vector<int> v(10, 0);
//
//
//    //int n;
//    //cin >> n;
//    //Stack<double, n> st3;
//
//    return 0;
//}

// 模板特化：针对某些类型进行特殊化处理
template<class T1, class T2>
class Data
{
public:
    Data() { cout << "Data<T1, T2>" << endl; }
private:
    T1 _d1;
    T2 _d2;
};

// 特化 -- 全特化
template<>
class Data<int, double>
{
public:
    Data() { cout << "Data<int, double>" << endl; }
};

// 偏特化
template<class T1>
class Data<T1, double>
{
public:
    Data() { cout << "Data<T1, double>" << endl; }
};


template<class T1, class T2>
class Data<T1*, T2*>
{
public:
    Data() { cout << "Data<T1*, T2*>" << endl; }
private:
    T1 _d1;
    T2 _d2;
};

//Data<int, int> d1;
//Data<int, double> d2;
//Data<double, double> d3;

//template<class T>
//class Less
//{
//public:
//    bool operator()(const T& x, const T& y)
//    {
//        return x < y;
//    }
//};

// 特化一下  当T是Date*时，进行特殊处理，按指向的对象比较
//template<>
//class Less<Date*>
//{
//public:
//    bool operator()(Date* x, Date* y)
//    {
//        return *x < *y;
//    }
//};

template<class T>
class Less<T*>
{
public:
    bool operator()(T* x, T* y)
    {
        return *x < *y;
    }
};

int main()
{
    Data<int, int> d1;
    Data<int, double> d2;
    Data<double, double> d3;
    Data<double*, double*> d4;
    Data<int*, double*> d5;

    pq::priority_queue<Date*> q2;
    q2.push(new Date(2018, 10, 29));
    q2.push(new Date(2018, 10, 28));
    q2.push(new Date(2018, 10, 30));
    cout << *(q2.top()) << endl;


    return 0;
}
