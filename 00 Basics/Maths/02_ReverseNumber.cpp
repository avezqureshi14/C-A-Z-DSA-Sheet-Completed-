#include <iostream>
using namespace std;
int reverseNumber(int n)
{
    int num = n;
    int newNum = 0;
    while (num)
    {
        int digit = num % 10;
        newNum = newNum * 10 + digit;
        num = num / 10;
    }
    return newNum;
}
int main()
{
    int num = 778900;
    cout << reverseNumber(num);
    return 0;
}