#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int minimumSum(int n, int k)
{
    int sum = 0;
    if (n > k)
    {
        sum = n * (n+1) / 2;
        sum = sum + (k-1);
    }
    else{
        sum = n * (n+1) / 2;
    }
    return sum;
}
int main()
{
    int n = 10;
    int k = 5;
    cout<<minimumSum(n,k);
    return 0;
}