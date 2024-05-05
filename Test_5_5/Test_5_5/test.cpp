#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<deque>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

void test_op1()
{
    srand(time(0));
    const int N = 100000;

    deque<int> dq;
    vector<int> v;

    for (int i = 0; i < N; ++i)
    {
        auto e = rand() + i;
        v.push_back(e);
        dq.push_back(e);
    }

    int begin1 = clock();
    sort(v.begin(), v.end());
    int end1 = clock();

    int begin2 = clock();
    sort(dq.begin(), dq.end());
    int end2 = clock();

    printf("vector:%d\n", end1 - begin1);
    printf("deque:%d\n", end2 - begin2);
}

void test_op2()
{
    srand(time(0));
    const int N = 100000;

    deque<int> dq1;
    deque<int> dq2;

    for (int i = 0; i < N; ++i)
    {
        auto e = rand() + i;
        dq1.push_back(e);
        dq2.push_back(e);
    }

    int begin1 = clock();
    sort(dq1.begin(), dq1.end());
    int end1 = clock();

    int begin2 = clock();

    // vector
    vector<int> v(dq2.begin(), dq2.end());
    sort(v.begin(), v.end());
    dq2.assign(v.begin(), v.end());
    int end2 = clock();

    printf("deque sort:%d\n", end1 - begin1);
    printf("deque copy vector sort, copy back deque:%d\n", end2 - begin2);
}

int main()
{
    //test_op1();
    test_op2();


}
