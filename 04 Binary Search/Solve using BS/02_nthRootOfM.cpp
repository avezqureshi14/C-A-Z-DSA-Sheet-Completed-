#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long NthRoot(long long n, long long  m)
{
    long long low = 0;
    long long high = m;
    int ans = 0;
    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        long long value = 1;
        for (int i = 0; i < n; i++)
        {
            value = value * mid;
        }

        if (value == m)
        {
            ans = mid;
            break;
        }
        else if (value > m)
        {

            high = mid - 1;
        }
        else
        {
            ans = mid;
            low = mid + 1;
        }
    }
    return ans;
}
int main()
{
    long long  n = 6;
    long long m = 4096;
    cout<<"The Nth root of M is "<<NthRoot(n,m);
    return 0;
}