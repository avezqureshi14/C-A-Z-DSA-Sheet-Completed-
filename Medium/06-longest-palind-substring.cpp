#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s)
{
    int n = s.length();
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

string longestPalindrome(string s)
{
    int len = INT_MIN;
    string ans;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            string substring = s.substr(i, j - i);
            if (isPalindrome(substring))
            {
                int newLen = substring.length();
                if (newLen > len)
                {
                    len = newLen;
                    ans = substring;
                }
            }
        }
    }
    return ans;
}
int main()
{
    string s = "cbbd";
    cout << longestPalindrome(s);
    return 0;
}