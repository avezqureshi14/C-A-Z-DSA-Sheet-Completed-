#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;

int merge(vector<vector<int>> &intervals)
{

    int n = intervals.size();
    sort(intervals.begin(), intervals.end());

    long long ans = 2;
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
            temp = i;
            ans = (ans * 2) % MOD;
        }
    }
    return ans;
}
int countWays(vector<vector<int>> &ranges)
{
    int ans = merge(ranges);
    return ans;
}
int main()
{
    vector<vector<int>> ranges = {{1, 3}, {10, 20}, {2, 5}, {4, 8}};
    cout << countWays(ranges);
    return 0;
}