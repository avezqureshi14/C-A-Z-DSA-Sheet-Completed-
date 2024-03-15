#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string toLowerCase(const string &str)
{
    string result = str;
    for (char &c : result)
    {
        c = tolower(c);
    }
    return result;
}
int countKeyChanges(string s)
{
    string lowered = toLowerCase(s);
    int count = 0;
    for (int i = 0; i < lowered.length() - 1; i++)
    {
        if (lowered[i] != lowered[i + 1])
        {
            count++;
        }
    }
    return count;
}
int main()
{
    string s = "mDVD";
    cout << countKeyChanges(s);
    return 0;
}