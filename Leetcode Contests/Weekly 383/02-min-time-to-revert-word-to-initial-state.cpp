#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minimumTimeToInitialState(string word, int k)
{
    int n = word.length();
    for (int i = 1; i <= n; i++)
    {
        int d = i * k;
        bool ok = false;
        for (int j = d; j < n; j++)
        {
            if (word[j] != word[j - d])
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            return i;
        }
    }
    return 0;
}

int main()
{

    return 0;
}