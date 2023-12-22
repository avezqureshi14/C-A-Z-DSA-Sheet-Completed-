// In GFG verision the matrix is rowise and columnwise sorted means it cannot be stretched into a sorted array

#include <iostream>
#include <bits/stdc++.h>
using namespace std;


//this can be a better approach for leetcode version where the matrix can be streched into a sorted array (Optimal for leetcode version is binary search in 2d arrays )
void searchIn2D(vector<vector<int>> nums, int target)
{
    // no. of rows
    int n = nums.size();
    // no. of cols
    int m = nums[0].size();
    int i = 0;
    int j = m - 1;
    while (i < n && j >= 0)
    {
        if (nums[i][j] == target)
        {
            cout << "Found at " << i+1 << ", " << j+1;
            return ;
        }
        if (nums[i][j] > target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }

}
int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    searchIn2D(matrix, 8);
    return 0;
}