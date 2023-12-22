#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int>findMissingAndRepeating(vector<int>&nums){
    unordered_map<int,int>map;
    vector<int>ans;
    int n = nums.size();
    for (int i = 1; i <= n; i++)
    {
        map[i] = 0;
    }
    
    for(auto i : nums){
        map[i]++;
    }

    for(auto i : map){
        //missing
        if (i.second < 1)
        {
            ans.push_back(i.first);
        }
        //repeating
        if (i.second > 1)
        {
            ans.push_back(i.first);
        }
        
    }

    return ans;
}

int main()
{
    vector<int>nums = {3,1,2,5,3};
    for(auto i : findMissingAndRepeating(nums)){
        cout<<i<<" ";
    }
    return 0;
}