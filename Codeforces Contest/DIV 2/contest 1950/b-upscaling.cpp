#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void markHash(vector<vector<char>> &board, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        for (int j = start; j <= end; j++)
        {
            board[i][j] = '#';
        }
    }
}
void printBoard(vector<vector<char>> &board)
{
    for (auto i : board)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<char>> board(2 * n, vector<char>(2 * n, '.'));

        for (int i = 0; i < 2 * n; i++)
        {
            cout << "i = " << i << endl;
            for (int j = 0; j < 2 * n; j++)
            {
                cout << "j = " << j << endl;

                int start, end;
                start = j;
                end = j + 1;
                cout << "start = " << start << endl;
                cout << "end = " << end << endl;
                markHash(board, start, end);
                j = j + 2;
                i = i + 1;
            }
        }

        printBoard(board);
    }

    return 0;
}