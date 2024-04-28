#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void cyclicSort(vector<int> &nums)
{
    // correct position = nums[nums[i]-1]

    int i = 0;
    int n = nums.size();
    while (i < n)
    {
        if (i != nums[i] - 1)
        {
            swap(nums[nums[i] - 1], nums[i]);
        }
        else
        {
            i++;
        }
    }
}

// missing number
int missingNum(vector<int> nums)
{
    // correct position = nums[nums[i]-1]

    int n = nums.size();
    int i = 0;
    while (i < n)
    {
        if (i != nums[i] && nums[i] != n)
        {
            swap(nums[i], nums[nums[i]]);
        }
        else
        {
            i++;
        }
    }
    for (int j = 0; j <= n; j++)
    {
        if (nums[j] != j)
        {
            return j;
        }
    }
    return -1;
}

// find number disappeared in an array
vector<int> findDisappearedNumbers(vector<int> &nums)
{
    int n = nums.size();
    int i = 0;
    vector<int> ans;
    // vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    // correct position = nums[nums[i]-1] //dont consider it as a big thing just do a dry run on above example, it will be clear
    while (i < n)
    {
        if (nums[nums[i] - 1] == nums[i])
        {
            i++;
        }
        else
        {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != i + 1)
        {
            ans.push_back(i + 1);
        }
    }

    return ans;
}

// find duplicate number
vector<int> findDuplicates(vector<int> &nums)
{
    int n = nums.size();
    int i = 0;
    while (i < n)
    {
        if (nums[i] == nums[nums[i] - 1])
        {
            i++;
        }
        else
        {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != i + 1)
        {
            ans.push_back(nums[i]);
        }
    }

    return ans;
}

// find missing positive
int firstMissingPositive(vector<int> &nums)
{
    int n = nums.size();
    int i = 0;
    while (i < n)
    {
        if (nums[i] > n || nums[i] == i - 1)
        {
            i++;
        }
        else
        {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (nums[i - 1] != i)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {1, 2, 0};
    firstMissingPositive(nums);
    for (auto i : nums)
    {
        cout << i << " ";
    }

    return 0;
}