#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<string> splitWordsBySeparator(vector<string> &words, char separator)
{
    int n = words.size();
    vector<string> ans;
    for (int i = 0; i < n; i++)
    {
        string s = words[i];
        string temp = "";
        for (auto j : s)
        {
            if (j == separator && temp != "")
            {
                ans.push_back(temp);
                temp = "";
            }
            if (j != separator)
            {
                temp = temp + j;
            }
        }
        if (temp != "")
        {
            ans.push_back(temp);
        }
    }
    return ans;
}

vector<string> splitWordsBySeparatorII(vector<string> &words, char separator)
{
    vector<string> ans;
    for (int i = 0; i < words.size(); i++)
    {
        string s = words[i];
        string temp = "";

        for (auto a : s)
        {
            if (a == separator && temp != "")
            {
                ans.push_back(temp);
                temp = "";
            }
            if (a != separator)
                temp += a;
        }
        if (temp != "")
            ans.push_back(temp);
    }
    return ans;
}
int main()
{
    vector<string> words = {"one.two.three", "four.five", "six"};
    char separator = '.';
    for (auto i : splitWordsBySeparator(words, separator))
    {
        cout << i << " ";
    }
    return 0;
}