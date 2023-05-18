#include <bits/stdc++.h>

using namespace std;

int main() 
{
    /* 输入处理     */
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<long >> num(n, vector<long>(m, 0));
    for(int ii=0; ii<n; ii++)
    {
        for(int jj=0; jj<m; jj++)
        {
            cin >> num[ii][jj];
        }
    }

    /* DP   */
    vector<vector<long >> dp(n+1, vector<long>(m+1, 0));
    for(int ii=1; ii<=n; ii++)
    {
        for(int jj=1; jj<=m; jj++)
        {
            dp[ii][jj] = num[ii-1][jj-1] + dp[ii-1][jj] + dp[ii][jj-1] - dp[ii-1][jj-1];
        }
    }

    // for(auto dd:dp)
    // {
    //     for(auto d:dd)
    //     {
    //         cout << d << " ";
    //     }
    //     cout << endl;
    // }

    while(q--)
    {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1] << endl;
    }
    return 0;
}
// 64 位输出请用 printf("%lld")