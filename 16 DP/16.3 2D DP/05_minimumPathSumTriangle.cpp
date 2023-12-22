#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int utilityFunc(vector<vector<int>> &triangle, int i, int j, int n, vector<vector<int>> &dp)
{
    if (i == n - 1)
    {
        return triangle[i][j];
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int d = triangle[i][j] + utilityFunc(triangle, i + 1, j, n, dp);
    int dg = triangle[i][j] + utilityFunc(triangle, i + 1, j + 1, n, dp);
    dp[i][j]=min(d, dg);
    return dp[i][j];
}

int minimumTotalII(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return utilityFunc(triangle, 0, 0, n, dp);
}
int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    
}
int main()
{
    vector<vector<int>> traingle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << minimumTotal(traingle);
    return 0;
}