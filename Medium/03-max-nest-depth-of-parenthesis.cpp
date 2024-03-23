#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int maxDepth(string s)
{
    int n = s.length();
    stack<char> stk;
    int ans = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        if (ch == '(')
        {
            count++;
            ans = max(ans, count);
        }
        else if (ch == ')')
        {
            count--;
            ans = max(ans, count);
        }
    }
    return ans;
}
int main()
{
    string s = "(1)+((2))+(((3)))0";
    cout << maxDepth(s);
    return 0;
}