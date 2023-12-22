#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(vector<char> &nums, vector<char> &output, int index, vector<vector<char>> &ans)
{
    // base case
    if (index >= nums.size())
    {
        if (output.size() == 3)
        {
            ans.push_back(output);
        }

        return;
    }

    // include
    char element = nums[index];
    output.push_back(element);
    solve(nums, output, index + 1, ans);

    // exclude
    output.pop_back();
    solve(nums, output, index + 1, ans);
}

vector<vector<char>> subsets(vector<char> &nums)
{
    vector<vector<char>> ans;
    vector<char> output;
    int index = 0;
    solve(nums, output, index, ans);
    return ans;
}
int main()
{
    vector<char> nums = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for (auto i : subsets(nums))
    {
        cout << "{ ";
        for (auto j : i) 
        {
            cout << j << " ";
        }
        cout << "} , ";
    }
    return 0;
}
