#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// passed 2008 / 2013 testcases on Leetcode
int minAbsoluteDifference(vector<int> &nums, int x)
{
    int n = nums.size();
    int minDiff = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j - i >= x)
            {
                minDiff = min(abs(nums[j] - nums[i]), minDiff);
            }
        }
    }

    return minDiff;
}

int minAbsDiff(vector<int> &nums, int x)
{
    int n = nums.size();
    int ans = INT_MAX;
    multiset<int> s;
    for (int i = 0; i < n; ++i)
    {
        s.insert(nums[i - x]);
        auto it = s.upper_bound(nums[i]);
        if (it != s.end())
        {
            ans = min(ans, abs(*it - nums[i]));
        }
        if (it != s.begin())
        {
            ans = min(ans, abs(*prev(it) - nums[i]));
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    int x = 3;
    cout << minAbsoluteDifference(nums, x);
    return 0;
}