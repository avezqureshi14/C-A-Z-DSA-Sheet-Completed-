#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(int index, vector<vector<int>> &ans, vector<int> &ds, vector<int> &nums)
{
    // here we have to push each value , previously we were pushing the value when it was satisfying the condition
    ans.push_back(ds);
    for (int i = index; i < nums.size(); i++)
    {
        if (i != index && nums[i] == nums[i - 1])
            continue;
        ds.push_back(nums[i]);
        solve(i + 1, ans, ds, nums);
        ds.pop_back();
    }
}

vector<vector<int>> subSetsII(vector<int> &nums)
{
    int index = 0;
    vector<vector<int>> ans;
    vector<int> ds;
    sort(nums.begin(), nums.end());
    solve(index, ans, ds, nums);
    return ans;
}

int main()
{
    vector<int> candidates = {4, 4, 4, 1, 4};

    vector<vector<int>> result = subSetsII(candidates);

    for (auto i : result)
    {
        cout << "{ ";
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << "}, ";
    }

    return 0;
}
