#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int binarySubarrayWithSum(vector<int>&nums, int goal){
    unordered_map<int,int>map;
    int sum = 0;
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (sum == goal)
        {
            count++;
        }
        if(map.find(sum-goal) != map.end()){
            count += map[sum - goal];
        }
        if(map.find(sum) != map.end()){
            map[sum]++;
        }
        else{
            map[sum] = 1;
        }
    }
    return count;
}


int main()
{
    vector<int> nums = {0,0,0,0,0};
    int goal = 0;
    cout << binarySubarrayWithSum(nums, goal);
    return 0;
}