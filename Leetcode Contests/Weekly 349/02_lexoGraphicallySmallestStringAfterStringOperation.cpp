#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string smallestStringII(string s)
{
    int i = 0;

    while (i < s.size() && s[i] == 'a')
    {
        i++;
    }

    //if consider the given string is "aaaa" then its answer will be "aaaz"
    if (i >= s.size())
    {
        s[s.size() - 1] = 'z';
        return s;
    }
    while (i < s.size() && s[i] != 'a')
    {
        s[i]--;
        i++;
    }
    return s;
}
string smallestString(string s)
{
    int n = s.length();
    string ans;
    int i = 0;
    int j = 1;
    while (i < n)
    {
        char ch = s[i];

        if (ch == 'a')
        {
            ans.push_back(ch);
        }
        else if (s[i - j] == 'a' && i - 1 != 0)
        {
            ans.push_back(ch);
            j++;
        }
        else
        {

            char newCh = (((ch - 'a') - 1) + 'a');
            ans.push_back(newCh);
        }
        i++;
    }
    return ans;
}
int main()
{
    string s = "aaaaa";
    cout << smallestStringII(s);
    return 0;
}