#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool isMatchRecur(string &s, string &p, int n, int m, vector<vector<int>> &dp)
{
    if (n < 0 && m < 0)
    {
        return true;
    }
    if (n < 0 && m >= 0)
    {
        return false;
    }
    if (n >= 0 && m < 0)
    {
        for (int i = 0; i <= n; i++)
        {
            if (s[i] != '*')
            {
                return false;
            }
        }
        return true;
    }
    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }

    if (s[n - 1] == p[m - 1] || s[n - 1] == '?')
    {
        dp[n][m] = isMatchRecur(s, p, n - 1, m - 1, dp);
        return dp[n][m];
    }
    else
    {
        if (s[n - 1] == '*')
        {
            dp[n][m] = isMatchRecur(s, p, n - 1, m, dp) || isMatchRecur(s, p, n, m - 1, dp);
            return dp[n][m];
        }
        else
        {
            dp[n][m] = false;
            return dp[n][m];
        }
    }
}
bool isMatchII(string s, string p)
{
    int n = s.length();
    int m = p.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return isMatchRecur(s, p, n, m, dp);
}
bool isMatch(string s, string p)
{
    int n = s.length();
    int m = p.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    
}
int main()
{
    string s = "*";
    string p = "aa";
    cout << isMatch(s, p);
    return 0;
}