#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxFromCol(vector<vector<int>> &ans, int col, int row)
{
    int maxi = ans[0][col];
    for (int i = 0; i < row; i++)
    {
        if (ans[i][col] > maxi)
        {
            maxi = ans[i][col];
        }
    }
    return maxi;
}

vector<vector<int>> modifiedMatrix(vector<vector<int>> &matrix)
{
    vector<vector<int>> ans;
    int row = matrix.size();
    int col = matrix[0].size();
    ans = matrix;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (ans[i][j] == -1)
            {
                int maxNum = maxFromCol(ans, j, row);
                ans[i][j] = maxNum;
            }
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, -1},
        {4, -1, 6},
        {4, -1, 6},
        {7, 8, 9}};
    for (auto i : modifiedMatrix(matrix))
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}