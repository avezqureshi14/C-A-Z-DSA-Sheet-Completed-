#include <iostream>
#include <bits/stdc++.h>
using namespace std;

static bool comp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first && a.second < b.second)
    {
        return false;
    }
    else if (a.first > b.first)
    {
        return true;
    }
    return false;
}

int findNthSmallest(vector<pair<int, int>> nums, int n)
{
    sort(nums.begin(), nums.end(), comp);
    reverse(nums.begin(), nums.end());
    for (auto i : nums)
    {
        cout << i.first << " : " << i.second << ", ";
    }
    cout << endl;
    return nums[n - 1].second;
}

vector<pair<int, int>> trimmer(vector<string> &nums, int trim)
{
    vector<pair<int, int>> trimmed;
    int n = nums.size();
    int len = nums[0].length();
    for (int i = 0; i < n; i++)
    {
        string num = "";
        for (int j = len - trim; j <= len - 1; j++)
        {
            num = num + nums[i][j];
        }
        trimmed.push_back({stoi(num), i});
    }

    return trimmed;
}

vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries)
{
    int n = queries.size();

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int smallest = queries[i][0];
        int trim = queries[i][1];
        vector<pair<int, int>> trimmed = trimmer(nums, trim);
        ans.push_back(findNthSmallest(trimmed, smallest));
    }
    return ans;
}

int main()
{
    vector<string> nums = {"24", "37", "96", "04"};
    vector<vector<int>> queries = {
        {1, 1},
        {2, 3},
        {4, 2},
        {1, 2}};
    for (auto i : smallestTrimmedNumbers(nums, queries))
    {
        cout << i << " ";
    }
    return 0;
}