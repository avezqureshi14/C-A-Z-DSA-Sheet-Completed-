#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool isAnagram(string s, string t)
{
    int n = s.size();
    int m = t.size();
    if (n != m)
    {
        return false;
    }
    unordered_map<int, char> map1;
    unordered_map<int, char> map2;
    for (int i = 0; i < n; i++)
    {
        map1[s[i]]++;
        map2[t[i]]++;
    }

    for (auto it = map1.begin(); it != map1.end(); ++it)
    {
        //count is the count of our character to be counted
        int count1 = it->second;
        //key is our character to be counted
        char key = it->first;

        if (map2.find(key) == map2.end() || map2[key] != count1)
        {
            return false;
        }
    }
    return true;
}

bool isAnagramII(string s1, string s2){
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    if (s1.size() != s2.size()) return false;
    return s1 == s2 ? true : false;
}

int main()
{
    string s1 = "garden";
    string s2 = "danger";
    if (isAnagramII(s1, s2))
    {
        cout << "The given string is an Anagram " << endl;
    }
    else
    {
        cout << "The given string is not an Anagram " << endl;
    }
    return 0;
}