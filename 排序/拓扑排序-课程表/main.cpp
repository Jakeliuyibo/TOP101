class Solution {
public:

    vector<vector<int>> edge;
    vector<int> visited;
    bool flag = true;

    void dfs(int idx)
    {
        visited[idx] = 1;

        for(auto next:edge[idx])
        {
            if(visited[next]==0)
            {
                dfs(next);
                if(flag == false) return;
            }
            else if(visited[next]==1)
            {
                flag = false;
                return;
            }
        }
        visited[idx] = 2;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        edge.resize(numCourses);
        visited.resize(numCourses);

        /* 构建边   */
        for(auto p:prerequisites)
        {
            edge[p[1]].push_back(p[0]);
        }

        /* dfs遍历  */
        for(int ii=0; ii<numCourses && flag; ii++)
        {
            if(visited[ii]==0)
                dfs(ii);
        }

        return flag;
    }
};