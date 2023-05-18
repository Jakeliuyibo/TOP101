#include <bits/stdc++.h>

using namespace std;

int main() 
{
    /* 输入处理 */
    string str;
    while(getline(cin, str))
    {
        bool flag_cond1 = true;
        bool flag_cond2 = true;
        bool flag_cond3 = true;

        /* cond 1 */
        if(str.size() <= 8)
            flag_cond1 = false;

        /* cond 2 */
        vector<int> count(4, 0);
        for(int idx=0; idx<str.size(); idx++)
        {
            if(str[idx]>='a'&&str[idx]<='z')      count[0]=1;
            else if(str[idx]>='A'&&str[idx]<='Z') count[1]=1;
            else if(str[idx]>='0'&&str[idx]<='9') count[2]=1;
            else                                  count[3]=1;
        }
        if((count[0]+count[1]+count[2]+count[3])<3)
            flag_cond2 = false;

        /* cond 3 */
        /* 双指针   */
        for(int left=0; left<str.size()&&flag_cond3; left++)
        {
            for(int right=left+3; right<str.size()&&flag_cond3; right++)
            {
                if(str[left] == str[right])
                {
                    /* 截取3个字符  */
                    if(str.substr(left, 3) == str.substr(right, 3))
                    {
                        flag_cond3 = false;
                        break;
                    }
                }
            }
        }


        /* 输出处理 */
        if(flag_cond1 && flag_cond2 && flag_cond3)
            cout << "OK" << endl;
        else
            cout << "NG" << endl;
    }


    return 0;
}
