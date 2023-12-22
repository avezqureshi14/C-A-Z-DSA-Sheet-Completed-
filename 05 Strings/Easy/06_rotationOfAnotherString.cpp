#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool compareStrings(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();
    for (int i = 0; i < n; i++)
    {
        if (s1[i] != s2[i])
        {
            return false;
        }
    }

    return true;
}

bool rotateString(string s, string goal)
{
    int n = s.length();
    int m = goal.length();
    if (n != m)
    {
        return false;
    }
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        string rotated = s.substr(i) + s.substr(0, i);
        if (compareStrings(rotated, goal))
        {
            return true;
        }
    }

    return false;
}

//KMP algo
bool rotateStringII(string s, string goal){
    int n = s.length();
    int m = goal.length();
    if (n != m)
    {
        return false;
    }
    string text = s + s;
    if (text.find(goal) != string::npos)
    {
        return true;
    }
    return false;
}

int main()
{
    string s = "abcde";
    string goal = "abced";
    if (rotateStringII(s, goal))
    {
        cout << "The String is Rotated " << endl;
    }
    else
    {
        cout << "The string is not rotated " << endl;
    }
    return 0;
}