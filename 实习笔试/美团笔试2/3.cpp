#include <bits/stdc++.h>

using namespace std;


int helper(vector<int >& volume, int n, int m, int s)
{
    /* 水果-果篮    */
    vector<vector<int >> ans(n, vector<int>(n, INT_MAX));

    for(int ii=0; ii<n; ii++)
    {
        int max_v = volume[ii];
        int min_v = volume[ii];
        int tmp   = INT_MAX;
        for(int jj=0; jj<ii; jj++)
        {
            tmp = min(tmp, ans[jj][ii-1]);
        }

        for(int jj=ii; jj<(ii+m) && jj<n; jj++)
        {
            max_v = max(volume[jj], max_v);
            min_v = min(volume[jj], min_v);

            if(ii==0)
                ans[ii][jj] = min(ans[ii][jj], (jj-ii+1)*int((max_v+min_v)/2)+s);
            else
                ans[ii][jj] = min(ans[ii][jj], (jj-ii+1)*int((max_v+min_v)/2)+s+tmp);
        }
    }

    /* 处理结果 */
    int result = INT_MAX;
    for(int idx=0; idx<n; idx++)
    {
        result = min(result, ans[idx][n-1]);
    }
    return result;
}



int main()
{
    freopen("in.txt", "r", stdin );
    freopen("out.txt", "w", stdout);

    int n,m,s;
    cin >> n >> m >> s;

    vector<int > volume;
    for(int idx=0; idx<n; idx++)
    {
        int tmp;
        cin >> tmp;
        volume.push_back(tmp);
    }

    /* 递归回溯 */
    int res = helper(volume, n, m, s);
    cout << res << endl;

    return 0;
}