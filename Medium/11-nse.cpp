#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> prevSmaller(vector<int> &nums)
{
    int n = nums.size();
    stack<int> stk;
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++)
    {
        while (!stk.empty() && stk.top() >= nums[i])
        {
            stk.pop();
        }
        if (!stk.empty())
        {
            ans[i] = stk.top();
        }
        stk.push(nums[i]);
    }
    return ans;
}
int main()
{
    vector<int> nums = {4, 5, 2, 10, 8};
    for (auto i : prevSmaller(nums))
    {
        cout << i << " ";
    }
    return 0;
}