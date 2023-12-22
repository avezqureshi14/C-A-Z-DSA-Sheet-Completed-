#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int firstUniqChar(string s){
    int n = s.length();
    unordered_map<char,int>map;
    for(auto i : s){
        map[i]++;
    }
    for (int i = 0; i < n; i++)
    {
        if(map[s[i]]  == 1){
            return i;
        }             
    }
    
    return -1;
}
int main()
{
    string s = "aabb";
    cout<<firstUniqChar(s);
    return 0;
}