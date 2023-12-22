#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Helper function which returns the number of hours required to consume the piles for given K
int hoursRequired(const vector<int> &piles, int k)
{
    int h = 0;
    if (k == 0)
        return INT_MAX;
    for (int i : piles)
    {
        if (i % k != 0)
        {
            h++;
        }
        h += (i / k);
    }
    return h;
}

int minEatingSpeed(vector<int> &piles, int h)
{
    int low = 0;
    int high = INT_MIN;
    int n = piles.size();
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        if (piles[i] < low)
        {
            low = piles[i];
        }
        if (piles[i] > high)
        {
            high = piles[i];
        }
    }
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int required = hoursRequired(piles, mid);
        if (required <= h)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}
int main()
{
    vector<int> piles = {312884470};
    int h = 312884469;
    cout << minEatingSpeed(piles, h);
    return 0;
}