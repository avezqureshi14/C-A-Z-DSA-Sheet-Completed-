#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int minimumRightShifts(vector<int> &nums)
{
    int n = nums.size();
    int index = 0;
    int i = 0;
    while (index < n - 1 && nums[i] > nums[i + 1])
    {
        index++;
    }
    if (index == n - 1)
    {
        return 0;
    }
    index++;
    int curIndex = index;
    // checking if the remaining elements after the index are also sorted
    while (index < n - 1 && nums[index] > nums[index + 1])
    {
        index++;
    }

    // the index was not able to reach at end the elements after the index are not in sorted order
    if (index != n - 1)
    {
        return -1;
    }

    // now to check whether is the last element greater than first element
    if (nums[0] > nums[n - 1])
    {
        return n - curIndex;
    }
    return -1;
}
int main()
{
    vector<int> nums = {92, 84, 37, 19, 16, 85, 20, 79, 25, 89};
    cout << minimumRightShifts(nums);

    return 0;
}