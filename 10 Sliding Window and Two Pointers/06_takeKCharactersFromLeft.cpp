#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> freq, int k)
{
    for (auto i : freq)
    {
        if (i < k)
        {
            return true;
        }
    }
    return false;
}

int takeCharacters(string s, int k)
{
    vector<int> freq(3, 0);
    for (auto i : s)
    {
        // this below line will convert a to 0, b to 1 , c to 2 and vice versa
        freq[i - 'a']++;
    }
    if (check(freq,k))
    {
        return -1;
    }
    
    int i = 0;
    int j = 0;
    int n = s.length();
    int ulPart = 0;
    while (j < n)
    {
        freq[s[j] - 'a']--;
        while (check(freq, k))
        {
            freq[s[i] - 'a']++;
            i++;
        }
        ulPart = max(ulPart, j - i + 1);
        j++;
    }
    int ans = s.length() - ulPart;

    return ans;
}
int main()
{
    string s = "a";
    int k = 1;
    cout<<takeCharacters(s,k);
    return 0;
}