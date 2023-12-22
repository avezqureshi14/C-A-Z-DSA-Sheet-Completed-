#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int largestElement(vector<int> nums)
{
    sort(nums.begin(), nums.end());
    return nums[nums.size() - 1];
}

long long maxArrayValue(vector<int> &nums)
{
    int n = nums.size();
    long long suffixSum = 0;
    long long maxSum = INT_MIN;
    for (int i = n - 1; i >= 0; i--)
    {
        if (nums[i] > suffixSum)
        {
            suffixSum = 0;
        }
        suffixSum = suffixSum + nums[i];
        maxSum = max(maxSum,suffixSum);
    }
    return maxSum;    
}

int main()
{
    vector<int>nums = {2,3,7,9,3};
    cout<<maxArrayValue(nums);
    return 0;
}