#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <deque>
#include <queue>
using namespace std;
#include "stack.h"


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        //bit::stack<int, vector<int>> st;
        //bit::stack<int, list<int>> st;
        sta::stack<int> st;

        for (auto& str : tokens)
        {
            if (str == "+"
                || str == "-"
                || str == "*"
                || str == "/")
            {
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();
                switch (str[0])
                {
                case '+':
                    st.push(left + right);
                    break;
                case '-':
                    st.push(left - right);
                    break;
                case '*':
                    st.push(left * right);
                    break;
                case '/':
                    st.push(left / right);
                    break;
                }
            }
            else
            {
                st.push(stoi(str));
            }
        }

        return st.top();
    }
};

int main()
{
    vector<string> v = { "4","13","5","/","+" };
    cout << Solution().evalRPN(v) << endl;



}
