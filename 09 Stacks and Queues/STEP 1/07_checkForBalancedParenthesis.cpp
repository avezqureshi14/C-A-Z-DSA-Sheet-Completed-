#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool isValidParenthesis(string s)
{
    stack<char> stk;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '{' || ch == '[')
        {
            stk.push(ch);
        }
        else
        {
            if (!stk.empty())
            {
                char top = stk.top();
                if (top == '(' && ch == ')' ||
                    top == '{' && ch == '}' ||
                    top == '[' && ch == ']')
                {
                    stk.pop();
                }
            }
            else
            {
                return false;
            }
        }
    }

    if (stk.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    string s = "{})[]";
    if (isValidParenthesis(s))
    {
        cout << "Yeah";
    }
    else
    {
        cout << "Nope";
    }
    return 0;
}