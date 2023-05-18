#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> result;
int min_step = INT_MAX;

/* 检测是否为叶子节点   */
bool isLeafNode(vector<vector<int>> &edge, int curr_node)
{
    for(int ii=0; ii<edge.size(); ii++)
    {
        if(edge[ii][0] == curr_node)
        {
            return false;
        }
    }
    return true;
}

/* 检测有没有障碍物     */
bool isBarrierNode(vector<int> &bar, int curr_node)
{
    for(auto b:bar)
    {
        if(b == curr_node)
        {
            return true;
        }
    }
    return false;
}


/* 递归，回溯   */
void helper(vector<vector<int>> &edge, vector<int> &history, vector<int> &path, int curr_node, vector<int> &bar)
{
    /* 终止条件，走到叶节点 */
    if(isLeafNode(edge, curr_node))
    {
        int curr_step = path.size();
        if(curr_step <= min_step)       // 取最短路径
        {
            result.push_back(path);
            min_step = curr_step;
        }
        return;
    }

    /* 递归 */
    for(int ii=0; ii<edge.size(); ii++)
    {
        if(edge[ii][0] ==  curr_node)
        {
            /* 尝试走edge[ii][1]节点    */
            int next_node = edge[ii][1];
            if(history[next_node] == 0 && !isBarrierNode(bar, next_node))    // 没有走过且没有障碍物
            {
                history[next_node] = 1;
                path.push_back(next_node);
                helper(edge, history, path, next_node, bar);
                history[next_node] = 0;
                path.pop_back();
            }
        }
    }

}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    /* 输入处理     */
    int num_nodes;          // 节点数量
    cin >> num_nodes;
    int num_edge;           // 边数量
    cin >> num_edge;

    vector<vector<int>> edge(num_edge, vector<int>(2, 0));
    for(int ii=0; ii<num_edge; ii++)
    {
        cin >> edge[ii][0] >> edge[ii][1];
    }
    int num_bar;            // 障碍物数量
    cin >> num_bar;
    vector<int> bar(num_bar, 0);
    for(int ii=0; ii<num_bar; ii++)
    {
        cin >> bar[ii];
    }

    /* 递归回溯求解 */
    vector<int> path;                   // 路径
    vector<int> history(num_nodes, 0);  // 历史记录
    helper(edge, history, path, 0, bar);

    /* 输出处理     */
    if(result.size() == 0)
    {
        cout << "NULL" << endl;
    }
    else
    {
        /* 处理result有多个情况的结果   */
        /* 首先筛选出路径为min_step的可能存放到ret中*/
        vector<vector<int>> ret;
        for(auto r:result)
        {
            if(r.size() == min_step)
            {
                ret.push_back(r);
            }
        }

        /* 然后按字典序输出唯一的路径   */
        int jj = 0;
        while(1)
        {
            /* 找到idx位最小值  */
            int min_val = INT_MAX;
            for(int ii=0; ii<ret.size(); ii++)
            {
                min_val = min(min_val, ret[ii][jj]);
            }

            /* 删除所有不是min_val的值  */
            for(int ii=0; ii<ret.size(); ii++)
            {
                if(ret[ii][jj] != min_val)
                {
                    ret.erase(ret.begin()+ii);
                }
            }

            if(ret.size() == 1)
            {
                break;
            }
            jj++;
        }

        /* 输出最后一个元素 */
        for(int ii=0; ii<ret[0].size(); ii++)
        {
            if(ii==0)
            {
                cout << "0->";
            }
            cout << ret[0][ii];
            if(ii<ret[0].size()-1)
            {
                cout << "->";
            }
        }
        cout << endl;
    }



    return 0;
}