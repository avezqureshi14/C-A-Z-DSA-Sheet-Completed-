#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int removeDuplicatesFromSortedArray(vector<int>nums){
    int n = nums.size();
    int i = 0;
    int j = 1;
    while(j<n)
    {
        if (nums[i] != nums[j])
        {
            i++;
            nums[i] = nums[j];
        }
        j++;
        
    }
    return i  + 1;
}
int main()
{
    vector<int>nums = {0,0,1,1,1,2,2,2,3,3,3,4};
    cout<<"The number of Duplicates in the given array is "<<removeDuplicatesFromSortedArray(nums);
    return 0;
}