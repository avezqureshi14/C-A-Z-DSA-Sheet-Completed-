#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// approach1 : in this approach divide the vector into two halves start comparing the elements if nums[i] < nums[j]  then they both can be deleted increase count by 2 and i not move j forward and then check with another elements and at last we have to return nums.size() - count
int minLengthAfterRemovals(vector<int> &nums)
{
    int n = nums.size();
    int i = 0;
    int j = n / 2;
    int count = 0;
    while (j < n && i < n / 2)
    {
        if (nums[i] < nums[j])
        {
            count = count + 2;
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }

    return nums.size() - count;
}

int minLengthAfterRemovalsII(vector<int> &nums)
{
    unordered_map<int, int> map;
    int maxi = 0;
    int n = nums.size();
    for (auto i : nums)
    {
        map[i]++;
    }
    for (auto i : map)
    {
        if (i.second > n / 2)
        {
            maxi = max(maxi,i.second);
        }
    }
    if (maxi <= n / 2)
    {
        if (n % 2)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    return maxi*2 - n;
}

int main()
{
    vector<int> nums = {1, 3, 4, 9};
    cout << minLengthAfterRemovals(nums);
    return 0;
}