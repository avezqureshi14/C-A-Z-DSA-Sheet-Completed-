#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int minimumDeletions(string word, int k)
{
    vector<int> ans;
    unordered_map<char, int> mp;
    for (auto i : word)
    {
        mp[i]++;
    }
    string aStr = "";
    for (auto i : mp)
    {
        aStr = aStr + i.first;
    }
    int n = aStr.length();
    unordered_set<std::string> subsets;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            string subset = "";
            subset += aStr[i];
            subset += aStr[j];
            subsets.insert(subset);
        }
    }

    for (auto i : subsets)
    {
        char ch1 = i[0];
        char ch2 = i[1];
        int diff = abs(mp[ch1] - mp[ch2]);
        ans.push_back(diff);
    }

    int sol = 0;
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] > k)
        {
            sol++;
        }
    }

    return sol;
}
int main()
{
    string word = "aabcaba";
    int k = 0;
    cout << minimumDeletions(word, k);
    return 0;
}