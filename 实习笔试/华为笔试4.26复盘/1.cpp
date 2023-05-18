#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt","r", stdin);

    /* 输入处理 */
    int n;
    cin >> n;
    vector<vector<int>> graph(n);
    vector<int> indegree(n, 0);
    for(int ii=0; ii<n; ii++)
    {
        int cnt = 0;
        cin >> cnt;
        for(int jj=0; jj<cnt; jj++)
        {
            int num;
            cin >> num;
            num--;
            graph[ii].push_back(num);
            indegree[num]++;
        }
    }

    /* 不停的删除入读为0的节点  */
    queue<int> q;
    for(int ii=0; ii<n; ii++)
    {
        if(indegree[ii] == 0)
            q.push(ii);
    }

    int res = 0;
    while(!q.empty())
    {
        res++;
        int num = q.size();
        while(num--)
        {
            int cur = q.front();
            q.pop();
            for(auto next:graph[cur])
            {
                indegree[next]--;
                if(indegree[cur] == 0)
                    q.push(next);
            }
        }
    }

    /* 输出处理 */
    for(auto rr:graph)
    {
        for(auto r:rr)
            cout << r << " ";
        cout << endl;
    }
    cout << "res" << res << endl;
    return 0;
}



