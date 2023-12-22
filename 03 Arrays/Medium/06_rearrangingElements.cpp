#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void rearrangeElements(vector<int> &nums)
{
    int n = nums.size();
    vector<int> pos;
    vector<int> neg;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] < 0)
        {
            pos.push_back(nums[i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
        {
            neg.push_back(nums[i]);
        }
    }
    nums.clear();
    for (int i = 0; i < n / 2; i++)
    {
        nums.push_back(pos[i]);
        nums.push_back(neg[i]);
    }
}

void printArray(vector<int> nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}

int main()
{
    vector<int> nums = {28, -41, 22, -8, -37, 46, 35, -9, 18, -6, 19, -26, -37, -10, -9, 15, 14, 31};
    // [28,-41,22,-8,46,-37,35,-9,18,-6,19,-26,15,-37,14,-10,31,-9]
    rearrangeElements(nums);
    printArray(nums);
    return 0;
}