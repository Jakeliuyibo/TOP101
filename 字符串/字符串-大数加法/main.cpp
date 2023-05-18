#include <iostream>
#include <iterator>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cstddef>

using namespace std;



/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 * 计算两个数之和
 * @param s string字符串 表示第一个整数
 * @param t string字符串 表示第二个整数
 * @return string字符串
 */
string solve(string s, string t) 
{
    string ret = "";
    int ii = s.size() - 1;
    int jj = t.size() - 1;

    int num = 0;
    while(ii>=0 || jj>=0)
    {
        char c = '0';

        if(ii>=0)
            num += s[ii--] - '0';
        if(jj>=0)
            num += t[jj--] - '0';

        /* 判断是否有余数   */
        if(num >= 10)
        {
            c  += num%10;
            num = 1;
        }
        else
        {
            c  += num;
            num = 0;
        }

        ret = c + ret;
    }

    /* 边界处理 */
    if(num == 1)
    {
        ret = '1' + ret;
    }

    return ret;
}


int main() 
{
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);

    string s,t;
    cin >> s;
    cin >> t;
    cout << solve(s,t)<< endl;

}