#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &intervals)
{
    vector<vector<int>> ans;
    int n = intervals.size();
    if (n == 0)
    {
        return ans;
    }
    sort(intervals.begin(), intervals.end());
    vector<int> tempInterval = intervals[0];

    for (auto i : intervals)
    {
        if (i[0] <= tempInterval[1])
        {
            tempInterval[1] = max(i[1], tempInterval[1]);
        }
        else
        {
            ans.push_back(tempInterval);
            tempInterval = i;
        }
    }
    ans.push_back(tempInterval);
    return ans;
}
int main()
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    for (auto i : mergeOverlappingIntervals(intervals))
    {
        cout << endl;
        for (auto j : i)
        {
            cout << j << " ";
        }
    }
    return 0;
}