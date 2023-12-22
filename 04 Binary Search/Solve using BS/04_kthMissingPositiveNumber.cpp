#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool binarySearch(vector<int> &nums, int key)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == key)
        {
            return true;
        }
        else if (nums[mid] > key)
        {
            high = mid - 1;
        }
        else if (nums[mid] < key)
        {
            low = mid + 1;
        }
    }

    return false;
}

int findKthPositive(vector<int> &arr, int k)
{
    int n = arr.size();
    int low = 1;
    int high = INT_MAX;
    int j = 0;
    int count = 0;

    for (int i = low; i < high; i++)
    {
        if (!binarySearch(arr, i))
        {
            count++;
            if (count == k)
            {
                return i;
            }
        }
    }
    return 0;
}
// optimal
int findKthPositiveII(vector<int> &arr, int k)
{
    int low = 0;
    int high = arr.size();
    int mid = (low + high) / 2;
    // no. of missing number at a particular index
    int nmissing = arr[mid] - 1 - mid;
    if (nmissing < k)
    {
        low = mid + 1;
    }
    else
    {
        high = mid;
    }
    return low + k;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    int k = 2;
    cout << findKthPositive(nums, k);
    return 0;
}