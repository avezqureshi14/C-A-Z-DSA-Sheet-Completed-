#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//duplicates are also handled in proper manner , please dry run it is best code 
bool searchOptimal(vector<int> &nums, int target)
{
    int l = 0;
    int r = nums.size() - 1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target)
            return true;
        // with duplicates we can have this contdition, just update left & right
        if ((nums[l] == nums[mid]) && (nums[r] == nums[mid]))
        {
            l++;
            r--;
        }
        // first half
        // first half is in order
        else if (nums[l] <= nums[mid])
        {
            // target is in first  half
            if ((nums[l] <= target) && (nums[mid] > target))
                r = mid - 1;
            else
                l = mid + 1;
        }
        // second half
        // second half is order
        // target is in second half
        else
        {
            if ((nums[mid] < target) && (nums[r] >= target))
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
    return false;
}

// the idea is to use binary search to narrow down the search space for the pivot element by comparing the middle element with the last element of the array.
int pivotElement(vector<int> &nums)
{
    int n = nums.size();

    int low = 0;
    int high = n - 1;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] > nums[high])
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

    return low;
}

int binarySearch(vector<int> &nums, int target, int low, int high)
{
    int n = nums.size();

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}

int search(vector<int> &nums, int target)
{
    int n = nums.size();
    int pivot = pivotElement(nums);
    int ans;

    // 🔴case when there is only one element in the array
    if (pivot == 0)
    {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }

    // 🔴 Condition for searching behind and forward pivot, this is very much important
    if (target < nums[0])
    {
        return binarySearch(nums, target, pivot, nums.size() - 1);
    }
    else
    {
        return binarySearch(nums, target, 0, pivot - 1);
    }

    return ans;
}

int main()
{
    vector<int> nums = {2,5,6,0,0,1,2};
    cout << "The position of element in the given array is " << searchOptimal(nums, 3) << endl;
    return 0;
}