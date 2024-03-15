#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int n = nums1.size();
    int m = nums2.size();
    int i = 0;
    int j = 0;
    vector<int> ans;
    while (i < m && j < n)
    {
        if (nums1[i] == nums2[j])
        {
            ans.push_back(nums1[i]);
            i++;
            j++;
        }
        else if (nums1[i] > nums2[j])
        {
            j++;
        }
        else if (nums2[j] > nums1[i])
        {
            i++;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    for (auto i : intersection(nums1, nums2))
    {
        cout << i << " ";
    }
    return 0;
}