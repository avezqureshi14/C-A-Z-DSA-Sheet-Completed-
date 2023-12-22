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

bool isCyclicDetection(unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node)
{
    unordered_map<int, int> parent;
    queue<int> q;
    q.push(node);
    parent[node] = -1;
    visited[node] = true;
    while (!q.empty())
    {
        int front = q.front();
        ans.push_back(front);
        q.pop();
        for (auto i : adjList[front])
        {
            //agar front kar parent i nahi hai toh cycle exists
            if (visited[i] == 1 && i != parent[front])
            {
                return true;
            }
            else if (visited[i] == 0)
            {
                q.push(i);
                //parent of i apun front set karne ka 
                parent[i] = front;
                visited[i] = true;
            }
        }
    }
    return false;
}

bool isCyclic(int vertex, vector<vector<int>> &edges)
{
    unordered_map<int, set<int>> adjList;
    vector<int> ans;
    printAdj(adjList, vertex, edges);
    unordered_map<int, bool> visited;
    for (int i = 0; i < vertex; i++)
    {
        if (visited[i] == 0)
        {
            return isCyclicDetection(adjList, visited, ans, i);
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> edges = {{0, 3}, {0, 2},  {4, 1}, {2, 4}, {5, 4}};
    int vertex = 6;
    cout << isCyclic(vertex, edges);
    return 0;
}