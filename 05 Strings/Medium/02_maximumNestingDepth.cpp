#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int maxDepth(string s)
{
    int n = s.length();
    int count = 0;
    int maxCount = 0;
    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        if (ch == '(')
        {
            count++;
            maxCount = max(maxCount, count);
        }
        else if (ch == ')')
        {
            count--;
        }
    }
    return maxCount;
}
int main()
{
    string s = "(1)+((2))+(((3)))";
    cout<<"Maximum nexting Depth is "<<maxDepth(s);
    return 0;
}