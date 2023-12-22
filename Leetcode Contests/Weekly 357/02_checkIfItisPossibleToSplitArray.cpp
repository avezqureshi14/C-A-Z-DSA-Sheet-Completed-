#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool solve(int start, int end, vector<int> nums, int currSum, int m, vector<vector<int>> &memo)
{
    if (start == end)
    {
        return true;
    }
    if (currSum < m)
    {
        return false;
    }

    if (memo[start][end] != -1)
    {
        return memo[start][end] == 1;
    }

    bool ans = solve(start + 1, end, nums, currSum - nums[start], m, memo) || solve(start, end - 1, nums, currSum - nums[end], m, memo);
    memo[start][end] = ans == false ? 0 : 1;
    return ans;
}

bool canSplitArray(vector<int> nums, int m)
{
    int n = nums.size();
    if (n < 3)
    {
        return true;
    }
    int totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        totalSum = totalSum + nums[i];
    }

    vector<vector<int>> memo(n, vector<int>(n, -1));

    return solve(0, n - 1, nums, totalSum, m, memo);
}
int main()
{
    vector<int> nums = {2, 1, 3};
    int m = 5;
    if (canSplitArray(nums, m))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}