#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool checkDups(vector<int> nums)
{
    unordered_map<int, int> map;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        map[nums[i]]++;
    }

    for (auto i : map)
    {
        if (i.second > 1)
        {
            return false;
        }
    }
    return true;
}

void generatePowersetRecursive(vector<int> &nums, vector<int> &currentSubset, int index, vector<vector<int>> &powerset, int prev=0, int curr=0)
{
    if (index == nums.size())
    {
        if (checkDups(currentSubset))
        {
            powerset.push_back(currentSubset);
            
        }
        return;
    }

    // Exclude the current element
    generatePowersetRecursive(nums, currentSubset, index + 1, powerset, prev, curr);

    // Include the current element
    currentSubset.push_back(nums[index]);
    generatePowersetRecursive(nums, currentSubset, index + 1, powerset, prev, curr);

    // Backtrack
    currentSubset.pop_back();
}

int maxIncreasingGroups(vector<int> &usageLimits)
{
    int index = 0;
    vector<int> currentSubset;
    vector<vector<int>> powerSet;
    generatePowersetRecursive(usageLimits, currentSubset, 0, powerSet);
    int count = powerSet.size();
    cout<<endl;
    for(auto i : powerSet){
        for(auto j : i ){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return count;
}
int main()
{
    vector<int> usage = {0, 1, 1, 2, 2, 2, 2, 2};
    cout<<maxIncreasingGroups(usage);
    return 0;
}