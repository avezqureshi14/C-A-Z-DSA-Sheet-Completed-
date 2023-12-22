#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a = 5;
    int b = 6;
    int c = 7;
    int d = 1;
    int andOp = a&b;
    int orOp = a|b;
    //even 1 = 0, odd 1 = 1 
    int xOr = a^b;

    //This operators are named after their tip, if their tip points towards right, right shift and if their tip points towards left, left shift 

    //pop out 0 and 1 from the back
    int rightShift = c>>d;

    //zeroes gets pushed backward
    int leftShift = c<<d;
    cout<<leftShift;
    return 0;
}