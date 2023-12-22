#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void printAdj(int vertex, vector<vector<int>> &edges)
{
    unordered_map<int, set<int>> adjList;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
    for (auto i : adjList)
    {
        cout << i.first << "-> ";
        for (auto j : i.second)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
int main()
{
    vector<vector<int>>edges = {{2,1},{2,0}};
    int vertex = 3;
    printAdj(vertex,edges);
    return 0;
}