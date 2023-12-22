#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void swapUsingBit(int &a, int &b){
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}
int main()
{
    int a = 5;
    int b = 2;
    swapUsingBit(a,b);
    cout<<a<<" "<<b<<endl;
    return 0;
}