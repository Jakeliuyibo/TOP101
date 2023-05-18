class Solution {
public:

    vector<int> res;
    vector<int> visited;    // 标记 0：未访问 1：访问过 2：安全节点

    bool dfs(vector<vector<int>>& graph, int idx)
    {
        visited[idx] = 1;

        for(auto next:graph[idx])
        {
            if(visited[next] == 0)
            {
                if(dfs(graph, next) == false)
                    return false;
            }
            else if(visited[next] == 1)
            {
                return false;
            }
        }

        visited[idx] = 2;
        res.push_back(idx);
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int n = graph.size();

        visited.resize(n);

        for(int ii=0; ii<n; ii++)
        {
            if(visited[ii] == 0)
            {
                dfs(graph, ii);
            }
        }
        
        sort(res.begin(), res.end());
        return res;
    }
};


// class Solution {
// public:
//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
//     {
//         int n = graph.size();

//         vector<vector<int>> rg(n);      // 反图
//         vector<int> indegree(n, 0);     // 入度
//         for(int ii=0; ii<n; ii++)
//         {
//             for(auto next:graph[ii])
//             {
//                 rg[next].push_back(ii);
//                 indegree[ii]++;
//             }
//         }

//         /* 将入读为0的节点存入队列  */
//         queue<int>  qu;
//         for(int ii=0; ii<n; ii++)
//             if(indegree[ii] == 0) 
//                 qu.push(ii);

//         while(!qu.empty())
//         {
//             /* 取出入读为0的节点    */
//             int cur = qu.front();
//             qu.pop();
//             printf("取出节点%d\n",cur);

//             /* 删除当前节点的边     */
//             for(auto next:rg[cur])
//             {
//                 printf("删除节点%d到节点%d的边\n",cur,next);
//                 indegree[next]--;
//                 if(indegree[next]==0)
//                     qu.push(next);
//             }
//         }

//         vector<int> res;        // 返回值
//         for(auto ii=0; ii<n; ii++)
//         {
//             if(indegree[ii]==0)
//                 res.push_back(ii);
//         }

//         return res;
//     }
// };