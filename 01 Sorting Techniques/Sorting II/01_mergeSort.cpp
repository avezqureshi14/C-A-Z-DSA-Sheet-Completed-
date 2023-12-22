#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (nums[left] <= nums[right])
        {
            temp.push_back(nums[left]);
            left++;
        }
        else{
            temp.push_back(nums[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(nums[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(nums[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
    {
        //hack for implace 
        nums[i] = temp[i-low];
    }
        
}

//divide
void mergeSort(vector<int> &nums, int low, int high)
{
    if (low == high)
    {
        return;
    }
    int mid = low + (high - low) / 2;
    mergeSort(nums, low, mid);
    mergeSort(nums, mid + 1, high);

    merge(nums,low,mid,high);
}

void mergeSortArray(vector<int> &nums)
{
    int n = nums.size();
    mergeSort(nums, 0, n - 1);
}


void printArray(vector<int>nums){
    for(auto i : nums){
        cout<<i<<" ";
    }
}

int main()
{
    vector<int> nums = {10,5,7,3,2,4};
    mergeSortArray(nums);
    printArray(nums);
    return 0;
}