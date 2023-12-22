#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool isFascinating(int n)
{
    unordered_map<char, int> map;
    int totalSum = 0;
    int n2 = n * 2;
    int n3 = n * 3;
    string nStr = to_string(n);
    string n2Str = to_string(n2);
    string n3Str = to_string(n3);
    string s = nStr + n2Str + n3Str;
    for (auto i : s)
    {
        totalSum += i - '0';
    }
    if (totalSum != 45)
    {
        return false;
    }
    for (auto i : s)
    {
        if (i == '0')
        {
            return false;
        }
        map[i]++;
    }
    if (map.size() == 9)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    if (isFascinating(327))
    {
        cout << "Yeah" << endl;
    }
    else
    {
        cout << "Nope" << endl;
    }
    return 0;
}