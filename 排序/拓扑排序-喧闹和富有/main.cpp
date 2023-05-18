class Solution {
public:

    /* 深度搜索 */
    int dfs(vector<vector<int>>& graph, vector<int>& quiet, int cur, vector<int>& hist_min_idx)
    {
        /* 终止条件 */
        if(hist_min_idx[cur] != cur)        // 遍历过
            return hist_min_idx[cur];
        else
        {
            int min_quiet = quiet[cur];
            for(auto next:graph[cur])
            {
                int next_res = dfs(graph, quiet, next, hist_min_idx); // 下一节点最小安静值
                if(quiet[next_res] < quiet[hist_min_idx[cur]])
                {
                    hist_min_idx[cur] = next_res;
                }
            }
            return hist_min_idx[cur];
        }
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) 
    {
        int n = quiet.size();

        /* 构建反图 */
        vector<vector<int>> graph(n);
        for(int ii=0; ii<richer.size(); ii++)
        {
            graph[richer[ii][1]].push_back(richer[ii][0]);
        }

        /* 深度搜索 */
        /* 初始化历史记录   */
        vector<int> hist_min_idx(n, 0);
        for(int ii=0; ii<n; ii++)
        {
            hist_min_idx[ii]   = ii;
        }

        for(int ii=0; ii<n; ii++)
        {
            dfs(graph, quiet, ii, hist_min_idx);
        }

        return hist_min_idx;
    }
};
