#include <bits/stdc++.h>

using namespace std;

bool rows[9][9];                 // 行
bool cols[9][9];                 // 列
bool block[3][3][9];             // 小格


bool dfs(vector<vector<char>>& board, int x, int y)
{
    /* 终止条件             */
    if(x==9 && y==0)
    {
        return true;
    }

    int next_x = y < 8 ? x : x+1;
    int next_y = y < 8 ? y+1 : 0;

    /* 填入数字             */
    if(board[x][y] != '.')  return dfs(board, next_x, next_y);

    for(int num=0; num<9; num++)
    {
        if(rows[x][num] || cols[y][num] || block[x/3][y/3][num])              /* 检测  */
            continue;

        /* 递归回溯 */
        board[x][y] = num + '1';
        rows[x][num] = cols[y][num] = block[x/3][y/3][num] = true;

        if(dfs(board, next_x, next_y)) 
            return true;

        rows[x][num] = cols[y][num] = block[x/3][y/3][num] = false;
        board[x][y] = '.';
    }

    return false;
} 

void solveSudoku(vector<vector<char>>& board)
{
    memset(rows, false, sizeof(rows));
    memset(cols, false, sizeof(cols));
    memset(block, false, sizeof(block));

    /* 记录每个节点的个数   */
    for(int ii=0; ii<9; ii++)
    {
        for(int jj=0; jj<9; jj++)
        {
            if(board[ii][jj] != '.')
            {
                int cur = board[ii][jj] - '1';
                rows[ii][cur] = cols[jj][cur] = block[ii/3][jj/3][cur] = true;
            }
        }
    }

    dfs(board, 0, 0);
}

int main()
{
    freopen("in.txt", "r", stdin);

    vector<vector<char>> board(9, vector<char>(9)); 
    for(int ii=0; ii<9; ii++)
    {
        for(int jj=0; jj<9; jj++)
        {
            cin >> board[ii][jj];
        }
    }

    for(auto bo:board)
    {
        for(auto b:bo)
        {
            cout << b << " ";
        }
        cout << endl;
    }

    solveSudoku(board);
    cout << "solve" << endl;
    for(auto bo:board)
    {
        for(auto b:bo)
        {
            cout << b << " ";
        }
        cout << endl;
    }


    return 0;
}