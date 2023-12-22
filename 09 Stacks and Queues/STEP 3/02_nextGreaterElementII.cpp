#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// remember my brother, that this is a circular array, and here we have to create an illusion by doing i%n
vector<int> nextGreaterElementII(vector<int> &nums)
{
    stack<int> stk;
    int n = nums.size();
    vector<int> nge(n,-1);
    for (int i = 2 * n - 1 ; i >= 0; i--)
    {
        while (!stk.empty() && stk.top() <= nums[i % n])
        {
            stk.pop();
        }
        if (!stk.empty() && i < n)
        {
            nge[i] = stk.top();
        }
        stk.push(nums[i%n]);
    }
    return nge;
}

int main()
{
    vector<int> nums = {1,2,1};
    for (auto i : nextGreaterElementII(nums))
    {
        cout << i << " ";
    }
    return 0;
}