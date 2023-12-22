#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(int index, int sum, vector<vector<int>> &ans, vector<int> &ds, vector<int> &nums, int target)
{
    if (sum == target)
    {
        if (sum == target)
        {
            ans.push_back(ds);
        }
        return;
    }

    for (int i = index; i < nums.size(); i++)
    {
        if (i != index && nums[i] == nums[i - 1])
            continue; //this moves the code to the next iteration without excecuting the remaining code

        sum += nums[i];
        ds.push_back(nums[i]);
        solve(i + 1, sum, ans, ds, nums, target);
        sum -= nums[i];
        ds.pop_back();
    }
}

vector<vector<int>> combinationSumII(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    int index = 0;
    int sum = 0;
    vector<vector<int>> ans;
    vector<int> ds;
    solve(index, sum, ans, ds, candidates, target);
    return ans;
}

int main()
{
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    vector<vector<int>> result = combinationSumII(candidates, target);

    for (const auto &comb : result)
    {
        cout << "{ ";
        for (const auto &num : comb)
        {
            cout << num << " ";
        }
        cout << "}, ";
    }

    return 0;
}
