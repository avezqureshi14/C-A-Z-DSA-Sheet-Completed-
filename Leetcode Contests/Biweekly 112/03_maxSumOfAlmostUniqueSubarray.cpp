#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long maxSum(vector<int> &nums, int m, int k)
{
    int i = 0;
    int j = 0;
    long long maxSum = INT_MIN;
    long long sum = 0;
    int n = nums.size();
    unordered_map<int, int> map;
    while (j < n)
    {
        sum = sum + nums[j];
        map[nums[j]]++;
        if (j - i + 1== k)
        {
            if (map.size() == m || map.size() > m)
            {
                maxSum = max(maxSum, sum);
            }
            sum = sum - nums[i];
            map[nums[i]]--;
            if (map[nums[i]] == 0)
            {
                map.erase(nums[i]);
            }
            i++;
        }
        j++;
    }
    return maxSum;
}

int main()
{
    vector<int> nums = {5,9,9,2,4,5,4};
    int k = 3;
    int m = 1;
    cout << maxSum(nums, m, k);
    return 0;
}