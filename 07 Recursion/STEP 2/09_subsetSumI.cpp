#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>&nums, int index, vector<int>&ans,vector<int>&ds){
    if (index == nums.size())
    {
        int sum = 0;
        for(auto i : ds){
            sum = sum + i;
        }
        ans.push_back(sum);
        return;
    }
    
    ds.push_back(nums[index]);
    solve(nums,index+1,ans,ds);

    ds.pop_back();
    solve(nums,index+1,ans,ds);

}

vector<int>subsetSumI(vector<int>nums){
    int index = 0;
    vector<int>ans;
    vector<int>ds;
    solve(nums,index,ans,ds);
    return ans;
}

int main()
{
    vector<int>nums = {2,3};
    for(auto i : subsetSumI(nums)){
        cout<<i<<" ";
    }
    return 0;
}          