#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int missingNumber(vector<int> nums)
{
    int n = nums.size();
    int Totalsum = 0;
    int Arraysum = 0;
    for (int i = 0; i < n + 1; i++)
    {
        Totalsum = Totalsum + i;
    }
    for (int i = 0; i < n; i++)
    {
        Arraysum = Arraysum + nums[i];
    }
    int ans = Totalsum - Arraysum;
    return ans;
}

int main()
{
    vector<int>nums = {9,6,4,2,3,5,7,0,1};
    cout<<"The missing number in the given array is "<<missingNumber(nums);
    return 0;
}