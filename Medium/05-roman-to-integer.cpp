#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int romanToInt(string s)
{
    int n = s.length();
    int ans = 0;
    unordered_map<char, int> roman = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };

    for (int i = 0; i < n - 1; i++)
    {
        char a = s[i];
        char b = s[i + 1];
        int val1 = roman[a];
        int val2 = roman[b];
        if (val1 >= val2)
        {
            cout << val1 << " val 1" << endl;
            ans = ans + val1;
            if (i + 1 == n - 1)
            {
                ans = ans + val2;
            }
        }
        else
        {
            ans = ans + (val2 - val1);
            i++;
        }
    }
    return ans;
}

int main()
{
    string s = "MCMXCIV";
    cout << romanToInt(s);

    return 0;
}

// Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four.