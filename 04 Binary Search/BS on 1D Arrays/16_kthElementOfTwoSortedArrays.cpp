#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int kthElementOfTwoSortedArraysII(vector<int> nums1, vector<int> nums2, int k){
    int n = nums1.size();
    int m = nums2.size();
    vector<int> nums3;
    int i = 0;
    int j = 0;
    while (i < n && j < m)
    {
        if (nums1[i] < nums2[j])
        {
            nums3.push_back(nums1[i]);
            i++;
        }
        else
        {
            nums3.push_back(nums2[j]);
            j++;
        }
    }

    while (i < n)
    {
        nums3.push_back(nums1[i]);
        i++;
    }

    while (j < m)
    {
        nums3.push_back(nums2[j]);
        j++;
    }
    int ans;
    for (int i = 0; i < nums3.size(); i++)
    {
        //because vector is indexed from 0
        ans = nums3[k-1];
    }
    
    return ans;
}

int kthElementOfTwoSortedArrays(vector<int>nums1,vector<int>nums2, int k)
{
    int n = nums1.size();
    int m = nums2.size();
    if (n > m)
    {
        return kthElementOfTwoSortedArrays(nums2,nums1,k);
    }

    int low = max(0,k-m), high = min(k,n);

    while (low <= high)
    {
        int cut1 = (low + high) >> 1;
        int cut2 = k - cut1;
        int l1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
        int l2 = cut2 == 0 ? INT_MIN : nums2[cut2-1];
        int r1 = cut1 == n ? INT_MAX : nums1[cut1];
        int r2 = cut2 == m ? INT_MAX : nums2[cut2];

        if(l1 <= r2 && l2 <= r1){
            return max(l1,l2);
        }
        else if(l1 > r2){
            high = cut1 - 1;
        }
        else{
            low = cut1 + 1;
        }
    }
    return 1;
}


int main()
{
    vector<int>nums1 = {2, 3, 6, 7, 9};
    vector<int>nums2 = {1, 4, 8, 10};
    cout<<"The kth element is "<<kthElementOfTwoSortedArrays(nums1,nums2,5);
    return 0;
}