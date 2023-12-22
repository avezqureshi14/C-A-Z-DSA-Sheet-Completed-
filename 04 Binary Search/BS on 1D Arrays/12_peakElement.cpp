#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int peakElement(vector<int>&nums){
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid]<nums[mid+1])
        {
            low = mid + 1;
        }
        else {
            high = mid;
        }
        
    }
    return low;
}
int main()
{
    vector<int>nums = {1,2,3,1};
    cout<<"The Peak Element is "<<peakElement(nums);
    return 0;
}