#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// ( ()() )  ( () )  ( ()(()) )
string removeOuterParentheses(string s)
{
    string result;
    int index = 0;
    for (char x : s)
    {
        switch (x)
        {
        case '(':
            if (index++ > 0)
                result += x;
            break;
        case ')':
            if (index-- > 1)
                result += x;
            break;
        }
    }
    return result;
}
void printString(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        cout << s[i];
    }
}

int main()
{
    string s = "()()";
    printString(removeOuterParentheses(s));
    return 0;
}