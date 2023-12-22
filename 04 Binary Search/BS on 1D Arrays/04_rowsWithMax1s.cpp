#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// brute O(n*m)
int rowsWithMax1s(vector<vector<int>> arr)
{
    // no. of rows
    int n = arr.size();
    // no. of columns
    int m = arr[0].size();
    int maxCount = INT_MIN;
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
            {
                count++;
            }
        }
        if (count > maxCount && count != 0)
        {
            ans = i;
            maxCount = count;
        }
    }

    return ans;
}

// brute O(n+m)
int rowsWithMax1sII(vector<vector<int>> arr)
{
    int n = arr.size();
    int m = arr[0].size();
    int start = 0;
    int end = n * m - 1;
    int row = 0;
    int maxCount = INT_MIN;
    int ans = -1;
    int count = 0;

    for (int i = start; i <= end; i++)
    {
        int val = arr[i / m][i % m];
        if (val == 1)
        {
            count++;
        }
        if (i % m == m - 1)
        {
            if (count > maxCount && count != 0)
            {
                ans = row;
                maxCount = count;
            }
            count = 0;
            row++;
        }
    }

    if (count > maxCount && count != 0)
    {
        ans = row;
    }

    return ans;
}

int main()
{
    vector<vector<int>> arr = {
        {0, 0}, {1, 1}};
    cout << "This row has the maximum 1s " << rowsWithMax1sII(arr);
    return 0;
}