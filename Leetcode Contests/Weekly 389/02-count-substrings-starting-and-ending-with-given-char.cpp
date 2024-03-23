#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long countSubstringsII(string s, char c)
{
    long long count = 0;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            string substring = s.substr(i, j - i);
            int start = substring[0];
            int end = substring[substring.length() - 1];
            if (start == c && end == c)
            {
                count++;
            }
        }
    }
    return count;
}
long long countSubstrings(string s, char c)
{
    long long count = 0;
    int n = s.length();
    int countOfC = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == c)
        {
            countOfC++;
        }
    }

    count = (long long)countOfC * (countOfC + 1) / 2;

    return count;
}

int main()
{
    string s = "zzz";
    char c = 'z';
    cout << countSubstrings(s, c);
    return 0;
}