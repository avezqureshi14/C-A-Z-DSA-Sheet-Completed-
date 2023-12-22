#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int searchInsertPosition(vector<int>nums, int target){
    int n = nums.size();
    int low  = 0;
    int high = n-1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if(nums[mid] == target){
            return mid;
        }
        else if(nums[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return low;
}
int main()
{
    vector<int>nums = {1,3,5,6};
    cout<<"The position of the element or the hypothetical position where it can be is "<<searchInsertPosition(nums,7);
    return 0;
}