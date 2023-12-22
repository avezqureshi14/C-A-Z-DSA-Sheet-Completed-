#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> nums, int day, int gdays)
{
    int n = nums.size();
    int sum = 0;
    int count = 0;
    int i = 0;
    cout<<day<<" day"<<endl;
    while (i < n)
    {
        cout<<nums[i]<<" ";
        sum = sum + nums[i];
        if (sum < day)
        {
            i++;
        }
        else if (sum > day)
        {
            count++;
            sum = 0;
            cout<<endl;
        }
        else if (sum == day)
        {
            count++;
            i++;
            sum = 0;
            cout<<endl;
        }
    }
    cout<<endl;
    cout<<endl;
    return count == gdays;
}

int shipWithinDays(vector<int> &weights, int days)
{
    int totalSum = 0;
    for (auto i : weights)
    {
        totalSum = totalSum + i;
    }
    int low = 1;
    int high = totalSum;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (check(weights, mid, days))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;
    cout << shipWithinDays(nums, days);
    return 0;
}