#include <bits/stdc++.h>

using namespace std;

bool flagReach = false;
vector<vector<int>> bomb;
int result = -1;

vector<int> cal_dist_between(int curr_x, int curr_y)
{
    vector<int> ret;

    for(int idx=0; idx<bomb.size(); idx++)
    {
        int dist = abs(bomb[idx][0]-curr_x)+abs(bomb[idx][1] -curr_y);
        ret.push_back(dist);
        // printf("当前位置x=%d y=%d 雷位置%d,%d 扫雷距离%d \n", curr_x, curr_y, bomb[idx][0], bomb[idx][1], dist);
    }

    return ret;
}

void helper(vector<vector<int>>& map, vector<vector<int>>& history, int curr_x, int curr_y, int tar_x, int tar_y, int min_dist)
{
    /* 计算与地雷的距离，并计算当前路径下与地雷最近的步数 */
    vector<int > dist = cal_dist_between(curr_x, curr_y);
    for(auto di:dist)
    {
        min_dist = min(min_dist, di);
        // printf("当前位置x=%d y=%d 扫雷距离%d 最近距离%d\n", curr_x, curr_y, di, min_dist);
    }

    if(min_dist < result)
    {
        return;
    }

    /* 终止条件 */
    if(curr_x==tar_x && curr_y==tar_y)
    {
        flagReach = true;
        result = max(result, min_dist);
        // printf("抵达终点，result = %d\n", result);
        return;
    }

    // printf("当前位置x=%d y=%d 最近距离%d\n", curr_x, curr_y, min_dist);

    history[curr_x][curr_y] = 1;

    /* 朝4个方向走  */
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    for(int i=0; i<4; i++)
    {
        int x = curr_x + dx[i];
        int y = curr_y + dy[i];
        if(x>=0&& y>=0 && x<map.size() && y<map[0].size() && map[x][y]!=1 && history[x][y]!=1)
        {
            helper(map, history, x, y, tar_x, tar_y, min_dist);
        }
    }

    history[curr_x][curr_y] = 0;
}



int main()
{
    freopen("in.txt", "r", stdin );
    freopen("out.txt", "w", stdout);

    int n,m,k;
    cin >> n >> m >> k;

    vector<vector<int>> map(n,vector<int>(m,0));
    vector<vector<int>> history(n,vector<int>(m,0));
    

    for(int idx=0; idx<k; idx++)
    {
        int bomb_x, bomb_y;
        cin >> bomb_x >> bomb_y;
        bomb.push_back({bomb_x-1, bomb_y-1});
        map[bomb_x-1][bomb_y-1] = 1;
    }

    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;

    /* 判断能不能走到终点   */
    helper(map, history, x1-1,y1-1,x2-1,y2-1, 1001);

    if(flagReach)
    {
        cout << result << endl;
    }
    else
        cout << 0 << endl;

    return 0;
}