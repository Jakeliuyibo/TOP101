#include <bits/stdc++.h>
#include <climits>

using namespace std;

struct GOODS
{
    int weight;
    int value;
};

int main()
{
    freopen("in.txt", "r", stdin);
    
    /* 输入处理 */
    int n;                                                              // 物品数量
    int V;                                                              // 背包体积
    cin >> n >> V;
    GOODS goods[n];
    // vector<vector<int>> array(n, vector<int>(2, 0));     // 0:体积 1:价值
    for(int idx=0; idx<n; idx++)
    {
        cin >> goods[idx].weight >> goods[idx].value;
    }

    /* DP : 求不放满情况下最大价值  */
    vector<vector<int>> dp(n+1, vector<int>(V+1, 0));
    for(int ii=1; ii<=n; ii++)
    {
        for(int jj=1; jj<=V; jj++)
        {
            int value_no_push = dp[ii-1][jj];
            int value_push    = 0;
            if(jj>=goods[ii-1].weight)  // 放得下
            {
                value_push    = dp[ii-1][jj-goods[ii-1].weight] + goods[ii-1].value;
            }
            dp[ii][jj] = max(value_no_push, value_push);
        }
    }
    cout << dp[dp.size()-1][dp[0].size()-1] << endl;

    /* DP : 求放满情况下最大价值  */
    vector<vector<int>> dp2(n+1, vector<int>(V+1, INT_MIN));
    for(int ii=0; ii<=n; ii++)    dp2[ii][0] = 0;

    for(int ii=1; ii<=n; ii++)
    {
        for(int jj=1; jj<=V; jj++)
        {
            int value_no_push = dp2[ii-1][jj];
            int value_push    = INT_MIN;
            if(jj>=goods[ii-1].weight)  // 放得下
            {
                value_push    = dp2[ii-1][jj-goods[ii-1].weight] + goods[ii-1].value;
            }
            dp2[ii][jj] = max(value_no_push, value_push);
        }
    }
    /* 输出处理 */
    if(dp2[dp2.size()-1][dp2[0].size()-1]>0)
        cout << dp2[dp2.size()-1][dp2[0].size()-1] << endl;
    else
        cout << 0 << endl;
    // for(auto dd:dp2)
    // {
    //     for(auto d:dd)
    //         cout << d << " ";
    //     cout << endl;
    // }


    return 0;
}