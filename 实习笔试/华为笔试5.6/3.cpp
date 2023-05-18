#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PAIT;
int n;                  // 地图大小
int k;                  // 怪物数量
int x,y;                // 王子坐标
int target_x, target_y; // 公主坐标
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};
int graph[100][100][3];

struct Info
{
    int x, y;
    int path;
    int wait_time;
};

int main()
{
    freopen("in.txt", "r", stdin);
    /* 输入处理 */
    cin >> n;
    cin >> k;
    vector<vector<int>> boss_pos(k, vector<int>(2,0));
    for(int ii=0; ii<k; ii++)
    {
        cin >> boss_pos[ii][0] >> boss_pos[ii][1];
    }
    cin >> x >> y;
    cin >> target_x >> target_y;
    memset(graph, 0, sizeof(graph));
    for(int ii=0; ii<n; ii++)
    {
        for(int jj=0; jj<n; jj++)
        {
            string str;
            cin >> str;
            for(int kk=0; kk<3; kk++)
            {
                graph[ii][jj][kk] = str[kk] - '0'; 
            }
        }
    }
    // 合并怪兽信息到graph
    for(auto b:boss_pos)
    {
        for(int kk=0; kk<3; kk++)
        {
            graph[b[0]][b[1]][kk] = 1;
        }
    }

    /* 寻找最短时间 */
    /* 广度搜索 */
    vector<vector<bool>> visited(n, vector<bool>(n, false)); 
    queue<Info> q;
    Info start_info = {x,y,0,0};
    q.push(start_info);
    while(!q.empty())
    {
        int cur_num = q.size();
        for(int ii=0; ii<cur_num; ii++)
        {
            Info cur = q.front();
            q.pop();

            /* 终止条件 */
            if(cur.x==target_x && cur.y == target_y)
            {
                cout << cur.path+1 << endl;
                return 0;
            }

            visited[x][y] = true;
            printf("当前位置(%d,%d) 时间%d，停留次数%d\n", cur.x, cur.y, cur.path, cur.wait_time);

            /*  递归  */
            for(int jj=0; jj<4; jj++)
            {
                int nx = cur.x + dx[jj];
                int ny = cur.y + dy[jj];
                if(nx>=0 && nx<n && ny>=0 && ny<n && graph[nx][ny][(cur.path)%3]==0 && visited[nx][ny] == false)
                {
                    Info next_info = {nx,ny,cur.path+1,0};
                    q.push(next_info);
                }
            }

            /* 可以在当前位置停留3次    */
            if(cur.wait_time < 3)
            {
                cur.path++;
                cur.wait_time++;
                q.push(cur);
            }
        }
    }


    /* 输出处理 */
    cout << " 怪兽  " << endl;
    for(auto g:boss_pos)
        cout << g[0] << " " << g[1];
    cout << endl;
    cout << " 地图  " << endl;
    for(int kk=0; kk<3; kk++)
    {
        cout << "天数" << kk << endl;
        for(int ii=0; ii<n; ii++)
        {
            for(int jj=0; jj<n; jj++)
            {
                cout << graph[ii][jj][kk] << " ";
            }
            cout << endl;
        }
    }
    cout << "没找到" << endl;

    return 0;
}