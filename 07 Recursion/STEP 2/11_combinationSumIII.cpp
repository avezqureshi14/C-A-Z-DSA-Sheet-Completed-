#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(int index, int sum,int n, int k, vector<vector<int>>&ans, vector<int>&ds, vector<int>&nums){
    if (index == nums.size())
    {
        if (sum == n && ds.size() == k)
        {
            ans.push_back(ds);
        }
        return;
    }

    sum = sum + nums[index];
    ds.push_back(nums[index]);
    solve(index+1,sum,n,k,ans,ds,nums);

    sum = sum - nums[index];
    ds.pop_back();
    solve(index+1,sum,n,k,ans,ds,nums);
}

vector<vector<int>>combinationSum3(int k, int n){
    vector<int>nums = {1,2,3,4,5,6,7,8,9};
    vector<vector<int>>ans;
    vector<int>ds;
    int index = 0;
    int sum = 0;
    solve(index,sum,n,k,ans,ds,nums);
    return ans;
}

int main()
{
    int n = 9;
    int k = 3;
    for (auto i : combinationSum3(k,n))
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
