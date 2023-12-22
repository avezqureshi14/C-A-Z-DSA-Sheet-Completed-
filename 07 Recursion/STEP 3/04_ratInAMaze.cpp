#include <bits/stdc++.h>
using namespace std;

void solve(int i, int j, vector<vector<int>> &maze, int n, vector<string> &ans, string move,
           vector<vector<int>> &vis, int di[], int dj[])
{
    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(move);
        return;
    }
    string dir = "DLRU";
    // in each recursive call we are make for different recursive call for each direction we are checking whether it is possible for us to move any of this four direction by making those four recursive calls at each main recursive call
    for (int ind = 0; ind < 4; ind++)
    {
        int nexti = i + di[ind];
        int nextj = j + dj[ind];
        // first two condition checking for out of bound
        // third condition we are checking that its visited must be false (means it must not be visited before)
        // fourth condition we are checking that whether that same element in the maze is having value = 1
        if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && maze[nexti][nextj] == 1)
        {
            vis[nexti][nextj] = 1;
            solve(nexti, nextj, maze, n, ans, move + dir[ind], vis, di, dj);
            // Unmark the cell before returning
            vis[nexti][nextj] = 0;
        }
    }
}

vector<string> findPath(vector<vector<int>> &maze, int n)
{
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    int di[] = {1, 0, 0, -1};
    int dj[] = {0, -1, 1, 0};
    if (maze[0][0] == 1)
    {
        vis[0][0] = 1; // Mark the starting cell as visited
        solve(0, 0, maze, n, ans, "", vis, di, dj);
    }
    return ans;
}

int main()
{
    int n = 4;
    vector<vector<int>> maze = {{1, 0, 0, 0},
                                 {1, 1, 0, 1},
                                 {1, 1, 0, 0},
                                 {0, 1, 1, 1}};
    vector<string> result = findPath(maze, n);
    if (result.empty())
    {
        cout << -1;
    }
    else
    {
        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i] << " ";
        }
    }
    cout << endl;
    return 0;
}
