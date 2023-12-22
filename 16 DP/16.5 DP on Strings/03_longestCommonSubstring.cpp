#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// recursion
int longestCommonSubstringIII(string S1, string S2, int n, int m, int maxLen)
{
    if (n == 0 || m == 0)
    {
        return 0;
    }
    if (S1[n - 1] == S2[m - 1])
    {
        maxLen = max(maxLen,1 + longestCommonSubstringIII(S1, S2, n - 1, m - 1, maxLen)) ;
    }
    else
    {
        return 0;
    }
}

// memoize
int longestCommonSubstringII(string S1, string S2, int n, int m, vector<vector<int>> &dp)
{
    if (n == 0 || m == 0)
    {
        return 0;
    }
    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }

    if (S1[n - 1] == S2[m - 1])
    {
        dp[n][m] = 1 + longestCommonSubstringII(S1, S2, n - 1, m - 1, dp);
        return dp[n][m];
    }
    else
    {
        dp[n][m] = 0;
        return dp[n][m];
    }
}

// dp
int longestCommonSubstr(string S1, string S2)
{
    int maxLen = 0;
    int n = S1.length();
    int m = S2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {

            if (S1[i-1] == S2[j-1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                maxLen = max(maxLen, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return maxLen;
}

int main()
{
    string S1 = "abcdefg";
    string S2 = "aefg";
    int n = S1.length();
    int m = S2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    cout << longestCommonSubstringII(S1, S2,n-1,m-1,dp);
    return 0;
}