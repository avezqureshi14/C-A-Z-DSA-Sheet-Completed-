#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int countPairs(vector<int> &nums, int target)
{
    int count = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i + 1; j < n; j++)
        {
            sum = nums[i] + nums[j];
            if (sum < target)
            {
                count++;
            }
            
        }
    }
    return count;
}

int main()
{
    vector<int>nums = {-6,2,5,-2,-7,-1,3};
    cout<<countPairs(nums,-2);
    return 0;
}