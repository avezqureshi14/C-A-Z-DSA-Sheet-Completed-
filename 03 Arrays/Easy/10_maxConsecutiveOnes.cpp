#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int maxConsecutiveOnes(vector<int>nums){
    int n = nums.size();
    int count = 0;
    int maxCount = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 1)
        {
            count++;
        }
        maxCount = max(maxCount,count);
        if (nums[i] == 0)
        {
            count = 0;
        }
    }

    return count;
    
}
int main()
{
    vector<int>nums = {1,1,0,1,1,1};
    cout<<"Max consecutive ones is "<<maxConsecutiveOnes(nums);
    return 0;
}