class Solution {
public:

    typedef pair<int,int> PAIR;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    void bfs(vector<vector<char>>& grid, int n, int m, int x, int y)
    {
        queue<PAIR> q;
        q.push({x,y});
        grid[x][y] = '0';

        while(!q.empty())
        {
            /* 取出当前位置，并清除为0  */
            PAIR cur = q.front();
            q.pop();

            for(int idx=0; idx<4; idx++)
            {
                int next_x = cur.first  + dx[idx];
                int next_y = cur.second + dy[idx];
                if(next_x>=0 && next_x<n && next_y>=0 && next_y<m && grid[next_x][next_y] == '1')
                {
                    grid[next_x][next_y] = '0';
                    q.push({next_x, next_y});
                }
            }

        }
    }

    int numIslands(vector<vector<char>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();

        int ret = 0;
        for(int ii=0; ii<n; ii++)
        {
            for(int jj=0; jj<m; jj++)
            {
                if(grid[ii][jj] == '1')
                {
                    bfs(grid, n, m, ii, jj);
                    ret++;
                }
            }
        }

        return ret;
    }
};