class Solution {
public:

    int n, m;
    int dx[4] = {1,0,-1, 0};
    int dy[4] = {0,1, 0,-1};

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& record, int x, int y)
    {
        if(record[x][y] == true)    return;
        record[x][y] = true;

        for(int ii=0; ii<4; ii++)
        {
            int next_x = x + dx[ii];
            int next_y = y + dy[ii];
            if(next_x>=0 && next_x<n && next_y>=0 && next_y<m && heights[x][y] <= heights[next_x][next_y])
            {
                dfs(heights, record, next_x, next_y);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        n = heights.size();
        m = heights[0].size();

        /* 构建地图 */
        vector<vector<bool>> pacific( n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        /* 搜索节点能否到达太平洋   */
        for(int jj=0; jj<m; jj++)
            dfs(heights, pacific, 0, jj);
        for(int ii=0; ii<n; ii++)
            dfs(heights, pacific, ii, 0);

        /* 遍历节点能否到达大西洋   */
        for(int jj=0; jj<m; jj++)
            dfs(heights, atlantic, n-1, jj);
        for(int ii=0; ii<n; ii++)
            dfs(heights, atlantic, ii, m-1);

        /* 输出结果 */
        vector<vector<int>> res;
        for(int ii=0; ii<n; ii++)
        {
            for(int jj=0; jj<m; jj++)
            {
                if(pacific[ii][jj] && atlantic[ii][jj])
                    res.push_back({ii,jj});
            }
        }
        return res;
    }
};