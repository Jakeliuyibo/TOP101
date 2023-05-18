#include <bits/stdc++.h>

using namespace std;


int result = 0;

void helper(vector<vector<string>>& map, int n, int m, int a)
{
    /* 交换座位 */
    vector<vector<string>> tmp = map;
    vector<string>   last = tmp.back();
    tmp.pop_back();
    tmp.insert(tmp.begin(), last);
    for(int idx=0; idx<n; idx++)
    {
        string t = tmp[idx].back();
        tmp[idx].pop_back();
        tmp[idx].insert(tmp[idx].begin(), t);
    }

    /* 检查需要调整的次数   */
    for(int ii=0; ii<n; ii++)
    {
        for(int jj=0; jj<m; jj++)
        {
            for(int kk=0; kk<a; kk++)
            {
                if(map[ii][jj][kk] != tmp[ii][jj][kk])
                    result++;
            }
        }
    }
}



int main()
{
    freopen("in.txt", "r", stdin );
    freopen("out.txt", "w", stdout);

    /* 输入处理     */
    int n,m,a;
    cin >> n >> m >> a;

    vector<vector<string>> map(n,vector<string>(m));

    for(int ii=0; ii<n; ii++)
    {
        for(int jj=0; jj<m; jj++)
        {
            cin >> map[ii][jj];
        }
    }

    helper(map, n, m, a);
    cout << result << endl;

    return 0;
}