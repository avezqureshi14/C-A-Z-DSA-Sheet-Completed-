#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int countSubmatrices(vector<vector<int>> &grid, int k)
{
    int n = grid.size();
    int m = grid[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            grid[i][j] = grid[i][j] + grid[i][j - 1];
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            grid[i][j] = grid[i][j] + grid[i - 1][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] <= k)
            {
                ans++;
            }
        }
    }
    return ans;
}
int main()
{

    return 0;
}