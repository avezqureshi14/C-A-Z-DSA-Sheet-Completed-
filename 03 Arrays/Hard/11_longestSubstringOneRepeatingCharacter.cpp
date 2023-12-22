#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> longestRepeating(string &s, string queryCharacters, vector<int> &queryIndices)
{
    int n = s.size();
    int k = queryIndices.size();
    vector<int> ans;
    int maxCount = INT_MIN;

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == queryIndices[i])
            {
                s[j] = queryCharacters[i];
            }
        }
        int count = 1;
        for (int j = 0; j < n - 1; j++)
        {
            if (s[j] == s[j + 1])
            {
                count++;
            }
            else
            {
                count = 1;
            }
            maxCount = max(count, maxCount);
        }
        ans.push_back(maxCount);
    }
    return ans;
   
}
int main()
{
    string s = "geuqjmt";
    string queryCharacters = "bgemoegklm";
    vector<int> queryIndices = {3,4,2,6,5,6,5,4,3,2};
    for (auto i : longestRepeating(s, queryCharacters, queryIndices))
    {
        cout << i << " ";
    }
    return 0;
}