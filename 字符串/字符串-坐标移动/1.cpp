#include <bits/stdc++.h>

using namespace std;

int main() 
{
    vector<char> opr_sym;
    vector<int>  opr_num;
    /* 输入处理 */
    string str;
    while(getline(cin, str, ';'))
    {
        bool flag = true;
        if(str.size() > 0)
        {
            char sym = str[0];
            if(sym == 'A' || sym == 'D' || sym == 'W' || sym == 'S')
            {
                int data = 0;
                for(int idx=1; idx<str.size(); idx++)
                {
                    if(str[idx]>='0'&&str[idx]<='9')
                    {
                        data = 10*data + str[idx] - '0';
                    }
                    else
                    {
                        flag = false;
                        break;
                    }
                }

                if(flag)
                {
                    opr_sym.push_back(sym);
                    opr_num.push_back(data);
                }
            }
        }
    }

    /* 移动坐标 */
    int x = 0;
    int y = 0;
    for(int idx=0; idx<opr_num.size(); idx++)
    {
        if(opr_sym[idx] == 'S') y -= opr_num[idx];
        if(opr_sym[idx] == 'W') y += opr_num[idx];
        if(opr_sym[idx] == 'A') x -= opr_num[idx];
        if(opr_sym[idx] == 'D') x += opr_num[idx];
    }

    /* 输出处理 */
    cout << x << "," << y << endl;

    return 0;
}
