#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string unMatchedString(string &str1, string &str2)
{
    int n = str1.length();
    int m = str2.length();
    string ans = "";
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            string substring = str1.substr(i, j - i);
            if (str2.find(substring) == string::npos)
            {
                if (flag == false)
                {
                    ans = substring;
                    flag = true;
                }
                else if (substring.compare(ans) < 0)
                {
                    ans = substring;
                }
            }
        }
    }
    cout << endl;
    return ans;
}

vector<string> shortestSubstrings(vector<string> &arr)
{
    int n = arr.size();
    vector<string> ans;
    string ansStr;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i] != arr[j])
            {
                ansStr = unMatchedString(arr[i], arr[j]);
            }
        }
        ans.push_back(ansStr);
    }
    return ans;
}
int main()
{
    vector<string> arr = {"cab", "ad", "bad", "c"};
    for (auto i : shortestSubstrings(arr))
    {
        cout << i << " ";
    }
    return 0;
}