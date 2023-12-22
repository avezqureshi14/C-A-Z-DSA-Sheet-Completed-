#include <iostream>
#include <bits/stdc++.h>
using namespace std;

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

            if (text1[i - 1] == text2[j - 1])
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
// for no. of deletions = a.length() - LCS
// for no. of insertions = b.length() - LCS

int minOperations(string str1, string str2)
{
    int lcs = longestCommonSubsequence(str1, str2);
    int len1 = str1.length();
    int len2 = str2.length();
    int nd = len1 + len2 - 2 * lcs; // Corrected calculation
    return nd;
}

int main()
{
    string text1 = "ros";
    string text2 = "horse";
    int t1 = text1.length();
    int t2 = text2.length();
    cout << minOperations(text1, text2);
    return 0;
}