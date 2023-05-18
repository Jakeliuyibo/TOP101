class Solution {
public:

    int res = 0;

    void dfs(vector<vector<int>>& matrix, int n, int m, int x, int y, int len, vector<vector<int>>& history)
    {
        res = max(res, len);

        // printf("当前位置(%d,%d) 当前走过的长度%d,当前历史长度%d\n", x, y, len, history[x][y]);


        history[x][y] = max(len, history[x][y]);

        int dx[4] = {1,-1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        for(int ii=0; ii<4; ii++)
        {
            int next_x = x + dx[ii];
            int next_y = y + dy[ii];
            if(next_x>=0 && next_y>=0 && next_x<n && next_y<m && matrix[next_x][next_y]>matrix[x][y] && len>=history[next_x][next_y])
            {
                dfs(matrix, n, m, next_x, next_y, len+1, history);
            }
        }
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> history(n, vector<int>(m, 0));

        for(int ii=0; ii<n; ii++)
        {
            for(int jj=0; jj<m; jj++)
                dfs(matrix, n, m, ii, jj, 0, history);
        }

        return res+1;
    }
};