#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool solve(int index, vector<int> nums, int k, int sum, vector<int> &ans, vector<int> ds)
{
    if (index == nums.size())
    {
        if (sum == k)
        {
            for (auto i : ds)
            {
                ans.push_back(i);
            }
            return true;
        }
        return false;
    }

    ds.push_back(nums[index]);
    sum = sum + nums[index];
    if (solve(index + 1, nums, k, sum, ans, ds))
    {
        return true;
    }

    sum = sum - nums[index];
    ds.pop_back();
    if (solve(index + 1, nums, k, sum, ans, ds))
    {
        return true;
    }

    return false;
}

vector<int> oneSubsequenceWithSumK(vector<int> nums, int k)
{
    int index = 0;
    vector<int> ans;
    vector<int> ds;
    int sum = 0;
    solve(index, nums, k, sum, ans, ds);
    return ans;
}

int main()
{

    vector<int> nums = {1, 2, 1};
    int k = 2;
    for (auto i : oneSubsequenceWithSumK(nums, k))
    {
        cout << i <<" ";
    }

    return 0;
}