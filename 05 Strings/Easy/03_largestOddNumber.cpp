#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string largestOddNumber(string n)
{
    char a = '0';
    int m;
    for (int i = n.size() - 1; i >= 0; i--)
    {
        m = n[i] - '0';
        if (m % 2 != 0)
        {
            return n.substr(0, i + 1);
        }
    }
    return "";
}

int main()
{
    string str = "524";
    string ans = largestOddNumber(str);
    cout << ans << " This is the largest number " << endl;
    return 0;
}