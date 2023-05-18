class Solution {
public:


    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) 
    {
        int n = fruits.size();          // 水果数量

        /* 求水果区间矩阵   */
        vector<int> pos(n, 0);          // 位置矩阵
        vector<int> arr(n+1, 0);          // 水果累计矩阵
        for(int ii=0; ii<n; ii++)
        {
            pos[ii] = fruits[ii][0];
            arr[ii+1] = arr[ii]+fruits[ii][1];
        }

        /* 第一种走法：先往右走    */
        int res = 0;
        int left, right;
        int leftIdx, rightIdx;
        for(int x=0; x<=k/2; x++)
        {
            /* 先往左走 */
            left  = startPos - x;
            right = left + (k-x);
            leftIdx  = lower_bound(pos.begin(), pos.end(), left) - pos.begin();
            rightIdx = upper_bound(pos.begin(), pos.end(), right) - pos.begin();
            res = max(res, arr[rightIdx]-arr[leftIdx]);

            /* 先往右走 */
            right = startPos + x;
            left  = right - (k-x);
            leftIdx  = lower_bound(pos.begin(), pos.end(), left) - pos.begin();
            rightIdx = upper_bound(pos.begin(), pos.end(), right) - pos.begin();
            res = max(res, arr[rightIdx]-arr[leftIdx]);
        }

        return res;
    }
};