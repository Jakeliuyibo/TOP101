#include <bits/stdc++.h>


using namespace std;


typedef pair<int, int>PAIR;


void helper(vector<string>& map, int init_x, int init_y, int tar_x, int tar_y, vector<vector<int>>& path)
{
    queue<PAIR> que;
    path[init_x][init_y] = 1;
    que.push({init_x, init_y});
    while(!que.empty())
    {
        /* 获取当前元素 */
        PAIR curr = que.front();
        que.pop();


        /* 朝4个方向走  */
        int dx[4] = {1,0,-1, 0};
        int dy[4] = {0,1, 0,-1};
        for(int idx=0 ; idx<4; idx++)
        {
            /* 判断路径是否可走 */
            int x = curr.first + dx[idx];
            int y = curr.second + dy[idx];
            if(x>=0&&y>=0&&x<map.size()&&y<map[0].size()&&map[x][y]!='*')
            {
                if(path[x][y]==0)   /* 没走过   */
                {
                    path[x][y] = path[curr.first][curr.second]+1;
                    
                    /* 提前终止条件，走到了目的地 */
                    if(curr.first==tar_x && curr.second == tar_y)
                    {
                        return;
                    }

                    que.push({x,y});
                }
                else                /* 走过了   */
                {

                }

            }
        }
    }   
}


int main() 
{
    freopen("in.txt", "r" , stdin);
    freopen("out.txt", "w", stdout);

    /* 输入处理     */
    int n, m;
    cin >> n >> m;

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    vector<string> map;
    for(int row=0; row<n; row++)
    {
        string st;
        cin >> st;
        map.push_back(st);
    }

    /* 广度优先搜索 */
    vector<vector<int>> path(n, vector<int>(m, 0));
    helper(map, x1-1, y1-1, x2-1, y2-1, path);

    for(auto pa:path)
    {
        for(auto p:pa)
        {
            cout << p << " ";
        }
        cout << endl;
    }

    if(path[x2-1][y2-1] == 0)
        cout << "-1" << endl;
    else
        cout << path[x2-1][y2-1] << endl;

    return 0;

}