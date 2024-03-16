#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void recurPerm(vector<int> &ds, vector<vector<int>> &ans, vector<int> &nums, vector<int> &freq)
{
    if (ds.size() == nums.size())
    {
        ans.push_back(ds);
        return;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (!freq[i])
        {
            ds.push_back(nums[i]);
            freq[i] = 1;
            recurPerm(ds, ans, nums, freq);
            freq[i] = 0;
            ds.pop_back();
        }
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<int> freq(nums.size(), 0);
    vector<int> ds;
    vector<vector<int>> ans;
    recurPerm(ds, ans, nums, freq);
    return ans;
}
int main()
{
    vector<int> nums = {1, 2, 3};
    for (auto i : permute(nums))
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}