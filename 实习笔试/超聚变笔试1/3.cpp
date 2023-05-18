#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int result=0;
vector<int> path;

int cal_curr_result()
{
    int sum = 0;
    for (int i = 0; i < path.size(); i++)
    {
        sum = sum + pow(10,path.size()-1-i) * path[i];
    }
    return sum;
}

/* 校验下一步是否正确   */
bool checkGoToNext(vector<vector<int> > &array, vector<vector<int> > &barr, int curr_x, int curr_y, int next_x, int next_y)
{
    if(next_x < 0 || next_x >= array.size())        return false;
    if(next_y < 0 || next_y >= array[0].size())     return false;

    /* 遍历barr数组，判断是否有限制规则 */
    for(int idx=0; idx<barr.size(); idx++)
    {
        if((barr[idx][0]==array[curr_x][curr_y]) && (barr[idx][1]==array[next_x][next_y]))
        {
            return false;
        }
    }
    return true;
}

/* 递归探索     */
void helper(vector<vector<int> > &array, vector<vector<int> > &barr, int max_steps, int ii, int jj)
{
    if(path.size() >= max_steps)
    {
        result = max(result, cal_curr_result());
        return;
    }

    /* 原地走   */
    if(checkGoToNext(array, barr, ii, jj, ii, jj))
    {
        path.push_back(array[ii][jj]);
        helper(array, barr, max_steps, ii, jj);
        path.pop_back();
    }

    /* 往上走   */
    if(checkGoToNext(array, barr, ii, jj, ii-1, jj))
    {
        path.push_back(array[ii-1][jj]);
        helper(array, barr, max_steps, ii-1, jj);
        path.pop_back();
    }

    /* 往下走   */
    if(checkGoToNext(array, barr, ii, jj, ii+1, jj))
    {
        path.push_back(array[ii+1][jj]);
        helper(array, barr, max_steps, ii+1, jj);
        path.pop_back();
    }

    /* 往左走   */
    if(checkGoToNext(array, barr, ii, jj, ii, jj-1))
    {
        path.push_back(array[ii][jj-1]);
        helper(array, barr, max_steps, ii, jj-1);
        path.pop_back();
    }

    /* 往右走   */
    if(checkGoToNext(array, barr, ii, jj, ii, jj+1))
    {
        path.push_back(array[ii][jj+1]);
        helper(array, barr, max_steps, ii, jj+1);
        path.pop_back();
    }

}

int main(){

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    vector<vector<int> > array = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int> > barr;
    int m;
    cin >> m;
    for(int i=0; i<m; i++)
    {
        int from, to;
        cin >> from >> to;
        barr.push_back({from, to});
    }
    int steps;
    cin >> steps;

    /* 随机选择起点 */
    for(int ii=0; ii<3; ii++)
    {
        for(int jj=0; jj<3; jj++)
        {
            path.push_back(array[ii][jj]);
            helper(array, barr, steps+1, ii, jj);
            path.pop_back();
        }
    }

    cout << result << endl;

    return 0;
}