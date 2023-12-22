#include <iostream>
#include <unordered_map>
using namespace std;

char highestCount(unordered_map<char, int> &map)
{
    int highestCount = 0;
    char elementWithHighestCount = '\0'; // Initialize with null character

    for (const auto &pair : map)
    {
        if (pair.second > highestCount)
        {
            highestCount = pair.second;
            elementWithHighestCount = pair.first;
        }
    }
    return elementWithHighestCount;
}

int longestRepeatingCharacterRepl(string s, int k)
{
    int left = 0;
    int right = 0;
    int repl = 0;
    int n = s.length();
    int longest = 0;
    unordered_map<char, int> map;
    for (auto i : s)
    {
        map[i]++;
    }

    char ch = highestCount(map);
    cout << ch;

    for (right = 0; right < n; right++)
    {
        if (s[right] != ch)
        {
            map[s[right]]++;
            repl++;
        }
        while (repl > k)
        {
            if (s[left] != ch)
            {
                repl--;
            }
            left++;
        }
        longest = max(longest, right - left + 1);
    }
    return longest;
}
// crcm = current replacement can be made
int longestRepeatingCharacterReplII(string s, int k)
{
    int left = 0;
    int right = 0;
    int maxCount = 0;
    int longest = 0;
    int n = s.length();
    unordered_map<char, int> charCount;
    for (int right = 0; right < n; right++)
    {
        charCount[s[right]]++;
        maxCount = max(maxCount, charCount[s[right]]);
        int crcm = (right - left + 1) - maxCount;
        if (crcm > k)
        {
            left++;
            charCount[s[left]]--;
        }
        longest = max(longest, right - left + 1);
    }
    return longest;
}

int main()
{
    string s = "KRSCDCSONAJNHLBMDQGIFCPEKPOHQIHLTDIQGEKLRLCQNBOHNDQGHJPNDQPERNFSSSRDEQLFPCCCARFMDLHADJADAGNNSBNCJQOF";
    int k = 4;
    cout << longestRepeatingCharacterReplII(s, k);
    return 0;
}
