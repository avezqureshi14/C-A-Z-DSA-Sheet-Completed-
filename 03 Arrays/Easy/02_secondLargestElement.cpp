#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int brute(vector<int>nums){
    sort(nums.begin(),nums.end());
    int largest = nums[nums.size()-1];
    int slargest;
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        if (nums[i] != largest)
        {
            slargest = nums[i];
        }
    }
    return slargest;    
}

int better(vector<int> nums)
{
    int largest = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > largest)
        {
            largest = nums[i];
        }
    }
    int slargest = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > slargest && nums[i] != largest)
        {
            slargest = nums[i];
        }
    }
    return slargest;    
}

int optimal(vector<int>nums){
    int largest = nums[0];
    int slargest = INT_MIN;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > largest)
        {
            slargest = largest;
            largest = nums[i];
        }
        else if(nums[i] <= largest && nums[i] > slargest){
            slargest = nums[i];
        }
    }
    return slargest;
}

int main()
{
    vector<int>nums = {1,2,7,3,4,5,5,4,6};
    cout<<"The second largest element is "<<optimal(nums);
    return 0;
}