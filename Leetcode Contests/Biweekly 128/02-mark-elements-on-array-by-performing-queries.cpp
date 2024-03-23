#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void smallestNumSmallestInd(vector<int> &nums, vector<long long> &marking, int count)
{
    int smallest = INT_MAX;
    int smallInd = -1;
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < nums.size(); j++)
        {
            if ((nums[j] < smallest || nums[j] == smallest && j < smallInd) && marking[j] == 0)
            {
                smallest = nums[j];
                smallInd = j;
            }
        }
        marking[smallInd] = 1;
        smallest = INT_MAX;
        smallInd = -1;
    }
}

long long ansCal(vector<int> &nums, vector<long long> &marking)
{
    long long ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (marking[i] == 0)
        {
            ans = ans + nums[i];
        }
    }
    return ans;
}
vector<long long> unmarkedSumArray(vector<int> &nums, vector<vector<int>> &queries)
{
    int n = nums.size();
    int m = queries.size();
    vector<long long> marking(n, 0);
    vector<long long> ans;
    for (int i = 0; i < m; i++)
    {
        int index = queries[i][0];
        int count = queries[i][1];
        if (marking[index] == 0)
        {
            marking[index] = 1;
        }
        smallestNumSmallestInd(nums, marking, count);
        ans.push_back(ansCal(nums, marking));
    }
    return ans;
}
int main()
{
    vector<int> nums = {1, 2, 2, 1, 2, 3, 1};
    vector<vector<int>> queries = {{1, 2}, {3, 3}, {4, 2}};
    for (auto i : unmarkedSumArray(nums, queries))
    {
        cout << i << " ";
    }
    return 0;
}