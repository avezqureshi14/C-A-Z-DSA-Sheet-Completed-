#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElements(vector<int> &nums)
{
    int n = nums.size();
    stack<int> stk;
    vector<int> ans(n);
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        while (!stk.empty() && stk.top() <= nums[i % n])
        {
            stk.pop();
        }
        if (!stk.empty())
        {
            ans[i] = stk.top();
        }

        stk.push(nums[i % n]);
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 3};
    for (auto i : nextGreaterElements(nums))
    {
        cout << i << " ";
    }
    return 0;
}