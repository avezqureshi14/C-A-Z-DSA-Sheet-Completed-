#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void merging(vector<int> &nums, int low, int mid, int high, int &ans)
{
    int left = low;
    int right = mid + 1;
    vector<int> temp;
    int j = mid + 1;
    for (int i = low; i <= mid; i++)
    {
        while (j <= high && nums[i] > 2LL * nums[j])
        {
            j++;
        }
        ans = ans + (j - (mid + 1));
    }

    while (left <= mid && right <= high)
    {
        if (nums[left] <= nums[right])
        {
            temp.push_back(nums[left]);
            left++;
        }
        else
        {
            temp.push_back(nums[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(nums[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(nums[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
    {
        nums[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &nums, int low, int high, int &ans)
{
    if (low == high)
    {
        return;
    }
    int mid = low + (high - low) / 2;
    mergeSort(nums, low, mid, ans);
    mergeSort(nums, mid + 1, high, ans);
    merging(nums, low, mid, high, ans);
}

void merge(vector<int> &nums, int &ans)
{
    int low = 0;
    int high = nums.size() - 1;

    mergeSort(nums, low, high, ans);
}

int reversePairs(vector<int> &nums)
{
    int ans = 0;
    merge(nums, ans);
    return ans;
}
int main()
{
    vector<int> nums = {2,4,3,5,1};
    cout << reversePairs(nums);
    return 0;
}