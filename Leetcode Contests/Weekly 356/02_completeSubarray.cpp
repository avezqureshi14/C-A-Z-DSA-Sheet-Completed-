#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int completeSubarrays(vector<int> nums)
{
    int n = nums.size();
    map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        map[nums[i]]++;
    }
    int d = map.size();
    map.clear();
    int c = 0;
    vector<int> ans;
    vector<vector<int>> result;
    for (int i = 0; i < n; i++)
    {
        map[nums[i]]++;
        for (int j = i; j < n; j++)
        {
            ans.push_back(nums[j]);
            map[nums[j]]++;
            if (map.size() == d)
            {
                c++;
                result.push_back(ans);
            }
        }
        map.clear();
        ans.clear();
    }
    for (auto i : result)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    cout<<endl;
    cout<<endl;
    return c;
}

int main()
{
    vector<int> nums = {1,3,1,2,2};
    cout << completeSubarrays(nums);
    return 0;
}