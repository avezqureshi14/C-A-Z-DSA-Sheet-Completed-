#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(int index, vector<int> nums, int k, vector<int> ds, vector<int> &ans, int sum)
{
    if (index == nums.size())
    {
        if (sum == k)
        {
            for (auto i : ds)
            {
                ans.push_back(i);
            }
            //no use of this -1 i have just leave one line
            ans.push_back(-1);
        }
        return;
    }

    ds.push_back(nums[index]);
    sum = sum + nums[index];
    solve(index + 1, nums, k, ds, ans, sum);

    sum = sum - nums[index];
    ds.pop_back();
    solve(index + 1, nums, k, ds, ans, sum);
}

vector<int> subsequenceWithSumK(vector<int> nums, int k)
{
    int sum = 0;
    int index = 0;
    vector<int> ds;
    vector<int> ans;

    solve(index, nums, k, ds, ans, sum);
    return ans;
}
int main()
{
    vector<int> nums = {1,0,1,0,1};
    int k = 2;
    for (auto i : subsequenceWithSumK(nums, k))
    {
        if (i == -1)
        {
            cout <<endl;
        }
        else
        {
            cout << i << " ";
        }
    }
    return 0;
}
