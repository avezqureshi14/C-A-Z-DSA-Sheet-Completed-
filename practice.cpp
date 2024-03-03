#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int maxSumOfNonAdjacent(int n, vector<int>nums){
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return nums[0];
    }
    int pick =  maxSumOfNonAdjacent(n-2,nums) + nums[n];
    int nonPick = maxSumOfNonAdjacent(n-1,nums);
    return max(pick,nonPick); 
}

int maxSumOfNonAdjacentII(int n, vector<int>nums, vector<int>dp){
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        dp[n] = nums[0];
        return dp[n];
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int pick = maxSumOfNonAdjacentII(n-2,nums,dp) + nums[n];
    int nonPick = maxSumOfNonAdjacentII(n-1,nums,dp);
    dp[n] = max(pick,nonPick);
    return dp[n];
}

int maxSumOfNonAdjacentIII(int n, vector<int>nums){
    vector<int>dp(n+1,-1);
    dp[0] = nums[0];
    dp[1] = nums[1];
    for (int i = 2; i <= n; i++)
    {
        int pick = dp[i-2] + nums[i];
        int nonPick = dp[i-1];
        dp[i] = max(pick,nonPick);
    }
    return dp[n];
}



int main()
{
    int n = 5;
    vector<int>nums = {1,2,3,4,5,6};
    vector<int>dp(n+1,-1);
    cout<<maxSumOfNonAdjacentIII(n,nums);

    return 0;
}