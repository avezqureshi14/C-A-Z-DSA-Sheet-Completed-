#include <iostream>
#include <bits/stdc++.h>
using namespace std;

double myPow(double x, int n)
{
    double ans = 1.0;
    long long num = n;
    if (num < 0)
    {
        -1 * num;
    }
    while (num)
    {
        //if the number is odd then do this 
        if (num % 2)
        {
            ans = ans * x;
            num = num - 1;
        }
        else
        {
            x = x * x;
            num = num / 2;
        }
    }
    if (n < 0)
    {
        ans = (double)(1.0) / (double)(ans);
    }
    return ans;
}

double solve(double x, double ans, long long num){
    if (num < 1)
    {
        return ans;
    }
    //odd then
    if (num % 2)
    {
       return solve(x,ans*x,num-1);
    }
    //if even then
    else{
       return solve(x*x,ans,num/2);
    }
}

//what is modulus

long long countGoodNum(int n)
{
    int evens = 0;
    int odds = 0;
    long long evenGood = 0;
    long long oddGood = 0;
    if (n % 2 == 0)
    {
        evens = n / 2;
        odds = n / 2;
    }
    else
    {
        evens = n / 2 + 1;
        odds = n / 2;
    }

    evenGood = myPow(5, evens);
    oddGood = myPow(4, odds);

    long long ans = evenGood * oddGood;
    return ans;
}
int main()
{
    cout<<countGoodNum(4);
    return 0;
}