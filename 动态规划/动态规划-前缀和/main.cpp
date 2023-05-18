#include <bits/stdc++.h>

using namespace std;

int main() 
{
    /* 输入处理 */
    int n,q;
    cin >> n >> q;
    vector<long long int> array(n);
    for(int idx=0; idx<n; idx++)
    {
        cin >> array[idx];
    }

    /* DP   */
    vector<long long int> dp(n+1, 0);
    for(int ii=1; ii<=n; ii++)
    {
        dp[ii] = dp[ii-1] + array[ii-1];
    }

    while(q--)
    {
        int left, right;
        cin >> left >> right;
        cout << dp[right]-dp[left-1] << endl;
    }

    return 0;
}
// 64 位输出请用 printf("%lld")