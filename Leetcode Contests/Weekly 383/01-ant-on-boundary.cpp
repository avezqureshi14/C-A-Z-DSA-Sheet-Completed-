#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int returnToBoundaryCount(vector<int> &nums)
{
    int sum = 0;
    int count = 0;
    for (auto i : nums)
    {
        sum = sum + i;
        if (sum == 0)
        {
            count++;
        }
    }
    return count;
}
int main()
{
    vector<int> nums = {3, 2, -3, -4};
    cout << returnToBoundaryCount(nums);
    return 0;
}