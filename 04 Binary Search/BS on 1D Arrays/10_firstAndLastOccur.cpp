#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int firstPos(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
        {
            ans = mid;
            high = mid - 1;
        }
        else if (nums[mid] > target)
        {
            high = mid - 1;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
    }
    return ans;
}
int lastPos(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int ans = -1;
    
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
        {
            ans = mid;
            low = mid + 1;
        }
        else if (nums[mid] > target)
        {
            high = mid - 1;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
    }
    return ans;
}
vector<int> searchRange(vector<int> &nums, int target)
{
    vector<int> ans;
    
    int first = firstPos(nums, target);
    int last = lastPos(nums, target);
    ans.push_back(first);
    ans.push_back(last);
    return ans;
}
int main()
{
    vector<int>nums={1};
    for(auto i : searchRange(nums,1)){
        cout<<i<<" "; 
    }
    return 0;
}