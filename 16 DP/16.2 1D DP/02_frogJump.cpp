#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int minimumEnergyII(vector<int> &height, int n, vector<int> &dp)
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
    int step1 = minimumEnergyII(height, n - 1, dp) + abs(height[n] - height[n - 1]);
    int step2 = INT_MAX;
    if (n > 1)
    {
        step2 = minimumEnergyII(height, n - 2, dp) + abs(height[n] - height[n - 2]);
    }
    dp[n] = min(step1, step2);
    return dp[n];
}

int minimumEnergy(vector<int> &height, int n)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    int step1 = 0;
    int step2 = 0;
    for (int i = 1; i <= n; i++)
    {
        step1 = dp[i - 1] + abs(height[i] - height[i - 1]);
        if (i > 1)
        {
            step2 = dp[i - 2] + abs(height[i] - height[i - 2]);
        }
        dp[i] = min(step1,step2);
    }

    return dp[n];
}

int main()
{
    vector<int> height = {10, 20, 30, 10};
    int n = 4;
    vector<int> dp(n + 1, -1);
    cout << minimumEnergy(height, n);
    return 0;
}