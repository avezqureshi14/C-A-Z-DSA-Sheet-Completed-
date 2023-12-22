#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool checkIfPowerOfTwo(int n){
    return (n & (n - 1)) == 0;
}

int main()
{
    int n = 8;
    cout<<checkIfPowerOfTwo(n);
    return 0;
}