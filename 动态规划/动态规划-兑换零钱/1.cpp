
#include <climits>
class Solution {
public:
    /**
     * 最少货币数
     * @param arr int整型vector the array
     * @param aim int整型 the target
     * @return int整型
     */
    int minMoney(vector<int>& arr, int aim) 
    {
        int n = arr.size();
        if(n==0)    return -1;

        /* DP   */
        vector<vector<int>> dp(n+1, vector<int>(aim+1, aim+1));
        for(int ii=1; ii<=n; ii++) dp[ii][0] = 0;             // 初始化
        for(int ii=1; ii<=n; ii++)              // 物品
        {
            for(int jj=1; jj<=aim; jj++)        // 容量
            {
                int curr_min = dp[ii-1][jj];    // 上一张钱的张树
                for(int kk=1; kk*arr[ii-1]<=jj; kk++)
                    curr_min = min(curr_min, dp[ii][jj-kk*arr[ii-1]]+kk);
                dp[ii][jj] = curr_min;
            }
        }

        /* 求最后一列最小值 */
        if(dp[n][aim] == aim+1)
        {
            return -1;
        }

        /* */
        return dp[n][aim];
    }
};


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        int num_coin = coins.size();

        /* 动态规划 */
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;

        for(int ii=1; ii<=amount; ii++)               // 遍历价格
        {
            for(int jj=0; jj<num_coin; jj++)          // 遍历币钟
            {
                int coin_val = coins[jj];      // 当前币种单价
                if(coin_val <= ii)
                    dp[ii] = min(dp[ii], dp[ii-coin_val] + 1);
            }
        }

        if(dp[amount] == amount+1)
            return -1;
        else
            return dp[amount];
    }
};