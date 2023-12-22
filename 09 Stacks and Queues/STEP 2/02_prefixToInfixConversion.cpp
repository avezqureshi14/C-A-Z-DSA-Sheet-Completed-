#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool isOperator(char ch)
{
    switch (ch)
    {
    case '*':
    case '/':
    case '+':
    case '-':
    case '%':
    case '^':
        return true;
    }
    return false;
}

string prefixToInfix(string s)
{
    stack<string> stk;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        char ch = s[i];
        if (isOperator(ch))
        {
            string op1 = stk.top();
            stk.pop();
            string op2 = stk.top();
            stk.pop();
            string temp = '(' + op1 + ch + op2 + ')';
            stk.push(temp);
        }
        else
        {
            stk.push(string(1, ch));
        }
    }
    return stk.top();
}

int main()
{
    string s = "*+AB-CD";
    for (auto i : prefixToInfix(s))
    {
        cout << i << " ";
    }
    return 0;
}