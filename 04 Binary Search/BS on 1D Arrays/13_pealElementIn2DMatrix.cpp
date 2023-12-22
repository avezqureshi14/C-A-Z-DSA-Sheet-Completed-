#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//WRONG SOLUTION

void addSurroundingCells(vector<vector<int>> &new_matrix, vector<vector<int>> &matrix, int value)
{
    int m = matrix.size(); // Number of rows in the matrix
    int n = matrix[0].size(); // Number of columns in the matrix

    // Resize the new matrix with extra surrounding cells
    new_matrix.resize(m + 2);
    for (int i = 0; i < m + 2; i++) {
        new_matrix[i].resize(n + 2, value);
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            new_matrix[i+1][j+1] = matrix[i][j]; // Copy values of original matrix into new matrix
        }
    }
}



vector<int> peakElementII(vector<vector<int>> &matrix)
{
    vector<vector<int>>newMatrix;
    addSurroundingCells( newMatrix ,matrix,-1);
    // no. of rows
    int n = newMatrix.size();
    // no. of cols
    int m = newMatrix[0].size();
    vector<int> ans;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            // Check if top element is within bounds
            int top_element = newMatrix[i - 1][j];

            // Check if bottom element is within bounds
            int bottom_element = newMatrix[i + 1][j];

            // Check if left element is within bounds
            int left_element = newMatrix[i][j - 1];

            // Check if right element is within bounds
            int right_element = newMatrix[i][j + 1];

            if (newMatrix[i][j] > top_element && newMatrix[i][j] > bottom_element && newMatrix[i][j] > left_element && newMatrix[i][j] > right_element)
            {
                ans.push_back(newMatrix[i][j]);
            }
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> matrix = {
        {1,4}, {3,2}
    }; 
    for(auto i : peakElementII(matrix)){
        cout<<i<<" ";
    }
    return 0;
}