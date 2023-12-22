#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxSumSubarray(vector<int> &nums, int k)
{
    int i = 0;
    int j = 0;
    int n = nums.size();
    int sum = 0;
    int maxSum = INT_MIN;
    while (j < n)
    {
        sum = sum + nums[j];
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            maxSum = max(maxSum, sum);
            sum = sum - nums[i];
            i++;
            j++;
        }
    }
    return maxSum;
}

int main()
{
    vector<int> nums = {2, 1, 3, 4, 2, 1, 5, 1};
    int k = 3;
    cout << maxSumSubarray(nums, k);
    return 0;
}