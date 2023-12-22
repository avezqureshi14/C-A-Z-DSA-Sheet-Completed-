#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// m = colors
// n = vertex

bool isSafe(int node, int color[], bool graph[101][101], int n, int col)
{
    for (int k = 0; k < n; k++)
    {
        if (k != node && graph[k][node] == 1 && color[k] == col)
        {
            return false;
        }
    }
    return true;
}

bool solve(int node, int color[], int m, int n, bool graph[101][101])
{
    // reach at last node
    if (node == n)
    {
        return true;
    }
    for (int i = 1; i <= m; i++)
    {
        if (isSafe(node, color, graph, n, i))
        {
            color[node] = i;
            if (solve(node + 1, color, m, n, graph))
            {
                return true;
                color[node] = 0;
            }
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n)
{
    int color[n] = {0};
    if (solve(0, color, m, n, graph))
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int n = 4;
    int m = 3;
    bool graph[101][101];
    // name intitalization size
    memset(graph, false, sizeof(graph));
    graph[0][1] = 1;
    graph[1][0] = 1;
    graph[1][2] = 1;
    graph[2][1] = 1;
    graph[2][3] = 1;
    graph[3][2] = 1;
    graph[3][0] = 1;
    graph[0][3] = 1;
    graph[0][2] = 1;
    graph[2][0] = 1;
    cout << graphColoring(graph, m, n);
    return 0;
}