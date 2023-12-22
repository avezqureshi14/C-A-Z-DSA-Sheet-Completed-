#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxAreaOfHistogram(vector<int> nums)
{
    int n = nums.size();
    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        int minHeight = INT_MAX;
        for (int j = i; j < n; j++)
        {
            minHeight = min(minHeight, nums[j]);
            int width = j - i + 1;
            maxArea = max(maxArea, minHeight * width);
        }
    }
    return maxArea;
}
                                           
int main()
{
    vector<int>nums = {2, 1, 5, 6, 2, 3, 1};
    cout<<maxAreaOfHistogram(nums);
    return 0;
}