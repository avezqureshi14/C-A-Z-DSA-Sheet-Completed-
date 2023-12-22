#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int mexAnized(int n, int k, int x)
{
    int i = 0;
    int maxSum = 0;
    int size = 0;
    while (size != n)
    {
        // cout<<i<<" ";
        if (i != k)
        {
            maxSum = maxSum + i;
        }
        if (i < x-1)
        {
            i++;
        }
        size++;
    }
    if (size == n)
    {
        return maxSum;
    }
    else
    {
        return -1;
    }
}
int main()
{
    int n = 4;
    int k = 7;
    int x = 5;
    cout<<mexAnized(n, k, x);
    return 0;
}