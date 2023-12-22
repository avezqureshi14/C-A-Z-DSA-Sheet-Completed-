#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool sortedAndRotated(vector<int> nums)
{
    int n = nums.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > nums[i + 1])
        {
            count++;
        }
    }

    if (nums[0] < nums[n - 1])
    {
        count++;
    }
    if (count <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    vector<int> nums = {4, 2,1, 2, 3};
    if (sortedAndRotated(nums))
    {
        cout << "Yes the array is sorted and rotated " << endl;
    }
    else
    {
        cout << "Nope the array is not sorted and rotated " << endl;
    }

    return 0;
}