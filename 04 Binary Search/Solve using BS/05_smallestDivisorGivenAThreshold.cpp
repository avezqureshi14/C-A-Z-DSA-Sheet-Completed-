#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int check(vector<int> &nums, int divisor)
{
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int val = ceil(double(nums[i]) / divisor);
        sum = sum + val;
    }
    return sum;
}

int smallestDivisor(vector<int> &nums, int threshold)
{
    int low = 1; // start from the lowest as 1 (smallest number to be taken as divisor )
    int high = INT_MIN;
    int n = nums.size();
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > high)
        {
            high = nums[i];
        }
    }
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int sum = check(nums, mid);
        if (sum <= threshold)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}
// optimal this solution is carrying out division in same function without using ceil fucntion
int smallestDivisorII(vector<int> &A, int threshold)
{
    int left = 1, right = 1e6, m, sum;
    while (left < right)
    {
        m = (left + right) / 2, sum = 0;
        for (int i : A)
            sum += (i + m - 1) / m;
        if (sum > threshold)
            left = m + 1;
        else
            right = m;
    }
    return left;
}

int main()
{
    vector<int> nums = {44, 22, 33, 11, 1};
    int threshold = 5;
    cout << smallestDivisor(nums, threshold);
    return 0;
}