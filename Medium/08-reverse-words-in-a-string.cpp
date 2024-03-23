#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string reverseWords(string s)
{
    int n = s.length();
    int i = 0;
    string result = "";
    while (i < n)
    {
        while (i < n && s[i] == ' ')
        {
            i++;
        }
        if (i >= n)
        {
            break;
        }

        int j = i + 1;
        while (j < n && s[j] != ' ')
        {
            j++;
        }
        string sub = s.substr(i, j - i);
        if (result.length() == 0)
        {
            result = sub;
        }
        else
        {
            result = sub + " " + result;
        }
        i = j + 1;
    }
    return result;
}
int main()
{
    string s = "  hello world  ";
    cout << reverseWords(s);
    return 0;
}