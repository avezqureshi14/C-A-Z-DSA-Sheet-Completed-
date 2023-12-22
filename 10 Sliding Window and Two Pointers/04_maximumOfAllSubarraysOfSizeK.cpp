#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxiNum(deque<int> &window)
{
    int maxi = INT_MIN;
    for (int i = 0; i < window.size(); i++)
    {
        maxi = max(maxi, window[i]);
    }
    return maxi;
}

vector<int> maxOfSubarraysOfSizeK(vector<int> nums, int k)
{
    int n = nums.size();
    int maxi = INT_MIN;
    deque<int> window;
    vector<int> ans;
    for (int i = 0; i < k; i++)
    {
        while (!window.empty() && nums[window.back()] < nums[i])
        {
            window.pop_back();
        }
        window.push_back(i);
    }
    ans.push_back(nums[window.front()]);
    for (int i = k; i < n; i++)
    {
        if (window.front() == i - k)
        {
            window.pop_front();
        }
        while (!window.empty() && nums[window.back()] < nums[i])
        {
            window.pop_back();
        }
        window.push_back(i);
        ans.push_back(nums[window.front()]);
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, -7};
    int k = 3;
    for (auto i : maxOfSubarraysOfSizeK(nums, k))
    {
        cout << i << " ";
    }
    return 0;
}