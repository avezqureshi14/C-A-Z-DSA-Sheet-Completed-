#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num = 4 ;
    //binary form of odd number always has a 1 at the end and when & operation is performed with 1 it gives 1 and not 0 thats why a odd
    //binary form of even number always has a 0 at the end and when & operation is performed with 1 it gives 0 thats why a even 
    if ((num & 1) == 0)
    {
        cout << "Even" << endl;
    }
    else
    {
        cout << "Odd" << endl;
    }

    return 0;
}