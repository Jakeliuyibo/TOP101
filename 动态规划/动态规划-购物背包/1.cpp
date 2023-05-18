#include <bits/stdc++.h>

using namespace std;

struct GOODS
{
    int prices;
    int importance;
    int q;
    vector<GOODS> fujian;
};


int main()
{
    /* 输入处理     */
    int N;                        // 钱
    int m;                        // 物品个数
    cin >> N >> m;
    vector<GOODS> goods(m);     // v：价格 p:重要度 q：主件编号
    for(int ii=0; ii<m; ii++)
    {
        int v, p, q;
        cin >> v >> p >> q;
        goods[ii].prices     = v;
        goods[ii].importance = v*p;
        goods[ii].q          = q;
        if(q==0)                // 主件
        {
        }
        else                    // 附件
        {
            goods[q-1].fujian.push_back(goods[ii]);
        }
    }
    /* 构建主件 */
    vector<GOODS> main_goods;
    for(int ii=0; ii<m; ii++)
    {
        if(goods[ii].q == 0)
        {
            main_goods.push_back(goods[ii]);
        }
    }

    // for(auto dd:main_goods)
    // {
    //     cout << dd.prices << " " << dd.importance << " ";
    //     if(dd.fujian.size() > 0)
    //     {
    //         for(auto d:dd.fujian)
    //         {
    //             cout << d.prices << " " << d.importance << " ";
    //         }
    //     }
    //     cout << endl;
    // }

    /* DP   ·       */
    vector<vector<int>> dp(main_goods.size()+1, vector<int>(N+1, 0));
    for(int ii=1; ii<=main_goods.size(); ii++)
    {
        GOODS curr_goods = main_goods[ii-1];
        
        for(int jj=1; jj<=N; jj++)
        {
            int curr_max = dp[ii-1][jj];

            /* 其次检测是否买得起   */
            if(jj>=curr_goods.prices)
            {
                /* 单买主件 */
                curr_max = max(curr_max, dp[ii-1][jj-curr_goods.prices] + curr_goods.importance);

                /* 单买主件+1个附件   */
                if(curr_goods.fujian.size() >= 1)
                {
                    if(jj>=(curr_goods.prices+curr_goods.fujian[0].prices))
                        curr_max = max(curr_max, dp[ii-1][jj-curr_goods.prices-curr_goods.fujian[0].prices] + curr_goods.importance+curr_goods.fujian[0].importance);
                    if(jj>=(curr_goods.prices+curr_goods.fujian[1].prices))
                        curr_max = max(curr_max, dp[ii-1][jj-curr_goods.prices-curr_goods.fujian[1].prices] + curr_goods.importance+curr_goods.fujian[1].importance);
                }

                /* 单买主件+2个附件   */
                if(curr_goods.fujian.size() == 2)
                {
                    if(jj>=(curr_goods.prices+curr_goods.fujian[0].prices+curr_goods.fujian[1].prices))
                        curr_max = max(curr_max, 
                                                dp[ii-1][jj -curr_goods.prices
                                                              -curr_goods.fujian[0].prices
                                                              -curr_goods.fujian[1].prices] 
                                                +curr_goods.importance
                                                +curr_goods.fujian[0].importance
                                                +curr_goods.fujian[1].importance);
                }
            }

            dp[ii][jj] = curr_max;
        }
    }


    /* 输出处理     */
    // for(auto dd:dp)
    // {
    //     for(auto d:dd)
    //         cout << d << " ";
    //     cout << endl;
    // }
    cout << dp[dp.size()-1][dp[0].size()-1] << endl;


    return 0;
}