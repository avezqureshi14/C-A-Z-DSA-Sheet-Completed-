#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int maximumSubarray(vector<int>nums){
    int n = nums.size();
    int currSum = 0;
    int finalSum = INT_MIN;
    int start = -1;
    int ansStart,ansEnd = -1;
    for (int i = 0; i < n; i++)
    {
        if (currSum == 0)
        {
            start = i;
        }
        
        currSum = currSum + nums[i];
        if (currSum > finalSum)
        {
            finalSum = currSum;
            ansStart = start;
            ansEnd = i;
        }
        
        if (currSum < 0)
        {
            currSum = 0;
        }
    }
    cout<<"The first element is "<<ansStart<<endl;
    cout<<"The last element is "<<ansEnd<<endl;
    return finalSum;
}
int main()
{
    vector<int>nums = {-2,-3,-4,-1,0,-5};
    cout<<"The maximum Subarray is "<<maximumSubarray(nums);
    return 0;
}