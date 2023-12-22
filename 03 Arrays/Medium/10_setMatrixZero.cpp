#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// i -> row
// j -> col

// m - rows
// n - cols
void markRow(vector<vector<int>> &matrix, int n, int m, int i)
{
    // set all non zero elements as -1 in the row i
    for (int j = 0; j < m; j++)
    {
        if (matrix[i][j] != 0)
        {
            matrix[i][j] = -1;
        }
    }
}

void markCol(vector<vector<int>> &matrix, int n, int m, int j)
{
    // set all non zero elements as -1 in the col j
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][j] != 0)
        {
            matrix[i][j] = -1;
        }
    }
}

vector<vector<int>> zeroMatrixI(vector<vector<int>> &matrix, int n, int m)
{
    // set -1 for rows and cols
    // that contains 0, Don't mark any 0 as -1
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                markRow(matrix, n, m, i);
                markCol(matrix, n, m, j);
            }
        }
    }

    // Finally mark all -1s as 0
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}

vector<vector<int>> zeroMatrixII(vector<vector<int>> &matrix, int n, int m)
{
    vector<int> row(m, 0);
    vector<int> col(n, 0);

    // here we are travesing the matrix and checking where we encountering 0, as soon as we encounter any 0 we are noting its row and col as 1
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 1;
                col[i] = 1;
            }
        }
    }

    // finally mark all the cells of matrix as 0 if our row[i] or col[j] is marked as 1
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (row[i] || col[j])
            {
                matrix[i][j] = 0;
            }
        }
    }
    return matrix;
}

// If any cell in the 0th row contains 0, we will mark matrix[0][0] as 0 and if any cell in the 0th column contains 0, we will mark the col0 variable as 0.

vector<vector<int>> zeroMatrixIII(vector<vector<int>> &matrix, int n, int m)
{
    int col0 = 1;

    // Do the work which we use to do in two arrays above
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                // marking ith row
                matrix[i][0] = 0;
                // marking jth col
                if (j != 0)
                {
                    matrix[0][j] = 0;
                }
                else
                {
                    col0 = 0;
                }
            }
        }
    }

    // Step 2 marking with 0s
    for (int i = m - 1; i >= 0; i--)
    {
        // remember this that u dont have to do 0s till first cell of the column
        for (int j = n - 1; j >= 1; j--)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
            if (col0 == 0)
            {
                matrix[i][0] = 0;
            }
        }
    }
    return matrix;
}

int main()
{
    vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};

    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> ans = zeroMatrixIII(matrix, n, m);
    cout << "The final matrix is " << endl;
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}