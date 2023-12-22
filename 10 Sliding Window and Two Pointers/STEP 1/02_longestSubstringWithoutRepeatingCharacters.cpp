#include <iostream>
#include <unordered_map>
using namespace std;

int longestSubstringWithoutRepeatChar(string s)
{
    int i = 0;
    int j = 0;
    int n = s.length();
    int maxi = 0;
    unordered_map<char, int> map;
    while (j < n)
    {
        map[s[j]]++;
        //this condition will never be reached 
        if (map.size() > j - i + 1)
        {
            j++;
        }
        else if (map.size() == j - i + 1)
        {
            maxi = max(maxi, j - i + 1);
            j++;
        }
        else if (map.size() < j - i + 1)
        {
            while (map.size() < j - i + 1)
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
    string s = "aabacbebebe";
    cout << longestSubstringWithoutRepeatChar(s);
    return 0;
}
