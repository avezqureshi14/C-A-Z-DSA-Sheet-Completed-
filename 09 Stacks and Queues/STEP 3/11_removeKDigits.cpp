#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string findMin(string s1, string s2)
{
    string minVal = min(s1, s2);
    return minVal;
}

void solve(int index, string &num, string &ans, string &ds, int k, int diff)
{

    if (index == num.length())
    {
        if (ds.length() == diff)
        {
            ans = findMin(ans, ds);
        }
        return;
    }
    ds.push_back(num[index]);
    solve(index + 1, num, ans, ds, k, diff);
    ds.pop_back();
    solve(index + 1, num, ans, ds, k, diff);
}

string removeKdigits(string num, int k)
{
    int index = 0;
    string ds;
    string ans = "999999999";
    int diff = num.length() - k;
    solve(index, num, ans, ds, k, diff);

    // Find the position of the first non-zero digit
    int nonZeroPos = ans.find_first_not_of('0');

    // Remove leading zeros by creating a substring starting from the first non-zero digit
    string result = (nonZeroPos != string::npos) ? ans.substr(nonZeroPos) : "0";
    if (result == "")
    {
        result = "0";
    }

    return result;
}

string removeKdigitsII(string num, int k)
{
    string ans;
    for (char &c : num)
    {
        if (ans.size() && ans.back() > c && k)
        {
            ans.pop_back();
            k--;
        }
        //this is necessary if trailing zeroes are going to be added will be only added if th ere is an already digit present in ans 
        if (ans.size() || c != '0')
        {
            ans.push_back(c);
        }
    }
    while (ans.size() && k--)
    {
        ans.pop_back();
    }
    if (ans == "")
    {
        ans = "0";
    }
    return ans;
}

int main()
{
    string s1 = "10200";
    int k = 1;
    cout << removeKdigitsII(s1, k);
    return 0;
}