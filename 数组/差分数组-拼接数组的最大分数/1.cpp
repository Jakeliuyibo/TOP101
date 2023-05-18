#include <bits/stdc++.h>
using namespace std;

/* 贪心求最大和 */
int tanxin_max(vector<int> &arr)
{
    int res = INT_MIN;
    int n = arr.size();

    vector<int> dp(n+1, INT_MIN);
    dp[0] = 0;
    for(int ii=1; ii<=n; ii++)
    {
        dp[ii] = max(arr[ii-1], dp[ii-1]+arr[ii-1]);
        res = max(res, dp[ii]);
    }
    return res;
}

/* 贪心求最小和 */
int tanxin_min(vector<int> &arr)
{
    int res = INT_MAX;
    int n = arr.size();

    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;
    for(int ii=1; ii<=n; ii++)
    {
        dp[ii] = min(arr[ii-1], dp[ii-1]+arr[ii-1]);
        res = min(res, dp[ii]);
    }
    return res;
}

/* 求vector和   */
int cal_array_sum(vector<int> &arr)
{
    int sum = 0;
    for(int idx=0; idx<arr.size(); idx++)
    {
        sum += arr[idx];
    }
    return sum;
}


int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) 
{
    int n = nums1.size();

    /* 计算差值 */
    vector<int> diff(n, 0);
    for(int idx=0; idx<n; idx++)
    {
        diff[idx] = nums1[idx] - nums2[idx];
    }

    /* 求解将nums2移到nums1 */
    cout << cal_array_sum(nums1) << " " << tanxin_min(diff) << endl;
    cout << cal_array_sum(nums2) << " " << tanxin_max(diff) << endl;

    int res1 = accumulate(nums1.begin(), nums1.end(), 0) + abs(min(0, tanxin_min(diff)));
    int res2 = accumulate(nums2.begin(), nums2.end(), 0) + abs(max(0, tanxin_max(diff)));
    // int res1 = cal_array_sum(nums1) + abs(min(0, tanxin_min(diff)));
    // int res2 = cal_array_sum(nums2) + abs(max(0, tanxin_max(diff)));

    return max(res1, res2);
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