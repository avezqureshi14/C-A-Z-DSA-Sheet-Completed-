#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals, vector<vector<int>> &result)
{

    int n = intervals.size();
    sort(intervals.begin(), intervals.end());

    vector<int> temp = intervals[0];
    for (auto i : intervals)
    {
        // in this approach we are creating intervals as we are walking
        if (temp[1] >= i[0])
        {
            temp[1] = max(temp[1], i[1]);
        }
        else
        {
            result.push_back(temp);
            temp = i;
        }
    }
    result.push_back(temp);
    return result;
}
int numberOfPoints(vector<vector<int>> &nums)
{
    vector<vector<int>> result;
    merge(nums, result);
    int ans = 0;
    for (auto i : result)
    {
        ans = ans + (i[1] - i[0] + 1);
    }
    return ans;
}
int main()
{
    vector<vector<int>> ranges = {{3,6}, {1, 5}, {4, 7}};
    cout << numberOfPoints(ranges);
    return 0;
}