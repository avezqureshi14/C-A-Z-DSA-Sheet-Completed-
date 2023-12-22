#include <iostream>
#include <vector>
using namespace std;

int minimumMoves(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    int moves = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] > 1)
            {
                moves = moves + grid[i][j] - 1;
            }
        }
    }
    return moves;
}

int main() {
    vector<vector<int>> grid = {{1, 1, 0}, {1, 1, 1}, {1, 2, 1}};
    cout << minimumMoves(grid);
    return 0;
}
