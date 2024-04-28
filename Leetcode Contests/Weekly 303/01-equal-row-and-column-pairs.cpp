#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> pushRows(vector<vector<int>> &grid, int row)
{
    vector<int> ans;
    int m = grid[0].size(); // cols
    for (int col = 0; col < m; col++)
    {
        ans.push_back(grid[row][col]);
    }
    return ans;
}

vector<int> pushCols(vector<vector<int>> &grid, int col)
{
    vector<int> ans;
    int n = grid.size(); // rows
    for (int row = 0; row < n; row++)
    {
        ans.push_back(grid[row][col]);
    }
    return ans;
}

int compare(vector<vector<int>> &rows, vector<vector<int>> &cols)
{
    int n = rows.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "i = " << i << ", j = " << j << endl;
            for (auto k : rows[i])
            {
                cout << k << " ";
            }
            cout << endl;
            for (auto k : cols[j])
            {
                cout << k << " ";
            }
            cout << endl;
            cout << endl;
            if (rows[i] == cols[j])
            {
                count++;
            }
        }
    }
    return count;
}

int equalPairs(vector<vector<int>> &grid)
{
    int m = grid[0].size(); // cols
    int n = grid.size();    // rows
    vector<vector<int>> rows;
    vector<vector<int>> cols;
    for (int i = 0; i < n; i++)
    {
        rows.push_back(pushRows(grid, i));
    }
    for (int j = 0; j < m; j++)
    {
        cols.push_back(pushCols(grid, j));
    }
    return compare(rows, cols);
}

int equalPairsII(vector<vector<int>> &grid)
{
    int n = grid.size(), ans = 0;
    map<vector<int>, int> mp;
    for (int i = 0; i < n; i++)
        mp[grid[i]]++;

    for (auto i : mp)
    {
    }
    for (int i = 0; i < n; i++)
    {
        vector<int> temp(n);
        for (int j = 0; j < n; j++)
            temp[j] = grid[j][i];
        if (mp.count(temp))
            ans += mp[temp];
    }
    return ans;
}

int main()
{
    vector<vector<int>> grid = {
        {3, 1, 2, 2},
        {1, 4, 4, 5},
        {2, 4, 2, 2},
        {2, 4, 2, 2}};
    cout << equalPairs(grid);
    return 0;
}