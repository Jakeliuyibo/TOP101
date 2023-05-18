#include <bits/stdc++.h>

using namespace std;

int main() 
{
    /* 输入处理     */
    string str1;
    string str2;
    cin >> str1;
    cin >> str2;
    int n = str1.size();
    int m = str2.size();

    /* DP   */
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int ii=1; ii<=n; ii++) dp[ii][0] = ii;
    for(int jj=1; jj<=m; jj++) dp[0][jj] = jj;
    for(int ii=1; ii<=n; ii++)
    {
        for(int jj=1; jj<=m; jj++)
        {
            int cmp1 = 1 + dp[ii-1][jj];
            int cmp2 = 1 + dp[ii][jj-1];
            int cmp3 = dp[ii-1][jj-1];
            
            if(str1[ii-1] != str2[jj-1])        // 相等
            {
                cmp3 ++;
            }

            dp[ii][jj] = min(min(cmp1, cmp2), cmp3);
        }
    }

    /* 输出处理 */
    // for(auto dd:dp)
    // {
    //     for(auto d:dd)
    //     {
    //         cout << d << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[n][m] << endl;
}
// 64 位输出请用 printf("%lld")



// class Solution {
// public:
//     int minDistance(string word1, string word2) 
//     {
//         int n = word1.size();
//         int m = word2.size();

//         vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
//         /* 初始化第0行  */
//         for(int jj=1; jj<=m; jj++)
//         {
//             dp[0][jj] = dp[0][jj-1]+1;
//         }
//         /* 初始化第0列  */
//         for(int ii=1; ii<=n; ii++)
//         {
//             dp[ii][0] = dp[ii-1][0]+1;
//         }

//         /* 遍历 */
//         for(int ii=1; ii<=n; ii++)
//         {
//             for(int jj=1; jj<=m; jj++)
//             {
//                 if(word1[ii-1] == word2[jj-1])
//                 {
//                     dp[ii][jj] = dp[ii-1][jj-1];
//                 }
//                 else
//                 {
//                     dp[ii][jj] = min(dp[ii-1][jj-1],min(dp[ii-1][jj], dp[ii][jj-1])) + 1;
//                 }
//             }
//         }

//         return dp[n][m];
//     }
// };