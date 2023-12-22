#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool compare(const pair<int,char>& a, const pair<int ,char>& b) {
    return a.first > b.first; // sort in descending order of counts
}

string frequencySort(string &s)
{
    int n = s.length();
    map<char, int> map;
    for (int i = 0; i < n; i++)
    {
        map[s[i]]++;
    }
    vector<pair<int, char>> ourMap;
    for (auto it = map.begin(); it != map.end(); ++it)
    {
        char value = it->first;
        int count = it->second;
        ourMap.push_back({it->second,it->first});
        sort(ourMap.begin(), ourMap.end());
    }
    s.clear();
    for(auto i : ourMap){
        int count = i.first;
        for (int j = 0; j < count; j++)
        {
            s.push_back(i.second);
        }
    }   
    reverse(s.begin(),s.end());
    return s;
}
int main()
{
    string s = "tree";
    cout << frequencySort(s);
    return 0;
}



// The time complexity of the frequencySort function is O(n log n), where n is the length of the input string s. This is because the function first creates a map of character counts, which takes O(n) time. Then, it creates a vector of pairs and sorts it based on the count, which takes O(n log n) time. Finally, it loops through the vector and rebuilds the string, which takes O(n) time.