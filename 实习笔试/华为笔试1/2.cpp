#include <bits/stdc++.h>

using namespace std;

int result    = -101;
int sum_value = 0;


void helper(vector<vector<int>>& rule, int curr_pos, vector<int>& history)
{
    /* 终止条件:             */

    /* 记录当前路径的值      */
    result = max(result, sum_value);

    /* 寻找下一跳可选的节点  */
    for(int ii=0; ii<rule.size(); ii++)
    {
        if(rule[ii][1] == curr_pos && history[ii] == 0)  // 存在下一跳节点，且从未走过
        {
            history[ii] = 1;
            sum_value += rule[ii][2];
            helper(rule, ii, history);
            sum_value -= rule[ii][2];
            /* 回溯 */
            history[ii] = 0;
        }
    }
}


int main() 
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    /* 输入处理 */
    int n;
    cin >> n;
    vector<vector<int>> rule(n, vector<int>(3, 0));
    for(int idx=0 ; idx<n ; idx++)
    {
        cin >> rule[idx][0] >> rule[idx][1] >> rule[idx][2];
    }

    /* 从0，n-1出发 */
    vector<int> history(n, 0);      // 记录走过的路径，每个节点只能走一次   
    for(int idx=0 ; idx<n ; idx++)
    {
        history[idx] = 1;
        sum_value += rule[idx][2];
        helper(rule, idx, history);
        sum_value -= rule[idx][2];
        history[idx] = 0;
    }

    /* 输出处理 */
    cout << result << endl;
}
