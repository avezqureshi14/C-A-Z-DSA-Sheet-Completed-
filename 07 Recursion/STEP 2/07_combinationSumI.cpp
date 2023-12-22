#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> nums, vector<vector<int>> &ans, int index, int k, vector<int> ds, int target)
{
    if (index == nums.size())
    {
        if (target == 0)
        {
            ans.push_back(ds);
        }
        return;
    }

    if (nums[index] <= target)
    {
        ds.push_back(nums[index]);
        solve(nums, ans, index, k, ds, target - nums[index]);
        ds.pop_back();
    }

    solve(nums, ans, index + 1, k, ds, target);
}

vector<vector<int>> combinationSumI(vector<int> nums, int k)
{
    int index = 0;
    vector<vector<int>> ans;
    vector<int> ds;
    int target = k;
    solve(nums, ans, index, k, ds, target);
    return ans;
}

int main()
{
    vector<int> nums = {2, 3, 6, 7};
    int k = 7;
    for (auto i : combinationSumI(nums, k))
    {
        cout << "{ ";
        for (auto j : i)
        {
            cout << j << ",";
        }
        cout << " }, ";
    }
    return 0;
}