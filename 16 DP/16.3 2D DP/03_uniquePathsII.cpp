#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int utility(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &obstacleGrid)
{
    if (i < 0 || j < 0 || obstacleGrid[i][j] == 1)
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

    dp[i][j] = utility(i, j - 1, dp, obstacleGrid) + utility(i - 1, j, dp, obstacleGrid);
    return dp[i][j];
}

// recursion + memoization
int uniquePathsWithObstaclesII(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    return utility(m - 1, n - 1, dp, obstacleGrid);
}

// dp
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
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
            if (i > 0 && j > 0 && obstacleGrid[i][j] == 1)
            {
                dp[i][j] = 0;
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
    vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    cout << uniquePathsWithObstacles(obstacleGrid);
    return 0;
}