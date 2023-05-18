#include <bits/stdc++.h>
#include <climits>

using namespace std;

struct GOODS
{
    int volume;
    int value;
    GOODS(int a, int b) : volume(a), value(b) {}
};

int main()
{

    /* 输入处理 */
    int n;                                                              // 物品数量
    int V;                                                              // 背包体积
    cin >> n >> V;
    vector<GOODS > goods(n, {0,0});                         // 物品体积。价值
    for(int idx=0; idx<n; idx++)
    {
        cin >> goods[idx].volume >> goods[idx].value;
    }

    /* DP : 求不放满情况下最大价值  */
    vector<vector<int>> dp(n+1, vector<int>(V+1, 0));
    for(int ii=1; ii<=n; ii++)
    {
        GOODS curr_goods = goods[ii-1]; 
        for(int jj=1; jj<=V; jj++)
        {
            int curr_max = dp[ii-1][jj];
            for(int kk=1; kk*curr_goods.volume<=jj; kk++)
                curr_max = max(curr_max, kk*curr_goods.value + dp[ii-1][jj-kk*curr_goods.volume]);

            dp[ii][jj] = curr_max;
        }
    }
    cout << dp[dp.size()-1][dp[0].size()-1] << endl;


    /* DP : 求放满情况下最大价值  */
    vector<vector<int>> dp1(n+1, vector<int>(V+1, INT_MIN));
    for(int ii=0; ii<=n; ii++)    dp1[ii][0] = 0;

    for(int ii=1; ii<=n; ii++)
    {
        GOODS curr_goods = goods[ii-1];
        for(int jj=1; jj<=V; jj++)
        {
            int curr_max = dp1[ii-1][jj];
            /* 尝试装k个    */
            for(int kk=1; kk*curr_goods.volume<=jj; kk++)
                curr_max = max(curr_max, kk*curr_goods.value + dp1[ii-1][jj-kk*curr_goods.volume]);

            dp1[ii][jj] = curr_max;
        }
    }
    if(dp1[dp1.size()-1][dp1[0].size()-1] < 0)
        cout << 0 << endl;
    else
        cout << dp1[dp1.size()-1][dp1[0].size()-1] << endl;

    // /* 输出处理 */
    // for(auto dd:dp)
    // {
    //     for(auto d:dd)
    //         cout << d << " ";
    //     cout << endl;
    // }


    return 0;
}