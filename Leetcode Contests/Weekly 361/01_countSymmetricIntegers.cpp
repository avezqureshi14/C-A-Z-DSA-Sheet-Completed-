#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int countDigits(int n)
{
    int count = 0;
    while (n != 0)
    {
        count++;
        n = n / 10;
    }
    return count;
}

int reverseDg(int X)
{
    int Y = 0;
    while (X != 0)
    {
        int digit = X % 10;
        Y = Y * 10 + digit;
        X = X / 10;
    }
    return Y;
}

int halfDgSum(int x, int count)
{
    int temp = 0;
    int sum = 0;
    while (temp != count / 2)
    {
        int digit = x % 10;
        sum = sum + digit;
        x = x / 10;
        temp++;
    }
    return sum;
}

int countSymmetricIntegers(int low, int high)
{
    int ans = 0;
    int leftSum = 0;
    int rightSum = 0;
    for (int i = low; i <= high; i++)
    {
        int count = countDigits(i);
        if (count % 2 == 0)
        {
            int revI = reverseDg(i);
            leftSum = halfDgSum(i, count);
            rightSum = halfDgSum(revI, count);
            if (leftSum == rightSum)
            {
                ans++;
            }
        }
    }
    return ans;
}
int main()
{
    int low = 1200;
    int high = 1230;
    cout<<countSymmetricIntegers(low,high);
    return 0;
}