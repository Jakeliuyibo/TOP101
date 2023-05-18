class Solution {
public:

    vector<vector<int>> graph;      // 地图
    map<pair<int,int>, bool> mp;    // 哈希表记录是否可达

    bool dfs(int start, int end)
    {
        if(start == end)    
        {
            mp[{start,end}] = true;
            return true;
        }
        /* 是否可达 */
        if(mp.find({start,end}) != mp.end())
            return mp[{start, end}];

        /* 遍历start的临边  */
        for(auto next:graph[start])
        {
            mp[{start,next}] = true; // 临边可达
            /* dfs遍历  */
            if(dfs(next, end) == true)
            {
                mp[{start,end}] = true;
                return true;
            }
        }
        
        mp[{start,end}] = false;
        return false;
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) 
    {
        /* 构建图   */
        graph.resize(numCourses);
        for(auto p:prerequisites)
        {
            graph[p[0]].push_back(p[1]);
        }

        /* dfs搜索每个节点到其余节点是否可达    */
        vector<bool> ans;
        for(auto q:queries)
        {
            ans.push_back(dfs(q[0], q[1]));
        }
        return ans;
    }
};
