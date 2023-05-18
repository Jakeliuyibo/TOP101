#include <bits/stdc++.h>

using namespace std;

int mSum(vector<int>& R, int limit)
{
    int sum = 0;
    for(auto r : R)
    {
        if(r>limit) sum += limit;
        else
            sum += r;
    }
    return sum;
}



int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    /* 输入处理 */
    vector<int > R;         // 流量
    int sum = 0;
    while(1)
    {
        int r = 0;
        cin >> r;
        sum += r;
        R.push_back(r);
        if(cin.get() == '\n')
        {
            break;
        }
    }
    int cnt = 0;
    cin >> cnt;             // 最大流量

    /* 判断是否大于限制 */
    if(sum > cnt)
    {
        int N = R.size();   // 上游数量 

        /* 二分查找 */
        sort(R.begin(), R.end());
        
        for(int left=0; ; left++)
        {
            if(mSum(R, left) <= cnt)
            {
            
            }
            else
            {
                cout << left-1 << endl;
                break;
            }
        }
    }
    else
    {
        cout << -1 << endl;
    }

}