#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// we want only contiguous subsequence

int minNum(vector<int> &nums)
{
    int min_val = *min_element(nums.begin(), nums.end());
    return min_val;
}

int sumSubarrayMins(vector<int> &nums)
{
    vector<int> ds;
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        ds.clear();
        for (int j = i; j < n; j++)
        {
            ds.push_back(nums[j]);
            sum = sum + minNum(ds);
        }
    }
    return sum;
}

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

int main()
{
    vector<int> nums = {1,2,3};
    cout << sumSubarrayMinsII(nums);
    return 0;
}