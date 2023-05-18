#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PAIR;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

/* 广度优先搜索     */
vector<PAIR> bfs(vector<vector<int>>& matrix, int n, int m, vector<vector<int>>& path)
{
    PAIR start = {0,0};
    matrix[0][0] = -1;
    queue<PAIR> qu;
    qu.push(start);

    while(!qu.empty())
    {
        PAIR curr = qu.front();
        qu.pop();

        if(curr.first==n-1&&curr.second==m-1)
            break;

        /* 探索 */
        for(int ii=0; ii<4; ii++)
        {
            int next_x = curr.first  + dx[ii];
            int next_y = curr.second + dy[ii];
            if(next_x>=0&&next_y>=0&&next_x<n&&next_y<m&&matrix[next_x][next_y]==0)
            {
                matrix[next_x][next_y] = -1;
                path[next_x][next_y] = path[curr.first][curr.second] + 1;
                qu.push({next_x, next_y});
            }
        }
    }

    /* 从目的节点向源节点回溯   */
    PAIR track = {n-1,m-1};
    vector<PAIR> result;
    while(1)
    {
        result.push_back(track);

        if(track.first == 0 && track.second == 0)
            break;
        /* 探索 */
        for(int ii=0; ii<4; ii++)
        {
            int next_x = track.first  + dx[ii];
            int next_y = track.second + dy[ii];
            if(next_x>=0&&next_y>=0&&next_x<n&&next_y<m&&path[track.first][track.second]==path[next_x][next_y]+1&&matrix[next_x][next_y]!=1)
            {
                track = {next_x, next_y};
                break;
            }
        }
    }
    return result;
}

int main()
{
    /* 输入处理     */
    int n,m; 
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    for(int ii=0; ii<n; ii++)
        for(int jj=0; jj<m; jj++)
            cin >> matrix[ii][jj];

    /* 递归     */
    vector<vector<int>> path(n, vector<int>(m, 0));
    vector<PAIR> result = bfs(matrix, n, m, path);

    /* 输出处理 */
    for(int idx=result.size()-1; idx>=0; idx--)
    {
        cout << "(" << result[idx].first <<"," << result[idx].second <<")" << endl;
    }

    return 0;
}