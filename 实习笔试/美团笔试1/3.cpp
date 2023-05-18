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
    int m;
    cin >> n >> m;
    vector<int> array(n, 0);
    
    vector<int > op;
    vector<int > x;
    vector<int > y;
    for(int i=0; i<m; i++)
    {
        int a;  cin >> a;
        op.push_back(a);
    }
    for(int i=0; i<m; i++)
    {
        int a;  cin >> a;
        x.push_back(a);
    }
    for(int i=0; i<m; i++)
    {
        int a;  cin >> a;
        y.push_back(a);
    }

    vector<int > result;
    
    /* 处理op操作   */
    for(int i=0; i<m; i++)
    {
        if(op[i]==1)
        {
            /* 查询操作 */
            int sum = 0;
            for(int j=x[i]; j<=y[i]; j++)
            {
                sum += array[j];
            }
            /* 添加到result中   */
            result.push_back(sum);
        }
        else
        {
            /* 修改操作 */
            array[x[i]] = y[i];
        }
    }

    /* 输出处理 */
    for(int i=0; i<result.size(); i++)
    {
        cout << result[i];
        if(i != result.size()-1)
        {
            cout << " ";
        }
    }

    return 0;
}