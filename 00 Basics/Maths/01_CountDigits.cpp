#include <iostream>
using namespace std;
// modulo - give last digits
// division - remove last digit
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
    cout << "The number of digits in given number are " << countDigits(n);
    return 0;
}