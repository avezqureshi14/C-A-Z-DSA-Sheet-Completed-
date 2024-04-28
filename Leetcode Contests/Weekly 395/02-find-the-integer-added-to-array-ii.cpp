#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> nums1, vector<int> nums2, int x)
{
    int j = 0;
    int count = 0;
    for (int i = 0; i < nums1.size() && j < nums2.size(); i++)
    {
        if (nums1[i] + x != nums2[j])
        {
            count++;
        }
        else
        {
            j++;
        }
    }
    if (count > 2)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int minimumAddedInteger(vector<int> &nums1, vector<int> &nums2)
{
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int minEle = INT_MAX;
    for (int i = 0; i < 3; i++)
    {
        int x = nums2[0] - nums1[i];
        if (check(nums1, nums2, x))
        {
            minEle = min(minEle, x);
        }
    }
    return minEle;
}
int main()
{
    vector<int> nums1 = {4, 6, 3, 1, 4, 2, 10, 9, 5};
    vector<int> nums2 = {5, 10, 3, 2, 6, 1, 9};
    cout << minimumAddedInteger(nums1, nums2);
    return 0;
}