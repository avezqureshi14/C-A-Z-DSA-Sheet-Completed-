#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int countMatchingSubarrays(vector<int> &nums, vector<int> &pattern)
{
    int k = pattern.size() + 1;
    int n = nums.size();
    int i = 0;
    int j = 0;
    int count = 0;
    deque<int> window;
    while (j < n)
    {
        window.push_back(nums[j]);
        int wn = window.size();
        if (wn == k)
        {
            bool ok = true;
            for (int iw = 0; iw < wn; iw++)
            {
                if (iw > 0)
                {
                    if (pattern[iw - 1] == 1)
                    {
                        if (window[iw - 1] > window[iw])
                        {
                            ok = false;
                        }
                    }
                    else if (pattern[iw - 1] == 0)
                    {
                        if (window[iw - 1] != window[iw])
                        {
                            ok = false;
                        }
                    }
                    else if (pattern[iw - 1] == -1)
                    {
                        if (window[iw - 1] < window[iw])
                        {
                            ok = false;
                        }
                    }
                }
            }
            if (ok)
            {
                count++;
            }
        }
        else if (window.size() > k)
        {
            window.pop_front();
            i++;
        }
        j++;
    }
    return count;
}
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    vector<int> pattern = {1, 1};
    cout << countMatchingSubarrays(nums, pattern);
    return 0;
}