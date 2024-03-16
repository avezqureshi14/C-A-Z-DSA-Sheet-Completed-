#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void recursionI(vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans, vector<int> &freq)
{
    if (ds.size() == nums.size())
    {
        ans.push_back(ds);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (freq[i] == 0)
        {
            freq[i] = 1;
            ds.push_back(nums[i]);
            recursionI(ds, nums, ans, freq);
            freq[i] = 0;
            ds.pop_back();
        }
    }
}

void recursionII(int index, vector<int> &nums, vector<vector<int>> &ans)
{
    if (index == nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[index], nums[i]);
        recursionII(index + 1, nums, ans);
        swap(nums[index], nums[i]);
    }
}
vector<vector<int>> permutation(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> ds;
    vector<int> freq(nums.size(), 0);
    // recursionI(ds,nums,ans,freq);
    recursionII(0, nums, ans);
    return ans;
}
int main()
{
    vector<int> nums = {1, 2, 3};
    for (auto i : permutation(nums))
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}