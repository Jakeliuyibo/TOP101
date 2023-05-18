#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);

    /* 输入处理 */
    int n,m;
    cin >> n >> m;
    string str1,str2;
    cin >> str1;
    cin >> str2;

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int ii=1; ii<=n; ii++)
    {
        for (int jj=1; jj<=m; jj++) 
        {
            if(str1[ii-1] == str2[jj-1])
            {
                dp[ii][jj] = dp[ii-1][jj-1] + 1;
            }
            else
            {
                dp[ii][jj] = max(dp[ii-1][jj], dp[ii][jj-1]);
            }
        }
    }

    /* 输出 */
    for(auto dd:dp)
    {
        for(auto d:dd)
        {
            cout << d << " ";
        }
        cout << endl;
    }

    cout << dp[dp.size()-1][dp[0].size()-1] << endl;
    return 0;
}