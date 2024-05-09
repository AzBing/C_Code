#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

//int main()
//{
//    queue<char> Q;
//    char x, y;
//    x = 'n'; y = 'g';
//    Q.push(x); Q.push('i'); Q.push(y);
//    Q.pop(); 
//    Q.push('r'); Q.push('t'); Q.push(x);
//    Q.pop(); 
//    Q.push('s');
//    while (!Q.empty())
//    {
//        x = Q.front();
//        Q.pop();
//        cout << x;
//    };
//    cout << y;
//
//}
//
//int main()
//{
//    stack<char> S;
//    char x, y;
//    x = 'n'; y = 'g';
//    S.push(x); S.push('i'); S.push(y);
//    S.pop();
//    S.push('r'); S.push('t'); S.push(x);
//    S.pop();
//    S.push('s');
//    while (!S.empty())
//    {
//        x = S.top();
//        S.pop();
//        cout << x;
//    };
//    cout << y;
//}



int mian()
{
    priority_queue<int> a;
    priority_queue<int, vector<int>, greater<int> > c;
    priority_queue<string> b;
    for (int i = 0; i < 5; i++)
    {
        a.push(i);
        c.push(i);
    }
    while (!a.empty())
    {
        cout << a.top() << ' ';
        a.pop();
    }
    cout << endl;
    while (!c.empty())
    {
        cout << c.top() << ' ';
        c.pop();
    }
    cout << endl;
    b.push("abc");
    b.push("abcd");
    b.push("cbd");
    while (!b.empty())
    {
        cout << b.top() << ' ';
        b.pop();
    }
    cout << endl;
    return 0;
}

