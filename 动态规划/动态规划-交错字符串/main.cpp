class Solution {
public:



    bool isInterleave(string s1, string s2, string s3) 
    {
        int len1 = s1.size();
        int len2 = s2.size();
        int len3 = s3.size();
        if(len1+len2 != len3) return false;

        /* 动态规划 */
        vector<vector<bool>> dp(len1+1, vector<bool>(len2+1, false));

        /* 初始化   */
        dp[0][0] = true;
        for(int jj=1; jj<=len2; jj++)
        {
            if(s2[jj-1] == s3[jj-1])
                dp[0][jj] = dp[0][jj-1];
        }
        for(int ii=1; ii<=len1; ii++)
        {
            if(s1[ii-1] == s3[ii-1])
                dp[ii][0] = dp[ii-1][0];
        }
        /* 遍历 */
        for(int ii=1; ii<=len1; ii++)
        {
            for(int jj=1; jj<=len2; jj++)
            {
                if(s1[ii-1] == s3[ii+jj-1])
                    dp[ii][jj] = dp[ii][jj] || dp[ii-1][jj];
                if(s2[jj-1] == s3[ii+jj-1])
                    dp[ii][jj] = dp[ii][jj] || dp[ii][jj-1];
            }
        }

        return dp[len1][len2];
    }
};