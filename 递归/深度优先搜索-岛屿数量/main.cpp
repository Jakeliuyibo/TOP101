#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
// #include<bits/stdc++.h>

using namespace std;

/* 深度优先搜索 */
void dfs(vector<vector<char> >& grid, int ii, int jj)
{
    if(grid[ii][jj] == '0') return;
    else    // gird[ii][jj] = '1'
    {
        grid[ii][jj] = '0';

        /* 遍历前后左右的节点   */
        if((ii-1)>=0)                   // 左
            dfs(grid, ii-1, jj);
        if((ii+1)<=(grid.size()-1))  // 右
            dfs(grid, ii+1, jj);
        if((jj-1)>=0)                   // 上
            dfs(grid, ii, jj-1);
        if((jj+1)<=(grid[0].size()-1))     // 下
            dfs(grid, ii, jj+1);
    }

}

int solve(vector<vector<char> >& grid) 
{
    int count = 0;
    if(grid.size() == 0) return count;

    for(int ii=0; ii<grid.size(); ii++)
    {
        for(int jj=0; jj<grid[0].size(); jj++)
        {
            if(grid[ii][jj] == '1')
            {
                count++;
                dfs(grid, ii, jj);
            }
        }
    }
    return count;
}

int main() 
{
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);

    int n=5, m=5;
    vector<vector<char> > grid(n, vector<char>(m, '0'));
    for(int ii=0; ii<n; ii++)
    {
        for (int jj=0; jj<m; jj++) 
        {
            cin >> grid[ii][jj];
        }
    }

    int ret = 0;
    ret = solve(grid);
    cout << ret << endl;

    return 0;
}