#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> printDivisors(int n)
{
    vector<int> ans;
    for (int i = 1; i < sqrt(n); i++)
    {
        if (n % i == 0)
        {
            ans.push_back(i);
        }
        if (n / i != i)
        {
            ans.push_back(n / i);
        }
    }
    return ans;
}
int main()
{
    for (auto i : printDivisors(36))
    {
        cout << i << " ";
    }
    return 0;
}