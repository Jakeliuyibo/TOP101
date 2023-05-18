#include <bits/stdc++.h>
using namespace std;


int minHeightShelves(vector<vector<int>>& books, int shelfWidth) 
{
    int n = books.size();       // 数本数量

    vector<int> dp(n+1, 0);
    for(int ii=1; ii<=n; ii++)
    {
        int curr_width  = 0;
        int curr_height = 0;
        dp[ii] = INT_MAX;
        for(int jj=ii-1; jj>=0; jj--)
        {
            curr_width += books[jj][0];                      // 计算(ii-1)-(0)的宽度
            if(curr_width > shelfWidth)                     // 超出限制，最大能容纳jj-ii的书籍
            {
                break;
            }
            curr_height = max(curr_height, books[jj][1]);
            dp[ii] = min(dp[ii], dp[jj]+curr_height);
        }
    }

    // for(auto d:dp)
    // {
    //     cout << d << " ";
    // }
    // cout << endl;


    return dp[n];
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