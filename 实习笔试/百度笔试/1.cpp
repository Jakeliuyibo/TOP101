#include <bits/stdc++.h>

using namespace std;



int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    /* 输入处理     */
    int n,k;
    cin >> n >> k;
    vector<int > array(n);
    for(int idx=0; idx<n; idx++)
    {
        cin >> array[idx];
    }
    sort(array.begin(), array.end());

    /* */
    double res = 0;
    double total = 0;
    int cnt = 0;
    for(int ii=0; ii<n; ii++)
    {
        if(ii < k-1)        // 计算前k-1个小数
        {
            res += array[ii];
        }
        else                // 计算后面的大数
        {
            total += array[ii];
            cnt++;
        }
    }
    res += total / cnt;     //  边界第k个

    /* 输出*/
    cout << res << endl;

    return 0;
}