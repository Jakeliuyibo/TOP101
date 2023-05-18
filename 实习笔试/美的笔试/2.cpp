#include <bits/stdc++.h>

using namespace std;

bool isValid(double pos, int n, int k, vector<double>& Li)
{
    int count = 0;
    for(int idx=0; idx<n; idx++)
    {
        count += Li[idx] / pos;
    }
    return count>=k;

}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    /* 输入处理 */
    int n, k;
    cin >> n >> k;
    vector<double> Li(n);
    for(int idx=0; idx<n; idx++)
    {
        cin >> Li[idx];
    }
    sort(Li.begin(), Li.end());

    /* 双指针   */
    double left = 0;
    double right = Li.back();
    while(left<=right)
    {
        double mid = (left+right)/2;
        printf("left=%.4f right=%.4f mid=%.4f\n", left, right, mid);

        if(isValid(mid, n, k, Li))
            left = mid + 0.0001;
        else
            right = mid - 0.0001;
    }

    // /* 输出处理 */
    printf("%.2lf\n", right);

    return 0;
}