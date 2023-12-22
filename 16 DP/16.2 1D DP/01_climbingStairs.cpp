#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int countWaysII(int n, vector<int> &dp)
{
    if (n == 0)
    {
        dp[0] = 1;
        return dp[0]; // Base case: There's one way to reach 0.
    }
    if (n < 0)
    {
        return 0; // Base case: There are no ways to reach negative numbers.
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = countWaysII(n - 1, dp) + countWaysII(n - 2, dp);
    return dp[n];
}

long long int mod = 1e9 + 7;
int countWays(int n)
{
    // your code here
    int dp[n];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 1] % mod + dp[i - 2] % mod) % mod;
    }
    return dp[n] % mod;
}

int main()
{
    int n = 84;
    vector<int> dp(n + 1, -1);
    cout << countWays(n) << endl;
    return 0;
}
