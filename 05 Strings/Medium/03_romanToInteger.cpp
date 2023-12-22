#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int romanToInteger(string s)
{
    unordered_map<char, int> map = {{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};
    int ans = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (map[s[i]] < map[s[i + 1]])
        {
            ans = ans - map[s[i]];
        }
        else
        {
            ans = ans + map[s[i]];
        }
    }

    return ans;
}
int main()
{
    string s = "MCMXCIV";
    cout<<"The Integer of given Roman Numbers is "<<romanToInteger(s);
    return 0;
}