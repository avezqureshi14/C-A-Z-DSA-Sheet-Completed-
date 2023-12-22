#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3)
{
    int n = nums1.size();
    int m = nums2.size();
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
}

double findMedianSortedArraysI(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> nums3;
    merge(nums1, nums2, nums3);
    int n = nums3.size();
    int low = 0;
    int high = n - 1;
    int mid = low + (high - low) / 2;
    double ans = 0;
    if (n % 2 == 0)
    {
        ans = (nums3[mid] + nums3[mid + 1]) / 2.0;
    }
    else
    {
        ans = nums3[mid];
    }

    return ans;
}

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    if (nums2.size() < nums1.size())
    {
        return findMedianSortedArrays(nums2, nums1);
    }

    int n1 = nums1.size();
    int n2 = nums2.size();
    int low = 0;
    int high = n1;

    while (low <= high)
    {
        int cut1 = (low + high) >> 1;
        // int cut1 = (low + high) / 2; //the above lines means this 
        int cut2 = (n1 + n2 + 1) / 2 - cut1;

        int left1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
        int left2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];

        int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];
        int right2 = cut2 == n2 ? INT_MAX : nums2[cut2];

        if (left1 <= right2 && left2 <= right1)
        {
            if ((n1 + n2) % 2 == 0)
            {
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            }
            else
            {
                return max(left1, left2);
            }
        }
        else if (left1 > right2)
        {
            high = cut1 - 1;
        }
        else
        {
            low = cut1 + 1;
        }
    }
    return 0.0;
}

int main()
{
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3,4};
    cout << "Median of the given sorted array " << findMedianSortedArrays(nums1, nums2);
    return 0;
}
