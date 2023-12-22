#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int floorInSortedArray(vector<int>nums, int target){
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if(nums[mid] <= target){
            ans = nums[mid];
            low = mid + 1;
        }
        else if(nums[mid] > target){
            high = mid - 1;
        }
    }
    return ans;
}
int main()
{
    vector<int>nums = {1,2,8,10,11,12,19};
    cout<<"Floor of the given element is "<<floorInSortedArray(nums,13);
    return 0;
}