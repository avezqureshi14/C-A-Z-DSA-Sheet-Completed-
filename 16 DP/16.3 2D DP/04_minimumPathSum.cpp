#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int utilityFunc(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
    {
        return 1e9;
    }

    if (i == 0 && j == 0)
    {
        return grid[0][0];
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int up = grid[i][j] + utilityFunc(grid, i - 1, j, dp);
    int left = grid[i][j] + utilityFunc(grid, i, j - 1, dp);

    dp[i][j] = min(up, left);
    return dp[i][j];
}
// recursion + memoization
int minPathSumII(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    return utilityFunc(grid, m - 1, n - 1, dp);
}

// dp
int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = grid[0][0];
            }
            else
            {

                int up = grid[i][j];
                if (i > 0)
                {
                    up += dp[i - 1][j];
                }
                else
                {
                    up += 1e9;
                }
                int left = grid[i][j];
                if (j > 0)
                {
                    left += dp[i][j - 1];
                }
                else
                {
                    left += 1e9;
                }
                dp[i][j] = min(up, left);
            }
        }
    }
    return dp[m - 1][n - 1];
}
int main()
{
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << minPathSum(grid);
    return 0;
}