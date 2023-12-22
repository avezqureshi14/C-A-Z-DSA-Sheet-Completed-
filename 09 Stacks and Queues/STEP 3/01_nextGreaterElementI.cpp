#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> ans;
    unordered_map<int, int> map;
    stack<int> stk;
    int n = nums2.size();
    for (int i = 0; i < n; i++) 
    {
        while (!stk.empty() && stk.top() < nums2[i])
        {
            map[stk.top()] = nums2[i];
            stk.pop();
        }
        stk.push(nums2[i]);
    }
    while (!stk.empty())
    {
        map[stk.top()] = -1;
        stk.pop();
    }
    for (int i = 0; i < nums1.size(); i++)
    {
        ans.push_back(map[nums1[i]]);
    }
    return ans;
}

int main()
{
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    for (auto i : nextGreaterElement(nums1, nums2))
    {
        cout << i << " ";
    }
    return 0;
}
