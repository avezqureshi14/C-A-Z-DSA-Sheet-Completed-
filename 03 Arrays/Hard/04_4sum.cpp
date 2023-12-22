#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    int n = nums.size();
    int first = 0;
    int last = n - 1;
    int sum = 0;
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int left = j + 1;
            int right = n - 1;
            while (left < right)
            {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[left];
                sum += nums[right];
                if (sum == target)
                {
                    vector<int> temp = {nums[i], nums[j], nums[left], nums[right]};
                    result.push_back(temp);
                    while (left < right && nums[left] == nums[left + 1])
                    {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1])
                    {
                        right--;
                    }
                    left++;
                    right--;
                }
                else if (sum > target)
                {
                    right--;
                }
                else if (sum < target)
                {
                    left++;
                }
            }
            while (j + 1 < n && nums[j] == nums[j + 1])
            {
                j++;
            }
        }
        while (i + 1 < n && nums[i] == nums[i + 1])
        {
            i++;
        }
    }

    return result;
}
int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    cout << "The Quads are " << endl;
    for (auto i : fourSum(nums, 0))
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}