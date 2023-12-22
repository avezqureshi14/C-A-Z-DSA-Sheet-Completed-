#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void prepareAdj(unordered_map<int, set<int>> &adjList, int vertex, vector<pair<int, int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void dfs(unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node)
{
    visited[node] = true;
    ans.push_back(node);
    for (auto i : adjList[node])
    {
        if (!visited[i])
        {
            dfs(adjList, visited, ans, i);
        }
    }
}

vector<int> DFS(int vertex, vector<pair<int, int>> &edges)
{
    unordered_map<int, set<int>> adjList;
    prepareAdj(adjList, vertex, edges);
    unordered_map<int, bool> visited;
    vector<int> ans;
    for (int i = 0; i < vertex; i++)
    {
        if (visited[i] == 0)
        {
            dfs(adjList, visited, ans, i);
        }
    }
    return ans;
}
int main()
{
    vector<pair<int, int>> edges;
    edges.push_back(make_pair(0, 1));
    edges.push_back(make_pair(0, 2));
    edges.push_back(make_pair(3, 1));
    edges.push_back(make_pair(2, 3));
    edges.push_back(make_pair(2, 4));
    edges.push_back(make_pair(3, 5));
    edges.push_back(make_pair(4, 6));
    edges.push_back(make_pair(5, 6));
    for (auto i : DFS(5, edges))
    {
        cout << i << " ";
    }
    return 0;
}