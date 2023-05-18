#include <bits/stdc++.h>
using namespace std;

int minCost(vector<int>& nums, int k) 
{
    int n = nums.size();

    /* 计算数组的重要性 */
    vector<vector<int>> importance(n, vector<int>(n, 0));
    for(int ii=0; ii<n; ii++)
    {
        unordered_map<int, int> mp;     // 记录元素出现次数
        int count = 0;                  // 记录遍历过程中只出现一次元素的个数
        for(int jj=ii; jj<n; jj++)
        {
            mp[nums[jj]]++;
            if(mp[nums[jj]] == 1)
            {
                count++;
            }
            else if(mp[nums[jj]] == 2)
            {
                count--;
            }

            /* 重要性   */
            importance[ii][jj] = jj-ii+1-count+k;
        }
    }

    vector<int> dp(n, INT_MAX);
    for(int ii=0; ii<n; ii++)
    {
        dp[ii] = importance[0][ii];
    }

    for(int ii=0; ii<n; ii++)
    {
        for(int jj=0; jj<ii; jj++)
        {
            dp[ii] = min(dp[ii], dp[jj]+importance[jj+1][ii]);
        }
    }

    return dp[n-1];
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    /* 输入处理     */

    vector<int> nums1 = {7,11,13}; 
    vector<int> nums2 = {1,1,1}; 

    cout << maximumsSplicedArray(nums1, nums2) << endl;

    return 0;
}