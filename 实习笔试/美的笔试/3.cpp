#include <bits/stdc++.h>

using namespace std;

int size = 10;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    /* 输入处理 */
    int n, m;
    cin >> n >> m;
    string S, T;
    cin >> S;
    cin >> T;

    /* 动态规划 */

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int ii=1; ii<=n; ii++)
    {
        for(int jj=1; jj<=m; jj++)
        {
            if(S[ii-1]==T[jj - 1])
            {
                dp[ii][jj] = dp[ii-1][jj-1] + 1;
            }
            else
            {
                dp[ii][jj] = max(dp[ii-1][jj], dp[ii][jj-1]);
            }
        }
    }

    /* 输出处理 */
    // for(auto d:dp)
    // {
    //     for(auto i:d)
    //     {
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[n][m] << endl;


    return 0;
}