#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &nums)
{
    int n = nums.size();
    stack<int> stk;
    vector<int> nse(n, -1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!stk.empty() && stk.top() >= nums[i])
        {
            stk.pop();
        }
        if (!stk.empty() && stk.top() < nums[i])
        {
            nse[i] = stk.top();
        }
        stk.push(nums[i]);
    }
    return nse;
}

int main()
{
    vector<int> nums = {5, 6, 2, 3, 1, 7};
    for (auto i : nextSmallerElement(nums))
    {
        cout << i << " ";
    }
    return 0;
}