#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int digitSum(int num)
{
    int ans = 0;
    int n = num;
    while (n)
    {
        int digit = n % 10;
        ans = ans + digit;
        n = n / 10;
    }
    return ans;
}

int sumofArr(std::vector<int> arrInd, std::vector<int> &nums)
{
    int n = arrInd.size();
    int max1 = INT_MIN;     // Initialize max1 to smallest possible value
    int max2 = INT_MIN;     // Initialize max2 to smallest possible value
    bool max1Found = false; // Flag to keep track if max1 is found
    for (int i = 0; i < n; i++)
    {
        if (nums[arrInd[i]] >= max1)
        {
            if (max1Found)
            {
                max2 = max1; // If a new max1 is found, update max2 to previous max1
            }
            max1 = nums[arrInd[i]]; // Update max1 to the new maximum
            max1Found = true;       // Set max1Found flag to true
        }
        else if (nums[arrInd[i]] > max2 && nums[arrInd[i]] != max1)
        {
            max2 = nums[arrInd[i]]; // Update max2 to the new second maximum
        }
    }
    // Compute sum
    int sum = max1 + max2;
    return sum;
}
int maximumSum(vector<int> &nums)
{
    int n = nums.size();
    int maxSum = -1;
    vector<int> sumofD;
    for (int i = 0; i < n; i++)
    {
        sumofD.push_back(digitSum(nums[i]));
    }
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
        mp[sumofD[i]].push_back(i);
    }
    for (auto i : mp)
    {
        if (i.second.size() >= 2)
        {
            maxSum = max(maxSum, sumofArr(i.second, nums));
        }
        cout << i.first << "->";
        for (auto k : i.second)
        {
            cout << k << " ";
        }
        cout << endl;
    }
    return maxSum;
}

int maximumSumII(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    unordered_map<int, int> mp;
    int ans = -1;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (mp.find(digitSum(nums[i])) != mp.end())
        {
            ans = max(ans, nums[i] + mp[digitSum(nums[i])]);
            mp.erase(digitSum(nums[i]));
        }
        mp[digitSum(nums[i])] = nums[i];
    }
    return ans;
}

int main()
{
    vector<int> nums = {18, 43, 36, 13, 7};
    cout << maximumSum(nums);
    return 0;
}