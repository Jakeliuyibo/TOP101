#include <bits/stdc++.h>

using namespace std;

int result = 0;

void helper(vector<string>& array, int x, int y, char mask)
{
    if(array[x][y] == '0')
    {
        return;
    }

    /* 清除当前标记 */
    array[x][y] = '0';

    int dx[] = {1, -1, 0 , 0 };
    int dy[] = {0,  0, 1 ,-1 };
    for(int ii=0; ii<4; ii++)
    {
        int next_x = x + dx[ii];
        int next_y = y + dy[ii];
        if(next_x>=0&&next_y>=0&&next_x<array.size()&&next_y<array[0].size())
        {
            if(array[next_x][next_y] == mask)
            {
                helper(array, next_x, next_y, mask);
            }
        }
    }

}


int main()
{
    freopen("in.txt", "r", stdin);

    /* 输入处理 */
    int n,m;
    cin >> n >> m;
    vector<string> array;
    for(int ii=0; ii<n; ii++)
    {
        string tmp;
        cin >> tmp;
        array.push_back(tmp);
    }

    /* 搜索 */
    int result = 0;
    vector<string> arr = array;
    for(int ii=0; ii<n; ii++)
    {
        for (int jj = 0; jj < m; jj++) 
        {
            if(arr[ii][jj] != '0')
            {
                result++;
                helper(arr, ii, jj, arr[ii][jj]);
            }
        }
    }

    /* 输出 */
    cout << result << endl;

    /* 色盲模式 */
    /* 将矩阵中B替换成R */
    result = 0;
    arr.clear();
    arr = array;
    for(int ii=0; ii<n; ii++)
        for (int jj = 0; jj < m; jj++) 
            if(arr[ii][jj] == 'B')
                arr[ii][jj] = 'G';

    for(int ii=0; ii<n; ii++)
    {
        for (int jj = 0; jj < m; jj++) 
        {
            if(arr[ii][jj] != '0')
            {
                result++;
                helper(arr, ii, jj, arr[ii][jj]);
            }
        }
    }
    /* 输出 */
    cout << result << endl;
    return 0;
}