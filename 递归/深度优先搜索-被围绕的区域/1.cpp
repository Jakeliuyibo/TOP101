#include <bits/stdc++.h>


using namespace std;

void helper(vector<vector<char>>& board, int n, int m, int x, int y)
{
    /* 终止条件 */
    if(board[x][y] == 'X')
        return;

    board[x][y] = 'M';

    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    for(int ii=0; ii<4; ii++)
    {
        int next_x = x + dx[ii];
        int next_y = y + dy[ii];
        if(next_x>=0 && next_x<n && next_y>=0 && next_y<m && board[next_x][next_y] == 'O')
        {
            helper(board, n, m, next_x, next_y);
        }
    }
}


void solve(vector<vector<char>>& board) 
{
    int n = board.size();
    int m = board[0].size();

    /* 从外层搜索，将外层元素符号改为M   */
    for(int ii=0; ii<n; ii++)
    {
        helper(board, n, m, ii, 0);
        helper(board, n, m, ii, m-1);
    }
    for(int jj=0; jj<m; jj++)
    {
        helper(board, n, m, 0  , jj);
        helper(board, n, m, n-1, jj);
    }

    /* 将所有'0'变成'X'                 */
    for(int ii=0; ii<n; ii++)
    {
        for(int jj=0; jj<m; jj++)
        {
            if(board[ii][jj] == 'O')
                board[ii][jj] = 'X';
            if(board[ii][jj] == 'M')
                board[ii][jj] = 'O';
        }
    }
}