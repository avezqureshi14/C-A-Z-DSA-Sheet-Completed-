
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool checkStrings(string s1, string s2)
{
    int n = s1.length();
    if (s1 == s2)
    {
        return true;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((j - i) % 2 == 0 && s1[i] != s2[i])
            {
                swap(s1[i], s1[j]);
                if (s1 == s2)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
int main()
{
    string s1 = "ublnlasppynwgx";
    string s2 = "ganplbuylnswpx";
    cout<<checkStrings(s1,s2);

    return 0;
}