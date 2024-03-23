#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int prefixSum(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 1; i < n; i++)
    {
        nums[i] = nums[i - 1] + nums[i];
    }
    return 0;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    prefixSum(nums);
    for (auto i : nums)
    {
        cout << i << " ";
    }
    return 0;
}
