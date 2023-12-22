#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int>twoSum(vector<int>nums, int target){
    unordered_map<int,int>map;
    vector<int>ans;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
            if (map.find(target-nums[i]) != map.end())
            {
                ans.push_back(i);
                ans.push_back(map[target-nums[i]]);
            }
            map[nums[i]] = i;
            // KEY -> INDEX
    }

    return ans;
}
int main()
{
    vector<int>nums = {2,7,11,15};
    int target = 9;
    for(auto i : twoSum(nums,target)){
        cout<<i<<" ";
    }

    return 0;
}