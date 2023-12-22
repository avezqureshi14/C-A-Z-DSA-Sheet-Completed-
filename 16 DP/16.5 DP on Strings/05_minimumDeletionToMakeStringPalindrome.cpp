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

int longestPalinSubseq(string A)
{
    string Ar = A;
    reverse(Ar.begin(), Ar.end());
    return longestCommonSubsequence(A, Ar);
}

int minInsertions(string s){
    int len = s.length();
    int lps = longestPalinSubseq(s);
    return len - lps;
}

int main()
{
    string text1 = "bbabcbcab";
    cout << longestPalinSubseq(text1);
    return 0;
}