#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string commonStr(string s1, string s2)
{
    int n = min(s1.length(), s2.length());
    string str;
    for (int i = 0; i < n; i++)
    {
        if (s1[i] == s2[i])
        {
            str.push_back(s1[i]);
        }
        else
        {
            break;
        }
    }
    return str;
}

string longestCommonPrefix(vector<string>& strs){
    string res = strs[0];
    int n = strs.size();
    for (int i = 0; i < n; i++)
    {
        res = commonStr(res,strs[i]);
    }

    return res;
}

int main()
{
    vector<string>strs = {"cir","car"};
    string ans = longestCommonPrefix(strs);
    cout<<ans;
    return 0;
}