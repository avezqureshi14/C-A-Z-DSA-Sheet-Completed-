#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int furthestDistanceFromOrigin(string moves)
{
    int count = 0;
    int i = 1;
    int n = moves.length();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (moves[i] == 'L')
        {
            count++;
            ans--;
        }
        else if (moves[i] == 'R')
        {
            count++;
            ans++;
        }
    }
    int remains  = n - count;
    int rmax = remains + ans;
    int lmax = -remains + ans;
    if (abs(rmax) > abs(lmax))
    {
        ans = rmax;
    }
    else
    {
        ans = lmax;
    }

    return abs(ans);
}
int main()
{
    string moves = "_______";
    cout << furthestDistanceFromOrigin(moves);
    return 0;
}