#include <bits/stdc++.h>

using namespace std;

double result = DBL_MAX;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    /* 输入处理 */
    int n;
    cin >> n;
    vector<double> x(n),y(n);
    for(int idx=0; idx<n; idx++)
    {
        cin >> x[idx];
    }
    for(int idx=0; idx<n; idx++)
    {
        cin >> y[idx];
    }

    if(n==1)
    {
        printf("0\n");
    }
    else
    {
        /* 计算节点间相互距离   */
        for(int ii=0; ii<n; ii++)
        {
            for(int jj=ii+1; jj<n; jj++)
            {
                double dist = sqrt((x[ii]-x[jj])*(x[ii]-x[jj])+(y[ii]-y[jj])*(y[ii]-y[jj]));
                result = min(result, dist);
            }
        }

        printf("%.4f\n", result);
    }
    return 0;
}