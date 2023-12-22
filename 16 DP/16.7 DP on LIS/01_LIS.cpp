#include <iostream>
#include <vector>
using namespace std;

int lengthOfLISRecur(vector<int> &nums, int n, int index, int prev, vector<int> &dp)
{
    if (index == n)
    {
        return 0;
    }
    if (dp[index] != -1)
    {
        return dp[index];
    }

    int included = 0;
    if (prev == -1 || nums[index] > nums[prev])
    {
        included = 1 + lengthOfLISRecur(nums, n, index + 1, index, dp);
    }

    int excluded = lengthOfLISRecur(nums, n, index + 1, prev, dp);

    dp[index] = max(included, excluded);
    return dp[index];
}

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1); // Memoization table
    return lengthOfLISRecur(nums, n, 0, -1, dp);
}

int main()
{
    vector<int> nums = {7, 7, 7, 7, 7, 7, 7};
    cout << lengthOfLIS(nums);
    return 0;
}
