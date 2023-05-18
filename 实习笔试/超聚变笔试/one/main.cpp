// 给定两个字符集合，一个为全量字符集，一个为已占用字符集。已占用的字符集中的字符不能再使用，要求输出剩余可用字符集。
// 输入描述：输入为一个字符串，字符串中包含了全量字符集和已占用字符集，两个字符集使用@连接，前面为全量，后面为已占用。
// 已占用字符集中的字符一定是全量字符集中的字符。
// 字符集中的字符跟字符之间用英文逗号分隔。
// 字符集中的字符表示为字符加数字，字符跟数字使用英文冒号分隔，比如a:1,表示1个a字符。字符只考虑英文字母，区分大小写，数字只考虑正整形，数量不超过100，如果一个字符都没被占用，@标识仍然存在，例如a:3,b:5,c:2@
// 示例1：
// 输入
// a:3,b:5,c:2@a:1,b:2
// 输出
// a:2,b:3,c:2
// 注意：输出的字符顺序要跟输入一致！如果某个字符已全被占用，不需要再输出！
// 示例2：
// 输入
// a:3,b:5,c:2@a:3,b:2
// 输出
// b:3,c:2

#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>

using namespace std;

char ans[60];

int main()
{
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);

    char input_str[100010];
    cin >> input_str;
    int len = strlen(input_str);

    map<char,int> mp;

    char char_list[100];
    int idx = 0;

    int ii  = 0;
    for(ii=0 ; ii<len ; ii++)
    {
        if((input_str[ii]>='a' && input_str[ii]<='z') || (input_str[ii]>='A' && input_str[ii]<='Z'))
        {
            char curr_char = input_str[ii];
            /* 偏移两个字符取数字   */
            ii += 2;
            int curr_data = 0;
            while(input_str[ii]>='0' && input_str[ii]<='9')
            {
                /* 获取当前数据 */
                curr_data = 10*curr_data + input_str[ii] - '0';
                ii++;
            }
            mp[curr_char] = curr_data;

            /* 记录当前字符顺序 */
            char_list[idx] = curr_char;
            idx++;
        }

        if(input_str[ii] == '@') break;
    }

    /* */
    for(int jj=ii+1; jj<len; jj++)
    {
        if((input_str[jj]>='a' && input_str[jj]<='z') || (input_str[jj]>='A' && input_str[jj]<='Z'))
        {
            char curr_char = input_str[jj];
            /* 偏移两个字符取数字   */
            jj += 2;
            int curr_data = 0;
            while(input_str[jj]>='0' && input_str[jj]<='9')
            {
                /* 获取当前数据 */
                curr_data = 10*curr_data + input_str[jj] - '0';
                jj++;
            }
            mp[curr_char] = mp[curr_char] - curr_data;
        }
    }

    /*  输出                */
    char output[100];
    int output_idx = 0;

    /* 为了应付逗号输出     */
    for(int k=0; k<idx; k++)
    {
        if(mp[char_list[k]] != 0)
        {
            output[output_idx] = char_list[k];
            output_idx++;
        }
    }
    for(int k=0; k<output_idx; k++)
    {
        cout << output[k] << ":" << mp[output[k]];
        if(k < output_idx-1)
        {
            cout << ",";
        }
    }

    cout << endl;
    return 0;
}
