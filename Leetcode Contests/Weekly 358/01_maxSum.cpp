#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int checkDigitEqual(int num)
{
    int mx = 0;
    while (num != 0)
    {
        mx = max(mx, num % 10);
        num = num / 10;
    }

    return mx;
}

int maxSum(vector<int> &nums)
{
    int n = nums.size();
    int maxSum = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int a = nums[i], b = nums[j];
            if (checkDigitEqual(a) == checkDigitEqual(b))
            {
                maxSum = max(maxSum, a + b);
            }
        }
    }

    return maxSum;
}

int main()
{
    vector<int> nums = {51, 71, 17, 24, 42};
    // vector<int>nums = {1,2,3,4};
    cout << maxSum(nums);

    return 0;
}