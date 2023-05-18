#include <bits/stdc++.h>


using namespace std;

int maxProfit(vector<int>& prices) 
{
    int n = prices.size();

    vector<int> dp(n, 0);
    int min_prices = prices[0];
    for(int ii=1; ii<n; ii++)
    {
        dp[ii] = max(dp[ii-1], prices[ii] - min_prices);
        min_prices = min(min_prices, prices[ii]);
    }

    return dp[n-1];
}