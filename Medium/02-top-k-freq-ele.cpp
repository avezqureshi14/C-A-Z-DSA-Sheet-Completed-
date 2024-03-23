#include <iostream>
#include <bits/stdc++.h>
using namespace std;

static bool comp(pair<int, int> &a, pair<int, int> &b)
{
    return a.second > b.second;
}

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    for (auto i : nums)
    {
        mp[i]++;
    }
    vector<pair<int, int>> v;
    vector<int> ans;
    for (auto i : mp)
    {
        pair<int, int> p;
        p.first = i.first;   // element
        p.second = i.second; // freq
        v.push_back(p);
    }
    sort(v.begin(), v.end(), comp);
    int n = v.size();
    for (int i = 0; i < k; i++)
    {
        ans.push_back(v[i].first);
    }

    return ans;
}
int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 3, 5, 5, 5, 5, 5, 5, 3, 3, 3, 3, 3};
    int k = 2;
    topKFrequent(nums, k);
    return 0;
}