#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool startsWith(string &str, string &prefix)
{
    return str.compare(0, prefix.length(), prefix) == 0;
}

bool endsWith(string &str, string &suffix)
{
    return str.compare(str.length() - suffix.length(), suffix.length(), suffix) == 0
}

int countPrefixSuffixPairs(vector<string> &words)
{
    int n = words.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            
        }
    }
}
int main()
{

    return 0;
}