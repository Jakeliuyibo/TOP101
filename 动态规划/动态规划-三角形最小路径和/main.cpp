#include <bits/stdc++.h>

using namespace std;


int minTrace(vector<vector<int> >& triangle) 
{
    int n = triangle.size();

    vector<vector<int>> dp(n+2, vector<int>(n+2, INT_MAX));

    dp[1][1] = triangle[0][0];
    for(int ii=2; ii<=n; ii++)
    {
        for(int jj=1; jj<=ii; jj++)
        {
            /* 计算自身成本 */
            int cost_self = triangle[ii-1][jj-1];

            /* 计算上行邻居成本 */
            int cost_last_min = INT_MAX;
            int dy[3] = {-1,0,1};
            for(int kk=0; kk<3; kk++)
            {
                if(dp[ii-1][jj+dy[kk]] != INT_MAX)
                    cost_last_min = min(cost_last_min, dp[ii-1][jj+dy[kk]]);
            }

            /* 更新dp   */
            dp[ii][jj] = cost_self + cost_last_min;
        }
    }

    for(auto tr:dp)
    {
        for(auto d:tr)
            cout << d << " ";
        cout << endl;
    }


    /* dp最后第二行为最终结果 */
    vector<int > result = dp[dp.size()-2];
    sort(result.begin(), result.end());
    return result.front();
}


int main()
{
    freopen("out.txt", "w", stdout);

    vector<vector<int>> array = {{-7}, {-2,1},{-5,-5,9},{-4,-5,4,4},{-6,-6,2,-1,-5},{3,7,8,-3,7,-9},{-9,-1,-9,6,9,0,7},{-7,0,-6,-8,7,1,-4,9},{-3,2,-6,-9,-7,-6,-9,4,0},{-8,-6,-3,-9,-2,-6,7,-5,0,7},{-9,-1,-2,4,-2,4,4,-1,2,-5,5},{1,1,-6,1,-2,-4,4,-2,6,-6,0,6},{-3,-3,-6,-2,-6,-2,7,-9,-5,-7,-5,5,1}};

    cout << minTrace(array) << endl;
}