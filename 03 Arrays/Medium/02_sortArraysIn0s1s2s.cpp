#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void sort0s1s2s(vector<int>&nums){
    int i = 0;
    int n = nums.size();
    int low = 0;
    int mid = 0;
    int high = n - 1;
    while (mid <= high)
    {
        switch (nums[mid])
        {
        case 0:
            swap(nums[low],nums[mid]);
            low++;
            mid++;
            break;
        case 1:
            mid++;
            break;        
        case 2:
            swap(nums[high],nums[mid]);
            high--;
        }
        
    }
    
}

void printarray(vector<int>nums){
    for (int i = 0; i < nums.size(); i++)
    {
        cout<<nums[i]<<" ";
    }
    
}

int main()
{
    vector<int>nums = { 2,0,1 };
    sort0s1s2s(nums);
    printarray(nums);
    return 0;
}