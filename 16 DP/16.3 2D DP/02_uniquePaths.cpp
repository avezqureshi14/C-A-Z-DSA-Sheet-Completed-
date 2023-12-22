#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int utility(int i, int j, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
    {
        return 0;
    }
    if (i == 0 && j == 0)
    {
        return 1;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    dp[i][j] = utility(i, j - 1, dp) + utility(i - 1, j, dp);
    return dp[i][j];
}

// recursion + memoization
int uniquePathsII(int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    return utility(m - 1, n - 1, dp);
}

// dp
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
                continue;
            }
            int up = 0;
            int left = 0;
            if (i > 0)
            {
                up = dp[i - 1][j];
            }
            if (j > 0)
            {
                left = dp[i][j - 1];
            }
            dp[i][j] = up + left;
        }
    }

    return dp[m - 1][n - 1];
}
int main()
{
    int m = 3;
    int n = 3;
    cout << uniquePaths(m, n);
    return 0;
}