#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int maximumLengthSubstring(string s)
{
    int i = 0;
    int j = 0;
    int n = s.length();
    unordered_map<char, int> mp;
    int maxLen = INT_MIN;
    while (j < n)
    {
        mp[s[j]]++;
        if (mp[s[j]] > 2)
        {
            while (mp[s[j]] > 2)
            {
                mp[s[i]]--;
                i++;
                if (mp[s[i]] == 0)
                {
                    mp.erase(s[i]);
                }
            }
        }
        maxLen = max(maxLen, j - i + 1);
        j++;
    }
    return maxLen;
}
int main()
{
    string s = "aaaa";
    cout << maximumLengthSubstring(s);
    return 0;
}