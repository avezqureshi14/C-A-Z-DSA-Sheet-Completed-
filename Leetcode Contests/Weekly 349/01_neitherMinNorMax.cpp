#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int findNonMinOrMax(vector<int> &nums)
{
    int n = nums.size();
    int  minValue = nums[0];
    int secondMin = -1;
    if (n <= 2)
    {
        secondMin = -1;
        return secondMin;
    }
    else
    {
        for (int i = 1; i < n; i++)
        {
            if (nums[i] < minValue)
            {
                secondMin = minValue;
                minValue = nums[i];
            }
            else if(nums[i] < minValue && nums[i] > secondMin){
                secondMin = nums[i];
            }
        }
        
    }
    return secondMin;
}
int main()
{
    vector<int>nums = {2,4,25};
    cout<<findNonMinOrMax(nums);
    return 0;
}