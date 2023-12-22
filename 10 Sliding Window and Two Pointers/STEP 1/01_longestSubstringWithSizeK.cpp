#include <iostream>
#include <unordered_map>
using namespace std;

int longestSubstringWithSizeK(string s, int k)
{
    int i = 0;
    int j = 0;
    int n = s.length();
    int maxi = 0;
    unordered_map<char, int> map;
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
            //we dont have to play by just removing one character in each iteration, becauase there can be duplicates too present that's why we have to remove until it completely gets removed from our map
            while (map.size() > k)
            {
                map[s[i]]--;
                if (map[s[i]] == 0)
                    map.erase(s[i]);
                i++;
            }
            j++;
        }
    }
    return maxi;
}

int main()
{
    string s = "212";
    int k = 2;
    cout << longestSubstringWithSizeK(s, k);
    return 0;
}
