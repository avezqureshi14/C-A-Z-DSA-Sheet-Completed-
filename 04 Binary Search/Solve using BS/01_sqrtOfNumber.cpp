#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long int floorSqrt(long long int x)
{
    // Your code goes here
    long long int low = 0;
    long long int high = x;

    long long int ans;

    while (low <= high)
    {
        long long int mid = low + (high - low) / 2;
        long long int value = mid * mid;
        if (value == x)
        {
            ans = mid;
            low = mid + 1;
        }

        else if (value > x)
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
    int num = 25;
    cout << "The Square root of the given number is " << floorSqrt(num);
    return 0;
}