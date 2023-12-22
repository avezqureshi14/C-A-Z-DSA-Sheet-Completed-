#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int utilityFunc(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if (day == 0)
    {
        int maxi = 0;
        for (int task = 0; task < 3; task++)
        {
            if (task != last)
            {
                maxi = max(maxi, points[0][task]);
            }
        }
        return maxi;
    }
    if (dp[day][last] != -1)
    {
        return dp[day][last];
    }

    int maxi = 0;
    for (int task = 0; task < 3; task++)
    {
        if (task != last)
        {
            int point = points[day][task] + utilityFunc(day - 1, task, points, dp);
            maxi = max(maxi, point);
            dp[day][last] = maxi;
        }
    }
    return dp[day][last];
}

int maximumPoints(vector<vector<int>> &points, int n)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return utilityFunc(n - 1, 3, points, dp);
}
int main()
{
    vector<vector<int>> points = {{1, 2, 5}, {3, 1, 1}, {3, 3, 3}};
    cout << maximumPoints(points, 3);
    return 0;
}