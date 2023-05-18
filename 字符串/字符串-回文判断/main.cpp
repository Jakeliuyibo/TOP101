#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;


/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 * 
 * @param str string字符串 待判断的字符串
 * @return bool布尔型
 */
bool judge(string str) 
{
    int len = str.size();

    int ii = 0;
    int jj = len-1;
    for(; ii < len/2; )
    {
        if(str[ii] != str[jj])
        {
            return false;
        }
        ii++;
        jj--;
    }
    return true;
}

int main() 
{
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);

    string s;
    cin >> s;
    cout << judge(s)<< endl;

}