#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int firstNeg(vector<int> &nums, int s, int e)
{
    int ans = 0;
    for (int i = s; i <= e; i++)
    {
        if (nums[i] < 0)
        {
            ans = nums[i];
            break;
        }
    }
    return ans;
}

// this solution have the time complexity of O(n^2)
vector<int> firstNegativeNumInWindowOfSizeK(vector<int> &nums, int k)
{
    int i = 0;
    int j = 0;
    int n = nums.size();
    vector<int> res;
    while (j < n)
    {
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            int ans = firstNeg(nums, i, j);
            res.push_back(ans);
            i++;
            j++;
        }
    }
    return res;
}

// the below solution have time complexity of O(n)
vector<int> firstNegativeNumInWindowOfSizeKII(vector<int> &nums, int k)
{
    deque<int> window;
    vector<int> ans;
    int n = nums.size();
    for (int i = 0; i < k; i++)
    {
        if (nums[i] < 0)
        {
            window.push_back(nums[i]);
        }
    }

    if (!window.empty())
    {
        ans.push_back(window.front());
    }

    for (int i = k; i < n; i++)
    {
        // removing the visited windows element
        if (!window.empty() && window.front() == nums[i - k])
        {
            window.pop_front();
        }

        // taking the first negative element of our window inside our answer
        if (!window.empty())
        {
            ans.push_back(window.front());
        }

        // checking and inserting of current element inside the window if it is less than 0
        if (nums[i] < 0)
        {
            window.push_back(nums[i]);
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {12, -1, -7, 8, -15, 30, 6, 28};
    int k = 3;
    for (auto i : firstNegativeNumInWindowOfSizeKII(nums, k))
    {
        cout << i << " ";
    }
    return 0;
}