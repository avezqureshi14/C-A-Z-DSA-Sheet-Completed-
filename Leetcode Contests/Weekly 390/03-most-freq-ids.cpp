#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long getMax(unordered_map<long, long> mp)
{
    long long maxi = 0;
    for (auto i : mp)
    {
        if (i.second > maxi)
        {
            maxi = i.second;
        }
    }
    return maxi;
}

vector<long long> mostFrequentIDs(vector<int> &nums, vector<int> &freq)
{
    int n = nums.size();
    vector<long long> ans;
    unordered_map<long, long> mp;
    long maxi = 0;
    for (int i = 0; i < n; i++)
    {
        mp[nums[i]] = mp[nums[i]] + freq[i];
        maxi = max(maxi, mp[nums[i]]);
        ans.push_back(maxi);
        for (auto i : mp)
        {
            cout << i.first << "-> ";
            cout << i.second << " ";
        }
        cout << endl;
    }

    return ans;
}
int main()
{
    vector<int> nums = {5, 5, 3};
    vector<int> freq = {2, -2, 1};
    for (auto i : mostFrequentIDs(nums, freq))
    {
        cout << i << " ";
    }
    return 0;
}