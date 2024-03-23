#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> maxDepthAfterSplit(string seq)
{
    int n = seq.length();
    vector<int> ans;
    int depth = 0;
    for (int i = 0; i < n; i++)
    {
        if (seq[i] == '(')
        {
            depth++;
        }
        ans.push_back(depth % 2);
        if (seq[i] == ')')
        {
            depth--;
        }
    }
    return ans;
}

int main()
{
    string seq = "(()())";
    for (auto i : maxDepthAfterSplit(seq))
    {
        cout << i << " ";
    }
    return 0;
}