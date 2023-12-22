#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void moveZeroes(vector<int> &nums)
{
    int onZero = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            swap(nums[i], nums[onZero]);
            onZero++;
        }
    }
}

void moveZeroBrute(vector<int> &nums)
{
    vector<int> ans(nums.size());
    int k=0; 
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[k] != 0)
        {
            ans[k] = nums[k];
        }
        k++;
    }
    cout<<endl;
    cout<<k;
    cout<<endl;
    while (k < nums.size())
    {
        ans.push_back(0);
        k++;
    }
    for(auto i :ans){
        cout<<i<<" ";
    }
}

vector<int> findUnion(vector<int> nums1, vector<int> nums2)
{
    // Your code here
    // return vector with correct order of elements
    int n = nums1.size();
    int m = nums2.size();
    set<int> set;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        set.insert(nums1[i]);
    }
    for (int i = 0; i < n; i++)
    {
        set.insert(nums2[i]);
    }

    for (auto i : set)
    {
        ans.push_back(i);
    }

    return ans;
}

void printArray(vector<int> nums)
{
    for (auto i : nums)
    {
        cout << i << " ";
    }
}

int main()
{
    vector<int> nums1 = {1,0, 0, 1, 2, 3,0,8};
    vector<int> nums2 = {8, 7, 1, 2, 3};

    moveZeroes(nums1);
    printArray(nums1);
    cout<<endl;
    moveZeroBrute(nums1);
    return 0;
}