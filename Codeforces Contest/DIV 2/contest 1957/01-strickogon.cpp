#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    vector<int> ans;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        for (auto i : nums)
        {
            mp[i]++;
        }
        int count = 0;
        for (auto i : mp)
        {
            count = count + i.second / 3;
        }
        ans.push_back(count);
    }
    for (auto i : ans)
    {
        cout << i << endl;
    }

    return 0;
}