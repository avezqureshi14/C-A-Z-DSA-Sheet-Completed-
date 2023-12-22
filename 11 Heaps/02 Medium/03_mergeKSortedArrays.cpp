#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    // rows
    int n = arr.size();
    // cols
    int m = arr[0].size();
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            minHeap.push(arr[i][j]);
        }
    }
    vector<int> ans;
    while (!minHeap.empty())
    {
        ans.push_back(minHeap.top());
        minHeap.pop();
    }
    return ans;
}
int main()
{
    vector<vector<int>> arr = {{1, 2, 3, 4}, {2, 2, 3, 4}, {5, 5, 6, 6}, {7, 8, 9, 9}};
    for (auto i : mergeKArrays(arr, 3))
    {
        cout << i << " ";
    }
    return 0;
}