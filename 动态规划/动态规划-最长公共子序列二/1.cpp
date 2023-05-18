
class Solution {
public:
    /**
     * longest common subsequence
     * @param s1 string字符串 the string
     * @param s2 string字符串 the string
     * @return string字符串
     */
    string LCS(string s1, string s2) 
    {
        int n = s1.size();
        int m = s2.size();

        /* DP求公共子序列    */
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int ii=1; ii<=n; ii++)
        {
            for(int jj=1; jj<=m; jj++)
            {
                if(s1[ii-1] == s2[jj-1])        // 字符相等
                    dp[ii][jj] = 1 + dp[ii-1][jj-1];    
                else                            // 不相等
                    dp[ii][jj] = max(dp[ii-1][jj], dp[ii][jj-1]);
            }
        }

        /* */
        if(dp[n][m] == 0)
        {
            return "-1";
        }
        else
        {
            /* 回溯路径 */
            string ret = "";
            int ii = n;
            int jj = m;
            while(ii>0&&jj>0)
            {
                if(dp[ii][jj] == dp[ii-1][jj-1])
                {
                    ii--;jj--;
                }
                else if(dp[ii][jj] == dp[ii-1][jj])
                    ii--;
                else if(dp[ii][jj] == dp[ii][jj-1])
                    jj--;
                else
                {
                    ret.push_back(s1[ii-1]);
                    ii--;
                    jj--;
                }
            }

            reverse(ret.begin(), ret.end());

            return ret;
        }
    }
};