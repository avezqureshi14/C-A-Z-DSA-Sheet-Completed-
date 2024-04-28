#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool isIsomorphic(string s, string t)
{
    unordered_map<char, char> mpS2T;
    unordered_map<char, char> mpT2S;
    for (int i = 0; i < s.size(); i++)
    {
        if (mpS2T.find(s[i]) != mpS2T.end())
        {
            if (mpS2T[s[i]] != t[i])
            {
                return false;
            }
        }
        else
        {
            if (mpT2S.find(t[i]) != mpT2S.end())
            {
                return false;
            }
        }
        mpS2T[s[i]] = t[i];
        mpT2S[t[i]] = s[i];
    }
    return true;
}
int main()
{
    string s = "paper";
    string t = "title";
    cout << isIsomorphic(s, t);
    return 0;
}