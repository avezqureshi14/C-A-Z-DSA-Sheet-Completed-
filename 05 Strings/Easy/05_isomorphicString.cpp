#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// This will work but not each testcase, it does not checks one - to - one mapping
bool isomorphicString(string str1, string str2)
{
    int n = str1.length();
    int m = str2.length();

    if (n != m)
    {
        return false;
    }
    int i = 0;
    int j = 0;
    unordered_map<char, int> m1;
    unordered_map<char, int> m2;
    for (int i = 0; i < n; i++)
    {
        m1[str1[i]]++;
        m2[str2[i]]++;
    }

    if (m1.size() == m2.size())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isIsomorphic(string s, string t)
{
    if (s.size() != t.size())
    {
        return false;
    }

    unordered_map<char, char> mapping;
    unordered_map<char, bool> checking;

    for (int i = 0; i < s.size(); i++)
    {
        char sChar = s[i];
        char tChar = t[i];

        if (mapping.find(sChar) == mapping.end() && checking.find(tChar) == checking.end())
        {
            mapping[sChar] = tChar;
            checking[tChar] = true;
        }
        else if (mapping.find(sChar) != mapping.end() && mapping[sChar] != tChar)
        {
            return false;
        }
        else if (checking.find(tChar) != checking.end() && mapping[sChar] != tChar)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string str1 = "paper";
    string str2 = "title";
    if (isIsomorphic(str1, str2))
    {
        cout << "Yes the given strings are isomorphic" << endl;
    }
    else
    {
        cout << "No the given strings are not isomorphic" << endl;
    }

    return 0;
}