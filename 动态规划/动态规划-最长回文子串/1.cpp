#include <algorithm>
#include <unistd.h>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param A string字符串 
     * @return int整型
     */
    int getLongestPalindrome(string A) 
    {
        int n = A.size();
        int res = 0;
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int right=1; right<=n; right++)
        {
            for(int left=1; left<=right; left++)
            {
                if(A[left-1] == A[right-1])  // 字符串相等
                {
                    if(left==right)          // 只有一个字符
                    {
                        dp[left][right] = 1;
                    }
                    else if(right - left <= 2) // 两个字符aa,aba
                    {
                        dp[left][right] = 1;
                    }
                    else 
                    {
                        dp[left][right] = dp[left+1][right-1];
                    }

                    if(dp[left][right] == 1)
                    {
                        res = max(res, right-left+1);
                    }
                }
                else                    // 不相等
                {

                }
            }
        }

        for(auto dd:dp)
        {
            for(auto d:dd)
            {
                cout << d << " ";
            }
            cout << endl;
        }
        cout << res  << endl;

        return res;
    }
};