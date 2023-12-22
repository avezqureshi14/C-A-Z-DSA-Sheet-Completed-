#include <iostream>
#include <bits/stdc++.h>
using namespace std;

pair<int, int> floorAndCeil(vector<int> nums, int target)
{
    int floor = -1;
    int ceil = -1;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] <= target && (floor == -1 || nums[i] > nums[floor]))
        {
            floor = i;
        }
        if (nums[i] >= target && (ceil == -1 || nums[i] < nums[ceil]))
        {
            ceil = i;
        }
    }

    pair<int, int> p = make_pair(nums[floor], nums[ceil]);
    return p;
}

int main()
{
    vector<int> nums = {5, 6, 8, 9, 6, 5, 5, 6};
    pair<int, int> ans = floorAndCeil(nums, 10);
    cout << "Floor is " << ans.first << endl;
    cout << "Ceil is " << ans.second << endl;

    return 0;
}