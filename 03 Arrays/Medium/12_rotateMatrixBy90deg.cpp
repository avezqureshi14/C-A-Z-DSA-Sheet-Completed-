#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> rotateMatrix(vector<vector<int>> &matrix)
{
    // this is a square matrix
    int n = matrix.size();
    vector<vector<int>> ans(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans[j][n - i - 1] = matrix[i][j];
        }
    }
    return ans;
}

// inplace
void rotateMatrixII(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    // Transpose the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse each row
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    } 
}

void print(vector<vector<int>> matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "Before Rotating" << endl;
    print(matrix);
    cout << "After Rotating" << endl;
    rotateMatrixII(matrix);
    print(matrix);
    return 0;
}