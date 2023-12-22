#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int binarySearch(vector<int>nums, int target){
    int low = 0 ;
    int high = nums.size() - 1;
    while (low  <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if(nums[mid] > target){
            high = mid - 1;
        }
        else{
            low  = mid + 1;
        }
    }
    return -1;    
}

int main()
{
    vector<int>nums = {1,2,3,4,5,6,7,8,9};
    int target = 9 ;
    cout<<"The position of the given element is "<<binarySearch(nums,9);
    return 0;
}