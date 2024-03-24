#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    vector<int> nodes;
    for (int i = 1; i <= n * n; i++)
    {
        nodes.push_back(i);
    }
    int top = 0;
    int left = 0;
    int bottom = n - 1;
    int right = n - 1;
    int it = 0;
    while (it <= nodes.size() && top <= bottom && left <= right)
    {
        // for moving left to right
        for (int i = left; i <= right; i++)
        {
            if (it <= nodes.size())
            {
                matrix[top][i] = nodes[it];
            }
            it++;
        }
        top++;
        // for moving top to bottom
        for (int i = top; i <= bottom; i++)
        {
            if (it <= nodes.size())
            {
                matrix[i][right] = nodes[it];
                it++;
            }
        }
        right--;
        if (top <= bottom)
        {
            // for moving right to left
            for (int i = right; i >= left; i--)
            {
                if (it <= nodes.size())
                {
                    matrix[bottom][i] = nodes[it];
                    it++;
                }
            }
            bottom--;
        }
        // for moving bottom to top
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                if (it <= nodes.size())
                {
                    matrix[i][left] = nodes[it];
                    it++;
                }
            }
            left++;
        }
    }
    return matrix;
}

int main()
{
    for (auto i : generateMatrix(3))
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}