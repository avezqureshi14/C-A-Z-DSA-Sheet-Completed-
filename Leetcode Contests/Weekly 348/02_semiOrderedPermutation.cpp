#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int semiOrderedPermutation(vector<int> &nums)
{
    int n = nums.size();
    int pos1;
    int posn;
    for (int i = 0; i < n; i++)
    {
        if (nums[0] == 1 && nums[n - 1] == n)
        {
            return 0;
        }
        else
        {
            if (nums[i] == 1)
            {
                pos1 = i;
            }
            if (nums[i] == n)
            {
                posn = i;
            }
        }
    }
    int finalAns;
    if (pos1 > posn)
    {
        finalAns = -1;
    }
    else
    {
        finalAns = 0;
    }

    // for 1
    int count1 = pos1 - 0;
    // for n
    int countn = (n - 1) - posn;
    finalAns = finalAns + count1 + countn;
    return finalAns;
}
int main()
{
    vector<int> nums = {2, 4, 1, 3};
    cout << semiOrderedPermutation(nums);
    return 0;
}