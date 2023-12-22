#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// recursion
int longestCommonSubsequenceIII(string text1, string text2, int t1, int t2)
{
    if (t1 == 0 || t2 == 0)
    {
        return 0;
    }
    if (text1[t1 - 1] == text2[t2 - 1])
    {
        return 1 + longestCommonSubsequenceIII(text1, text2, t1 - 1, t2 - 1);
    }
    else
    {
        return max(longestCommonSubsequenceIII(text1, text2, t1 - 1, t2), longestCommonSubsequenceIII(text1, text2, t1, t2 - 1));
    }
}

// memoize
int longestCommonSubsequenceII(string text1, string text2, int t1, int t2, vector<vector<int>> &dp)
{
    if (t1 == 0 || t2 == 0)
    {
        return 0;
    }
    if (dp[t1][t2] != -1)
    {
        return dp[t1][t2];
    }

    if (text1[t1 - 1] == text2[t2 - 1])
    {
        dp[t1][t2] = 1 + longestCommonSubsequenceII(text1, text2, t1 - 1, t2 - 1, dp);
        return dp[t1][t2];
    }
    else
    {
        dp[t1][t2] = max(longestCommonSubsequenceII(text1, text2, t1 - 1, t2, dp), longestCommonSubsequenceII(text1, text2, t1, t2 - 1, dp));
        return dp[t1][t2];
    }
}

// dp
int longestCommonSubsequence(string text1, string text2)
{
    int t1 = text1.length();
    int t2 = text2.length();
    vector<vector<int>> dp(t1 + 1, vector<int>(t2 + 1, -1));
    for (int i = 0; i <= t1; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= t2; j++)
    {
        dp[0][j] = 0;
    }
    for (int i = 1; i <= t1; i++)
    {
        for (int j = 1; j <= t2; j++)
        {

            if (text1[i-1] == text2[j-1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[t1][t2];
}

int main()
{
    string text1 = "babgbag";
    string text2 = "bag";
    int t1 = text1.length();
    int t2 = text2.length();
    vector<vector<int>> dp(t1 + 1, vector<int>(t2 + 1, -1));
    cout << longestCommonSubsequence(text1, text2);
    return 0;
}