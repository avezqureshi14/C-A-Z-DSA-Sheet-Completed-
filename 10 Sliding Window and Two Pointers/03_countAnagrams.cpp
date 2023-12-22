#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isAnagram(const string &ptr, const deque<char> &check)
{
    unordered_map<char, int> ptrCount;
    unordered_map<char, int> checkCount;

    for (char c : ptr)
        ptrCount[c]++;

    for (char c : check)
        checkCount[c]++;

    return ptrCount == checkCount;
}

int countAnagrams(const string &s, const string &ptr)
{
    int k = ptr.length();
    deque<char> window;
    for (int i = 0; i < k; i++)
    {
        window.push_back(s[i]);
    }

    int count = 0;
    if (isAnagram(ptr, window))
    {
        count++;
    }

    for (int i = k; i < s.length(); i++)
    {
        if (window.front() == s[i - k])
        {
            window.pop_front();
        }
        window.push_back(s[i]);
        if (isAnagram(ptr, window))
        {
            count++;
        }
    }

    return count;
}

int countAnagramsII(string &s, string &ptr)
{
    int n = s.length();
    int k = ptr.length();
    vector<int> windowCount(26,0);
    vector<int> ptrCount(26,0);
    for (int i = 0; i < k; i++)
    {
        windowCount[s[i] - 'a']++;
        ptrCount[ptr[i] - 'a']++;
    }
      
    int count = 0;
    if (ptrCount == windowCount)
    {
        count++;
    }
    for (int i = k; i < n; i++)
    {
        //this is been done to remove the out of window elements from the left 
        windowCount[s[i - k] - 'a']--;
        //this is been done to increase the length of window from right
        windowCount[s[i] - 'a']++;
        if (ptrCount == windowCount)
        {
            count++;
        }

    }


    cout<<endl;
    return count;
}

int main()
{
    string s = "forxorfxdofr";
    string ptr = "for";
    cout << countAnagramsII(s, ptr);

    return 0;
}
