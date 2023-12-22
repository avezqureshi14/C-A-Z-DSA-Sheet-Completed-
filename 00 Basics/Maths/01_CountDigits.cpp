#include <iostream>
using namespace std;
int countDigits(int n)
{
    int count = 0;
    while (n != 0)
    {
        n = n / 10;
        count++;
    }

    return count;
}
int main()
{
    int n = 547856;
    cout<<"The number of digits in given number are "<<countDigits(n);
    return 0;
}