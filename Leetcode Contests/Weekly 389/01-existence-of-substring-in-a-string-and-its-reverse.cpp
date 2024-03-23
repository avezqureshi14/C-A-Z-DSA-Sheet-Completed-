#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool isSubstringPresent(string s)
{
    int n = s.length();
    for (int i = 0; i < n - 1; i++)
    {
        string substring = s.substr(i, 2);
        reverse(substring.begin(), substring.end());
        if (s.find(substring) != string::npos)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    string s = "abcd";
    cout << isSubstringPresent(s);
    return 0;
}