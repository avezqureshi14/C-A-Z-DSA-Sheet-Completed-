#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int threeSumClosest(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int ans = 0;
    int n = nums.size();
    for (int i = 0; i < n - 2; i++)
    {
        int j = i + 1;
        int k = n - 1;
        int diff = INT_MAX;
        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == target)
            {
                return target;
            }
            else if (abs(sum - target) < diff)
            {
                diff = abs(sum - target);
                ans = sum;
            }
            if (sum > target)
            {
                k--;
            }
            else
            {
                j++;
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    cout << threeSumClosest(nums, target);
    return 0;
}