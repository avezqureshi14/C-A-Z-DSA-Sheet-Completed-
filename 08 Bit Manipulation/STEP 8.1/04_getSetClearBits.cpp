#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//a bit is set when it is equal to 1
//i from left starting from 0
bool checkSetBit(int n, int i){
    int mask = 1<<i;
    bool set = (mask & n);
    return set;   
}

// Function to get the i-th bit of n (0-based indexing)
int getithBit(int n, int i){
    int mask = 1 << i;
    int bit = (n & mask) >> i;
    return bit;
}

int setIthBit(int n, int i){
    int mask = i << i;
    int bit = (n | mask);
    return bit;
}

int clearithBits(int n, int i){
    int mask = ~(1<<n);
    int bit = (n & mask);
    return bit;
}

int clearLastSetBit(int n){
    int bit = (n & n-1);
    return bit;
}



int main()
{
    int n = 12;
    cout<<clearLastSetBit(n);
    return 0;
}