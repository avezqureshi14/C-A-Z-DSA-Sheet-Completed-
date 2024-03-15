#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isPowerOf(int num, int base)
{
    if (num == 1 && base != 1)
    {
        return false;
    }
    while (num > 1 && num % base == 0)
    {
        num /= base;
    }

    return num == 1;
}

vector<int> sepDups(vector<int> &nums)
{
    vector<int> dups;
    unordered_map<int, int> mp;
    for (auto i : nums)
    {
        mp[i]++;
    }
    for (auto i : mp)
    {
        if (i.second % 2 == 0)
        {
            dups.push_back(i.first);
        }
    }
    return dups;
}

vector<int> checkMultiples(vector<int> dups)
{
    int mini = INT_MAX;
    vector<int> ans;
    for (auto i : dups)
    {
        mini = min(i, mini);
    }
    for (auto i : dups)
    {
        if (isPowerOf(i, mini))
        {
            ans.push_back(mini);
        }
    }

    return ans;
}

bool checkCommon(int num, vector<int> &dups)
{
    for (auto i : dups)
    {
        if (i == num)
        {
            return false;
        }
    }
    return true;
}

int maximumLength(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dups = sepDups(nums);
    vector<int> processed = checkMultiples(dups);
    int mini = INT_MAX;
    vector<int> ans;
    for (auto i : dups)
    {
        mini = min(i, mini);
    }
    int p = processed.size();
    int count = 0;
    for (auto i : nums)
    {
        if (isPowerOf(i, mini) && checkCommon(i, dups))
        {

            count++;
        }
    }
    if (count >= 1)
    {
        return (p * 2) + 1;
    }
    else
    {
        return 1;
    }
}
int main()
{
    vector<int> nums = {1, 16, 49, 16, 121};
    cout << maximumLength(nums);
    return 0;
}