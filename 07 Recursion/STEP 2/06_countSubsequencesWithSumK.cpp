#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solve(int index, vector<int> nums, int k, int sum)
{
    if (index == nums.size())
    {
        if (sum == k)
        {
            return 1;
        }
        return 0;
    }
    sum = sum + nums[index];
    int left = solve(index + 1, nums, k, sum);

    sum = sum - nums[index];
    int right = solve(index + 1, nums, k, sum);

    return left + right;
}

int countSubsequencesWithSumK(vector<int> nums, int k)
{
    int index = 0;
    int sum = 0;
    return solve(index,nums,k,sum);
}

int main()
{
    vector<int> nums = {1, 2, 1};
    int k = 2;
    cout << "The count of Subsequences is " << countSubsequencesWithSumK(nums, k);
    return 0;
}