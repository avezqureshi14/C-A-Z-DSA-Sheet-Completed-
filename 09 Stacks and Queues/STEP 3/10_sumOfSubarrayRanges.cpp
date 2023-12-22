#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// we want only contiguous subsequence

vector<long> prevSmaller(vector<int> &nums, long n)
{
    stack<pair<int, int>> stk;
    vector<long> left(n);
    for (int i = 0; i < n; i++)
    {
        long cnt = 1;
        while (!stk.empty() && stk.top().first > nums[i])
        {
            cnt += stk.top().second;
            stk.pop();
        }
        stk.push({nums[i], cnt});
        left[i] = cnt;
    }
    return left;
}

vector<long> nextSmaller(vector<int> nums, long n)
{
    stack<pair<int, int>> stk;
    vector<long> right(n);
    for (int i = n - 1; i >= 0; i--)
    {
        int cnt = 1;
        while (!stk.empty() && stk.top().first >= nums[i])
        {
            cnt += stk.top().second;
            stk.pop();
        }
        stk.push({nums[i], cnt});
        right[i] = cnt;
    }

    return right;
}

vector<long> prevGreater(vector<int> &nums, long n)
{
    stack<pair<int, int>> stk;
    vector<long> left(n);
    for (int i = 0; i < n; i++)
    {
        long cnt = 1;
        while (!stk.empty() && stk.top().first < nums[i])
        {
            cnt += stk.top().second;
            stk.pop();
        }
        stk.push({nums[i], cnt});
        left[i] = cnt;
    }
    return left;
}

vector<long> nextGreater(vector<int> nums, long n)
{
    stack<pair<int, int>> stk;
    vector<long> right(n);
    for (int i = n - 1; i >= 0; i--)
    {
        int cnt = 1;
        while (!stk.empty() && stk.top().first <= nums[i])
        {
            cnt += stk.top().second;
            stk.pop();
        }
        stk.push({nums[i], cnt});
        right[i] = cnt;
    }

    return right;
}

int sumSubarrayMinsII(vector<int> &nums)
{
    long n = nums.size();
    const int kMOD = 1000000007;
    vector<long> left = prevSmaller(nums, n);
    vector<long> right = nextSmaller(nums, n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (nums[i] * left[i] * right[i]) % kMOD;
    }
    return sum;
}
int sumSubarrayMaxsII(vector<int> &nums)
{
    long n = nums.size();
    const int kMOD = 1000000007;
    vector<long> left = prevGreater(nums, n);
    vector<long> right = nextGreater(nums, n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (nums[i] * left[i] * right[i]) % kMOD;
    }
    return sum;
}

int main()
{
    vector<int> nums = {4, -2, -3, 4, 1};
    int ans = sumSubarrayMaxsII(nums) - sumSubarrayMinsII(nums);
    cout << ans;
    return 0;
}