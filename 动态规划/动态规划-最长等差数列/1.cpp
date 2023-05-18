#include <bits/stdc++.h>
using namespace std;




int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    /* 输入处理     */
    int n;                                                   // 
    cin >> n;
    vector<int> num(n);                                      // 矩阵
    for(int idx=0; idx<n; idx++)
    {
        cin >> num[idx];
    }

    vector<vector<int>> dp(n, vector<int>(11, 0));     // 矩阵
    int res = 0;
    for(int ii=0; ii<n; ii++)
    {
        for(int jj=0; jj<ii; jj++)
        {
            int diff = num[ii] - num[jj] + 5;
            dp[ii][diff] = dp[jj][diff] + 1;
            res = max(res, dp[ii][diff]);
        }
    }

    for(auto dd:dp)
    {
        for(auto d:dd)
        {
            cout << d << " ";
        }
        cout << endl;
    }
    cout << res + 1<< endl;


    return 0;
}