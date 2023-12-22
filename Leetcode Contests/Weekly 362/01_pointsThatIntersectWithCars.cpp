#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int numberOfPoints(vector<vector<int>> &nums)
{
    set<int> st;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int start = nums[i][0];
        int end = nums[i][1];
        for (int i = start; i <= end; i++)
        {
            st.insert(i);
        }
    }
    return st.size();
}
int main()
{
    vector<vector<int>> nums = {{1, 5}, {3, 6}, {9, 12}, {10, 13}, {11, 15}};
    cout << numberOfPoints(nums);
    return 0;
}