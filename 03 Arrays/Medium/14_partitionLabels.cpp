#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool allValuesZero(set<char> check, unordered_map<char, int> &map)
{
    for (auto i : check)
    {
        if (map[i] != 0)
        {
            return false;
        }
    }
    return true;
}

vector<int> partitionLabels(string s)
{
    int n = s.length();
    vector<int> ans;
    unordered_map<char, int> map;
    for (auto i : s)
    {
        map[i]++;
    }
    int count = 0;
    set<char> check;
    for (int i = 0; i < n; i++)
    {
        check.insert(s[i]);
        if (map.find(s[i]) != map.end())
        {
            map[s[i]]--;
            count++;
        }
        if(allValuesZero(check,map)){
            ans.push_back(count);
            count = 0;
        }
    }
    return ans;
}
int main()
{
    string s = "eccbbbbdec";
    for(auto i : partitionLabels(s)){
        cout<<i<<" ";
    }
    return 0;
}