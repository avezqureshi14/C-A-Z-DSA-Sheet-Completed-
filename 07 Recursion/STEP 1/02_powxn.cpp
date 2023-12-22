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
        
        cout<<num<<" Y"<<endl;
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

double myPowRecu(double x, int n){
    double ans = 1.0;
    long long num = n;
    if (num < 0)
    {
        -1 * num;
    }
    ans = solve(x,ans,num);
    if(n<0){
        ans = double(1.0) / double(ans);
    }
    return ans  ;
}

int main()
{
    cout << myPow(12, 21);

    return 0;
}