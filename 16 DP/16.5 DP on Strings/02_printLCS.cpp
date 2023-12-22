#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// dp
vector<string> all_longest_common_subsequences(string text1, string text2)
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

    int i = t1;
    int j = t2;
    string ans = "";
    while (i > 0 && j > 0)
    {
        if (dp[i - 1] == dp[j - 1])
        {
            for (auto k : dp[i - 1])
            {
                ans.push_back(k);
            }
            i--;
            j--;
        }
        else
        {
        }
    }
}

int main()
{
    string text1 = "abcde";
    string text2 = "ace";
    all_longest_common_subsequences(text1, text2);
    return 0;
}