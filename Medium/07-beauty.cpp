#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solve(string s)
{
    unordered_map<char, int> mp;
    for (auto i : s)
    {
        mp[i]++;
    }
    char miniCh = s[0];
    int mini = mp[s[0]];
    char maxiCh = s[0];
    int maxi = mp[s[0]];
    for (auto i : mp)
    {
        if (i.second < mp[miniCh])
        {
            miniCh = i.first;
            mini = i.second;
        }
        if (i.second > mp[maxiCh])
        {
            maxiCh = i.first;
            maxi = i.second;
        }
    }

    return maxi - mini;
}

int beautySumII(string s)
{
    int n = s.length();
    int result = 0;
    set<string> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            string substring = s.substr(i, j - i);
            if (substring.length() >= 3)
            {
                st.insert(substring);
            }
        }
    }
    for (auto i : st)
    {
        int ans = solve(i);

        if (ans > 0)
        {
            result = result + ans;
        }
    }
    return result;
}
int beautySum(string s)
{
    int n = s.length();
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        unordered_map<char, int> mp;
        for (int j = i; j < n; j++)
        {
            mp[s[j]]++;
            int maxFreq = 0;
            int minFreq = INT_MAX;

            for (auto it : mp)
            {
                maxFreq = max(maxFreq, it.second);
                minFreq = min(minFreq, it.second);
            }
            result += (maxFreq - minFreq);
        }
    }

    return result;
}
int main()
{
    string s = "aabcbaa";
    cout << beautySum(s);
    return 0;
}