#include <iostream>
#include <vector>
using namespace std;

bool check(const vector<int> &nums, int day, int m, int k)
{
    int n = nums.size();
    int count = 0;
    int cons = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] <= day)
        {
            count++;
            if (count == k)
            {
                cons++;
                count = 0;
            }
        }
        else
        {
            count = 0;
        }
    }

    return cons >= m;
}

int minDays(vector<int> &bloomDay, int m, int k)
{
    int low = INT_MAX;
    int high = INT_MIN;
    int n = bloomDay.size();
    for (int i = 0; i < n; i++)
    {
        if (bloomDay[i] > high)
        {
            high = bloomDay[i];
        }
        if (bloomDay[i] < low)
        {
            low = bloomDay[i];
        }
    }
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (check(bloomDay, mid, m, k))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 10, 3, 10, 2};
    int m = 3;
    int k = 1;
    cout << minDays(nums, m, k) << endl;
    return 0;
}
