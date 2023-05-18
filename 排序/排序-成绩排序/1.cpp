#include <bits/stdc++.h>

using namespace std;

typedef pair<string, int>PAIR;

bool cmp0(PAIR p1, PAIR p2)
{
    return p1.second > p2.second ? true: false;
}

bool cmp1(PAIR p1, PAIR p2)
{
    return p1.second < p2.second ? true: false;
}

int main()
{
    /* 输入处理     */
    int n;
    int flag;
    cin >> n;
    cin >> flag;
    vector<PAIR> store(n);

    for(int idx=0; idx<n; idx++)
    {
        cin >> store[idx].first >> store[idx].second;
    }

    if(flag == 0)           // 从大到小
    {
        stable_sort(store.begin(), store.end(), cmp0);
    }
    else
    {
        stable_sort(store.begin(), store.end(), cmp1);
    }

    /* 输出 */
    for(int idx=0; idx<n; idx++)
    {
        cout << store[idx].first << " " << store[idx].second << endl;
    }

    return 0;
}