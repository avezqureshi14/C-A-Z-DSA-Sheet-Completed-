#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int longestSubstringWithSizeK(vector<int> s, int k)
{
    int i = 0;
    int j = 0;
    int n = s.size();
    int maxi = 0;
    unordered_map<int, int> map;
    while (j < n)
    {
        map[s[j]]++;
        if (map.size() < k)
        {
            j++;
        }
        else if (map.size() == k)
        {
            maxi = max(maxi, j - i + 1);
            j++;
        }
        else if (map.size() > k)
        {
            // we dont have to play by just removing one character in each iteration, becauase there can be duplicates too present that's why we have to remove until it completely gets removed from our map
            while (map.size() > k)
            {
                map[s[i]]--;
                if (map[s[i]] == 0)
                    map.erase(s[i]);
                i++;
            }
            j++;
        }

        if (map.size() == 1)
        {
            maxi = map[s[i]];
        }
    }
    return maxi;
}

int main()
{
    vector<int> s = {1, 1, 1, 1};
    int k = 2;
    cout << longestSubstringWithSizeK(s, k);
    return 0;
}
