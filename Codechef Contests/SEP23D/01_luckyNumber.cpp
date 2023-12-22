#include <iostream>
#include <bits/stdc++.h>
using namespace std;
char luckyNumber(string s)
{
    int n = s.length();
    char ans = '\0';
    for (int i = 0; i < n; i++)
    {
        if (i == 6)
        {
            ans = s[i];
            break;
        }
    }
    return ans;
}
int main()
{
    string s;
    int n = 10;
    for (int i = 0; i < n; i++)
    {
        char ch;
        cin>>ch;
        s.push_back(ch);
    }
    cout << luckyNumber(s);
    return 0;
}