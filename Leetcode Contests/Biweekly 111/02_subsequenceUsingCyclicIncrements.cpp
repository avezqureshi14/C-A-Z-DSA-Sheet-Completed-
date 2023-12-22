#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// cyclic alphabets (str1[i] - 'a' + 1) % 26) + 'a'

void solve(int index, string &s, vector<string> &subsequence, string &sequence)
{
    if (index == s.length())
    {
        subsequence.push_back(sequence);
        return;
    }
    sequence.push_back(s[index]);
    solve(index + 1, s, subsequence, sequence);
    sequence.pop_back();
    solve(index + 1, s, subsequence, sequence);
}

bool canMakeSubsequence(string str1, string str2)
{
    vector<string> subsequence;
    string sequence;
    int n1 = str1.length();
    string str3;
    for (auto i : str1)
    {
        str3.push_back(i);
    }
    for (int i = 0; i < n1; i++)
    {
        if (str1[i] == 'z')
        {
            str3.push_back('a');
        }
        else
        {
            str3.push_back(str1[i] + 1);
        }
    }
    int index = 0;
    solve(index, str3, subsequence, sequence);
    for (auto i : subsequence)
    {
        sort(i.begin(), i.end());
        cout << i << " ";
        if (i == str2)
        {
            return true;
        }
    }

    return false;
}

bool canMakeSubsequenceII(string str1, string str2)
{
    int n1 = str1.length();
    int n2 = str2.length();
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (str1[i] == str2[j] || ((str1[i] - 'a' + 1) % 26) + 'a' == str2[j])
        {
            j++;
        }
        i++;
    }
    return j == n2;
}

int main()
{
    string str1 = "eao";
    string str2 = "ofa";
    if (canMakeSubsequence(str1, str2))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}