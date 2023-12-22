//smallest element greater than or equal to target

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int ceilInSortedArray(vector<int>nums, int target){
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if(nums[mid] >= target){
            ans = nums[mid];
            high = mid - 1;
        }
        else if(nums[mid] < target){
            low = mid + 1;
        }
    }
    return ans;
}
int main()
{
    vector<int>nums = {1, 3, 5, 7, 9};
    cout<<"Ceil of the given element is "<<ceilInSortedArray(nums,4);
    return 0;
}