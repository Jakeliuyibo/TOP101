#include <bits/stdc++.h>

using namespace std;


int max_idx = -1;
int max_len = 0;


int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    /* 输入处理 */
    string str1, str2;
    cin >> str1;
    cin >> str2;
    vector<vector<int>> dp(str1.size()+1, vector<int>(str2.size()+1, 0));

    /* 动态规划 */
    for(int ii=1; ii<=str1.size(); ii++)
    {
        for(int jj=1; jj<=str2.size(); jj++)
        {
            if(str1[ii-1] == str2[jj-1])
            {
                dp[ii][jj] = dp[ii-1][jj-1] + 1;
            }
            else
            {
                dp[ii][jj] = 0;
            }

            /* 记录最大位置 */
            if(dp[ii][jj] > max_len)
            {
                max_len = dp[ii][jj];
                max_idx = ii-1;
            }
        }
    }

    /* 输出     */
    for(auto dd:dp)
    {
        for(auto d:dd)
        {
            cout << d << " ";
        }
        cout << endl;
    }

    printf("max_len=%d max_idx=%d end\n", max_len, max_idx);
    string sub = str1.substr(max_idx-max_len+1, max_len);
    for(auto s:sub)
    {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}