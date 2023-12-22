#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int i, int j)
{
    while (i <= j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

void solveString(int index, string &s1, vector<vector<string>> &result, vector<string> &ans)
{
    if (index == s1.size())
    {
        result.push_back(ans);
        return;
    }

    for (int i = index; i <= s1.size(); i++)
    {
        if (isPalindrome(s1, index, i))
        {
            ans.push_back(s1.substr(index, i - index + 1));
            solveString(i + 1, s1, result, ans);
            ans.pop_back();
        }
    }

}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> result;
    vector<string> ans;
    solveString(0, s, result, ans);
    return result;
}
int main()
{
    string s = "aab";
    for (auto i : partition(s))
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}