#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> Solve(int n, vector<int> &nums)
{
    unordered_map<int, int> map;
    vector<int> ans;
    int maxVote = n / 3;
    for (auto i : nums)
    {
        map[i]++;
    }
    for (auto i : map)
    {
        if (i.second > maxVote)
        {
            ans.push_back(i.first);
        }
    }
    if (ans.empty())
    {
        ans.push_back(-1);
    }
    return ans;
}

vector<int> majorVote(int n, vector<int> nums)
{
    int vote1 = 0;
    int vote2 = 0;
    int ele1 = INT_MIN;
    int ele2 = INT_MIN;

    // Step 1: Find potential candidates
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == ele1)
        {
            vote1++;
        }
        else if (nums[i] == ele2)
        {
            vote2++;
        }
        else if (vote1 == 0)
        {
            ele1 = nums[i];
            vote1 = 1;
        }
        else if (vote2 == 0)
        {
            ele2 = nums[i];
            vote2 = 1;
        }
        else
        {
            vote1--;
            vote2--;
        }
    }

    // Step 2: Count occurrences of potential candidates
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == ele1)
        {
            cnt1++;
        }
        else if (nums[i] == ele2)
        {
            cnt2++;
        }
    }

    // Step 3: Check if potential candidates are actual majority elements
    int t = n / 3;
    vector<int> ans;
    if (cnt1 > t)
    {
        ans.push_back(ele1);
    }
    if (cnt2 > t)
    {
        ans.push_back(ele2);
    }

    return ans;
}


int main()
{
    vector<int> nums = {2, 1, 5, 5, 5, 5, 6, 6, 6, 6, 6};
    int n = nums.size();
    for (auto i : majorVote(n, nums))
    {
        cout << i << " ";
    }
    return 0;
}