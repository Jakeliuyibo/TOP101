#include <bits/stdc++.h>
using namespace std;

int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    /* 输入处理     */
    int num;                                            // 任务数量
    cin >> num;
    vector<vector<int>> task(num, vector<int>(2, 0));   // 任务列表
    int start_time = 1000001;                           // 起始时间
    int end_time = 0;                                   // 终止时间
    for(int ii=0; ii<num; ii++)
    {
        cin >> task[ii][0] >> task[ii][1];
        start_time  = min(start_time, task[ii][0]);
        end_time    = max(end_time, task[ii][1]);
    }

    /* 将数据存储到哈希表中 */
    unordered_map<int, int> mp;
    for(int ii=0; ii<num; ii++)
    {
        /* 存储时间段       */
        for(int jj=task[ii][0]; jj<=task[ii][1]; jj++)
        {
            mp[jj]++;
        }
    }

    /* 统计能耗     */
    int power = 0;
    for(int time=0; time<=end_time; time++)
    {
        if(time<start_time)             // 没有任务
        {
        
        }
        else
        {
            if(mp[time] == 0)           // 空载任务
                power += 1;
            else if(mp[time] == 1)      // 单任务
                power += 3;
            else                        // 多任务
                power += 4;
        }
    }

    /* 输出处理     */
    cout << power << endl;

    return 0;
}