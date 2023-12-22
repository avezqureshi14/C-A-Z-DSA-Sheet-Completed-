#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> insertIntervals(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    intervals.push_back(newInterval);
    vector<vector<int>> res;
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<int> tempIntervals = intervals[0];
    for (auto i : intervals)
    {
        if (tempIntervals[1] >= i[0])
        {
            tempIntervals[1] = max(tempIntervals[1], i[1]);
        }
        else
        {
            res.push_back(tempIntervals);
            tempIntervals = i;
        }
    }

    res.push_back(tempIntervals);
    return res;
}
int main()
{
    vector<vector<int>> intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int>interval = {4,8};
    for (auto i : insertIntervals(intervals,interval))
    {
        cout << endl;
        for (auto j : i)
        {
            cout << j << " ";
        }
    }
    return 0;
}