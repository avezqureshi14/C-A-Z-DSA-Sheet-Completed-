#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        count += n & 1;
        n >>= 1; // Right shift n by 1 to check the next bit
    }
    return count;
}
int main()
{
    int n = 21;
    cout<<countSetBits(n);
    return 0;
}