#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void immediateSmaller(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n-1; i++) {
        if (nums[i] > nums[i+1]) {
            nums[i] = nums[i+1];
        }
        else {
            nums[i] = -1;
        }
    }
    nums[n-1] = -1;
}

int main()
{
    vector<int>nums = {4,2,1,5,3};
    immediateSmaller(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout<<nums[i]<<" ";
    }
    
    return 0;
}