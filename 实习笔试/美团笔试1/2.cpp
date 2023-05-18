#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);

    /* 处理输入数据     */
    int n;
    cin >> n;
    vector<int> array;
    while (n--)
    {   
        int a;
        cin >> a;
        array.push_back(a);
    }

    sort(array.begin(), array.end());
    
    int res = 0;
    for(int idx=0; idx<array.size(); idx++)
    {
        if((idx+1)<array.size())
        {
            res += abs(array[idx]- array[idx+1]);
        }
    }
    cout << res << endl;

    return 0;
}