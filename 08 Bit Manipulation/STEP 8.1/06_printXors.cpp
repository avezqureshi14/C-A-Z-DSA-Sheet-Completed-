#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//xor from 1 to n
int XorOf(int num){
    if (num % 4 == 0)
    {
        return num;
    }else if(num % 4 == 1){
        return 1;
    }
    else if(num % 4 == 2){
        return num + 1;
    }
    else if(num % 4 == 3){
        return 0;
    }
    return -1;
}

//xor from range l to r
int xorOfRange(int l, int r){
   return XorOf(r) ^ XorOf(l-1);
}
int main()
{
    cout<<xorOfRange(3,6);
}