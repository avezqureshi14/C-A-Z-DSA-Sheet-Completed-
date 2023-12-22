#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//O(n) extra space
void mergeI(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    int m = nums2.size();
    vector<int> nums3;
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (nums1[i] < nums2[j])
        {
            nums3.push_back(nums1[i]);
            i++;
            k++;
        }
        else
        {
            nums3.push_back(nums2[j]);
            j++;
            k++;
        }
    }

    while (i < n)
    {
        nums3.push_back(nums1[i]);
        i++;
        k++;
    }

    while (j < m)
    {
        nums3.push_back(nums2[j]);
        j++;
        k++;
    }

    nums1.assign(nums3.begin(),nums3.end());
}


//without any extra space
void mergeII(vector<int>&nums1, vector<int>&nums2, int n, int m){
    int i = n-1;
    int j = m-1;
    int k = n+m-1;
    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[k] = nums1[i];
            k--;
            i--;
        }
        else{
            nums1[k] = nums2[j];
            k--;
            j--;
        }
    }
    while (i >= 0)
    {
        nums1[k] = nums1[i];
        i--;
        k--;
    }
    while (j >= 0)
    {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}


void printArray(vector<int>nums){
    for(auto i : nums){
        cout<<i<<" ";
    }
}

int main()
{
    vector<int>nums1 = {1,2,3,0,0,0};
    vector<int>nums2 = {2,5,6};
    mergeII(nums1,nums2,3,3);
    printArray(nums1);
    return 0;
}