#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string finalString(string s)
{
    int n = s.length();
    string ans;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'i')
        {
            reverse(ans.begin(), ans.end());
        }
        else
        {
            ans.push_back(s[i]);
        }
    }
    return ans;
}
int main()
{
    string s = "poiinter";
    string ans = finalString(s);
    for (int i = 0; i < ans.length(); i++)
    {
        cout << ans[i];
    }

    return 0;
}