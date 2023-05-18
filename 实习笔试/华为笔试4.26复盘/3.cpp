#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt","r", stdin);

    /* 输入处理 */
    int n,m;
    cin >> m;
    cin >> n;
    vector<vector<int>> array(n, vector<int>(2, 0));
    for(int ii=0; ii<n; ii++)
    {
        cin >> array[ii][0] >> array[ii][1];
    }

    /* 输出 */
    int res = 0;
    cout << "res " << res << endl;

    return 0;
}



