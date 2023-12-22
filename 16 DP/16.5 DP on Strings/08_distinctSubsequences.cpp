#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int numDistinctRecur(string &s, string &t, int n, int m, vector<vector<int>> &dp)
{
    if (m == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }
    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }

    if (s[n - 1] == t[m - 1])
    {
        dp[n][m] = numDistinctRecur(s, t, n - 1, m - 1, dp) + numDistinctRecur(s, t, n - 1, m, dp);
        return dp[n][m];
    }
    else
    {
        dp[n][m] = numDistinctRecur(s, t, n - 1, m, dp);
        return dp[n][m];
    }
}

int numDistinctII(string s, string t, vector<vector<int>> &dp)
{
    int n = s.length();
    int m = t.length();
    return numDistinctRecur(s, t, n, m, dp);
}
//65/66 test cases passed
int numDistinct(string s, string t)
{
    int n = s.length();
    int m = t.length();
    //if u will convert to double from int it will also be optimized 
    vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][m];
}

int main()
{
    string s = "babgbag";
    string t = "bag";
    int n = s.length();
    int m = t.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    cout << numDistinct(s, t);
    return 0;
}