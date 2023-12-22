#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int precedence(char ch)
{
    if (ch == '^')
    {
        return 3;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string infixToPostfix(string s)
{
    string result = "";
    stack<char> stk;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9')
        {
            result += ch;
        }
        else if (ch == '(')
        {
            stk.push(ch);
        }
        else if (ch == ')')
        {
            while (ch != '(')
            {
                result += stk.top();
                stk.pop();
            }
            stk.pop();
        }
        // if it is operator
        else
        {
            while (!stk.empty() && precedence(ch) <= precedence(stk.top()))
            {
                result += stk.top();
                stk.pop();
            }
            stk.push(ch);
        }
    }
    while (!stk.empty())
    {
        result += stk.top();
        stk.pop();
    }
    return result;
}

int main()
{
    string s = "a+b*c+d";
    for (auto i : infixToPostfix(s))
    {
        cout << i << " ";
    }
    return 0;
}