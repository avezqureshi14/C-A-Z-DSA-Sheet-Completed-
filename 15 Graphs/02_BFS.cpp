#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void printAdj(unordered_map<int, set<int>> &adjList, int vertex, vector<vector<int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfs(unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node)
{
    visited[node] = true;
    queue<int> q;
    q.push(node);
    while (!q.empty())
    {
        int front = q.front();
        ans.push_back(front);
        q.pop();
        for (auto i : adjList[front])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<vector<int>> &edges)
{
    unordered_map<int, set<int>> adjList;
    vector<int> ans;
    printAdj(adjList, vertex, edges);
    unordered_map<int, bool> visited;
    for (int i = 0; i < vertex; i++)
    {
        if (visited[i] == 0)
        {
            bfs(adjList, visited, ans, i);
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {0, 2}, {2, 3}};
    int vertex = 4;
    for (auto i : BFS(vertex, edges))
    {
        cout << i << " ";
    }
    return 0;
}