#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> rotateArray(vector<int> nums, int k)
{
    int n = nums.size();
    vector<int> nums2(n);
    for (int i = 0; i < n; i++)
    {
        int index = (i + k) % n;
        nums2[index] = nums[i];
    }

    return nums2;
}

void rotateArrayInplace(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n; //this will find a number less than the length of array which will be also created same kind of rotation  as that greater number would have create we are not using greater number directly because it may take our loop out of bound 


    //reverse first n-k elements 
    reverse(nums.begin(),nums.begin() + n - k );

    //first last k elements
    reverse(nums.begin() + n - k, nums.end() );

    //reverse complete vector
    reverse(nums.begin(), nums.end());

}

void print(vector<int> nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    rotateArrayInplace(nums,k);
    print(nums);
    return 0;
}