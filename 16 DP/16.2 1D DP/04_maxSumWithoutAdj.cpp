#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int findMaxSumIII(int *arr, int n, vector<int> &dp)
{
    if (n == 0)
    {
        return arr[0];
    }
    if (n < 0)
    {
        return 0;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int include = arr[n] + findMaxSumIII(arr, n - 2, dp);
    int exclude = 0 + findMaxSumIII(arr, n - 1, dp);
    dp[n] = max(include, exclude);
    return dp[n - 1];
}

int findMaxSumII(int *arr, int n)
{
    vector<int> dp(n + 1, -1);
    dp[0] = arr[0];
    int include = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        if (i > 1)
        {
            include = arr[i] + dp[i - 2];
        }
        int exclude = 0 + dp[i - 1];
        dp[i] = max(include, exclude);
    }
    return dp[n - 1];
}
int findMaxSum(int *arr, int n)
{
  int prev = arr[0];
    int prev2 =0;
    
    for(int i=1; i<n; i++){
        int pick = arr[i];
        if(i>1)
            pick += prev2;
        int nonPick = 0 + prev;
        
        int cur_i = max(pick, nonPick);
        prev2 = prev;
        prev= cur_i;
        
    }
    return prev;
}

int main()
{
    int arr[] = {1,5,3};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> dp(n + 1, -1);
    cout << findMaxSumIII(arr, n,dp);
    return 0;
}