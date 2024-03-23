#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int> &nums)
{
    int n = nums.size();
    stack<int> stk;
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!stk.empty() && stk.top() < nums[i])
        {
            stk.pop();
        }
        if (!stk.empty())
        {
            ans[i] = stk.top();
        }
        else
        {
            ans[i] = -1;
        }
        stk.push(nums[i]);
    }
    return ans;
}

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    vector<int> ans(n);
    vector<int> nge = solve(nums2);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < nums2.size(); j++)
        {
            if (nums1[i] == nums2[j])
            {
                ans[i] = nge[j];
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> nums1 = {2, 4};
    vector<int> nums2 = {1, 2, 3, 4};
    for (auto i : nextGreaterElement(nums1, nums2))
    {
        cout << i << " ";
    }
    return 0;
}