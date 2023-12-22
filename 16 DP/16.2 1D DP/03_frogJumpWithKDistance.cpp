#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int minimizeCostII(vector<int> &height, int n, int k, vector<int> &dp, int minSteps = INT_MAX)
{
    if (n == 0)
    {
        dp[0] = 0;
        return dp[0];
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    for (int i = 1; i <= k; i++)
    {
        if (n - i >= 0)
        {
            int jumps = minimizeCostII(height, n - i, k, dp) + abs(height[n] - height[n - i]);
            minSteps = min(minSteps, jumps);
        }
    }
    dp[n] = minSteps;
    return dp[n];
}

int minimizeCost(vector<int> &height, int n, int k)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int minSteps = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                int jumps = dp[i - j] + abs(height[i] - height[i - j]);
                minSteps = min(minSteps, jumps);
            }
        }
        dp[i] = minSteps;
    }
    return dp[n-1];
}

int main()
{
    vector<int> height = {10, 30, 40, 50, 20};
    int n = 5;
    vector<int> dp(n + 1, -1);
    cout << minimizeCost(height, n, 3);
    return 0;
}