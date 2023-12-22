#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findPoisonedDuration(vector<int> &time, int d)
{
    int total_duration = 0;
    int n = time.size();

    for (int i = 1; i < n; i++)
    {
        total_duration += min(d, time[i] - time[i - 1]);
    }

    // Add the last interval duration
    total_duration += d;

    return total_duration;
}

int main()
{
    vector<int> timeSeries = {1, 2};
    int duration = 2;
    findPoisonedDuration(timeSeries, duration);
    return 0;
}