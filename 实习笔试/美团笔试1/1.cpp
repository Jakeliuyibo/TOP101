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

    int m;
    cin >> m;
    string opr;
    for(int idx=0; idx<2*m; idx++)
    {
        char tmp;
        cin >> tmp;
        opr.push_back(tmp);
    }

}