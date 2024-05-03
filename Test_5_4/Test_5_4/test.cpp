#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<deque>
#include<queue>
#include<algorithm>
using namespace std;

#include"Queue.h"



void test_queue()
{
    que::queue<int, list<int>> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{

    test_queue();

    return 0;
}