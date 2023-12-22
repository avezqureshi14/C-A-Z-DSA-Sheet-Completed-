#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int largestSubarrayOfSumK(vector<int> &nums, int k)
{
    int n = nums.size();
    int i = 0;
    int j = 0;
    int sum = 0;
    int maxi = 0;
    int count = 0;
    while (j < n)
    {
        sum += nums[j];
        count++;
        if (sum < k)
        {

            j++;
        }
        else if (sum == k)
        {
            maxi = max(maxi, count);
            sum = sum - nums[i];
            count--;
            i++;
            j++;
        }
        else if (sum > k)
        {
            sum = sum - nums[i];
            i++;
            count--;
        }
    }
    return maxi;
}
int main()
{
    vector<int> nums = {4, 1, 1, 1, 2, 3, 5};
    int k = 5;
    cout << largestSubarrayOfSumK(nums, k);
    return 0;
}