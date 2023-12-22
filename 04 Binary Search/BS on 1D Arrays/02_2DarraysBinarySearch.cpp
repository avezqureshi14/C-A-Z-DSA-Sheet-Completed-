#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int searchIn2D(vector<vector<int>> &nums, int target)
{
    int n = nums.size();    // got the number of rows
    int m = nums[0].size(); // got the col
    int low = 0;
    int high = n * m - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int mid_val = nums[mid / m][mid % m];
        if (mid_val == target)
        {
            return mid;
        }
        else if (mid_val > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}

void print2dMatrix(vector<vector<int>> nums)
{
    for (auto i : nums)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    print2dMatrix(matrix);
    cout << "The position of the given element is " << searchIn2D(matrix, 8);
    return 0;
}