#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// when we divide it we say logarithmic
bool isPrime(int n)
{
    int count = 0;
    for (int i = 1; i < sqrt(n); i++)
    {
        if (n % i == 0)
        {
            count++;
        }
        if (n / i != i)
        {
            count++;
        }
        if (count > 2)
        {
            return false;
        }
    }
    if (count == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    cout << isPrime(36);
    return 0;
}