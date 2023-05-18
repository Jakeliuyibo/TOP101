#include <bits/stdc++.h>

using namespace std;

/* 找逗号位置   */
int find_douhao_pos(string str)
{
    int n = str.size();
    for(int ii=0; ii<n; ii++)
    {
        if(str[ii] == '.')
            return ii;
    }
    return -1;
}



int main()
{
    freopen("in.txt", "r", stdin);

    /**输入处理 */
    int len;
    string str;
    cin >> len;
    cin >> str;
    // TODO 修改了len
    len = str.size();

    /* 分割字符串   */
    string s1 = "";
    string s2 = "";
    /* 找到+号  */
    bool flag = true;
    for(int ii=0; ii<len; ii++)
    {   
        if(str[ii] == '+')
        {
            flag = false;
            continue;
        }
        if(flag)
            s1 += str[ii];
        else
            s2 += str[ii];
    }

    /* 补0对齐  */
    int s1_douhao_pos = find_douhao_pos(s1);
    int s2_douhao_pos = find_douhao_pos(s2);
    if(s1_douhao_pos == -1)
    {
        s1 += '.';
        s1 += '0';
        s1_douhao_pos = find_douhao_pos(s1);
    }
    if(s2_douhao_pos == -1)
    {
        s2 += '.';
        s2 += '0';
        s2_douhao_pos = find_douhao_pos(s2);
    }
    // 补前半部分
    int diff = abs(s1_douhao_pos-s2_douhao_pos);
    if(s1_douhao_pos<s2_douhao_pos)
    {
        for(int ii=0; ii<diff; ii++)
            s1 = '0' + s1;
    }
    else
    {
        for(int ii=0; ii<diff; ii++)
            s2 = '0' + s2;
    }
    // 补后半部分
    diff = abs((int)s1.size()-(int)s2.size());
    if(s1.size()<s2.size())
    {
        for(int ii=0; ii<diff; ii++)
            s1 = s1 + '0';
    }
    else
    {
        for(int ii=0; ii<diff; ii++)
            s2 = s2 + '0';
    }
    cout << "反转前" << endl;
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;

    /* 相加字符串   */
    /* 反转 */
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    cout << "反转后" << endl;
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    string res = "";                    // 输出结果
    int add_sum = 0;                    // 累加和
    int jinwei = 0;                     //  进位
    int num_deal = s1.size();
    for(int ii=0; ii<num_deal; ii++)    // 位处理   
    {
        add_sum = jinwei;
        if(s1[ii]=='.' && s2[ii]=='.')
        {
            res += '.';
            continue;
        }
        else if(s1[ii]>='0' && s1[ii]<='9'&& s2[ii]>='0' && s2[ii]<='9' )
            add_sum += s1[ii] - '0' + s2[ii] - '0';
        else if(s1[ii]=='!' && s2[ii]=='!')
            add_sum += 0;
        else if(s1[ii]=='@' && s2[ii]=='@')
            add_sum += 7;
        else if(s1[ii]=='#' && s2[ii]=='#')
            add_sum += 5;
        else if(   (s1[ii]=='!' && s2[ii]=='@')
                || (s1[ii]=='@' && s2[ii]=='!'))
            add_sum += 13;
        else if(   (s1[ii]=='!' && s2[ii]=='#')
                || (s1[ii]=='#' && s2[ii]=='!'))
            add_sum += 4;
        else if(   (s1[ii]=='#' && s2[ii]=='@')
                || (s1[ii]=='@' && s2[ii]=='#'))
            add_sum += 20;
        else
        {
            cout << "error" << s1[ii] << " " << s2[ii] << endl;
        }

        /* 添加结果，进位   */
        res += add_sum%10 + '0';
        jinwei = add_sum/10;
    }
    /* 处理末尾的进位   */
    if(jinwei > 0)
        res += jinwei + '0';

    cout << "输出" << endl;
    cout << "Res "  << res << endl;

    /* 输出处理 */
    cout << "len: " << len << endl;
    cout << "str: " << str << endl;
    reverse(res.begin(), res.end());
    cout << "Res "  << res << endl;

    /* 处理输出格式 */
    int res_len = res.size();
    int left = 0;
    int right = res_len-1;
    while(left<res_len && res[left]=='0')
    {
        left++;
    }
    while(right>=0 && res[right]=='0')
    {
        right--;
    }
    if(res[right]=='.')
        right--;

    string result;
    for(int ii=left; ii<=right; ii++)
    {
        result += res[ii];
    }
    cout << "result "  << result << endl;

    return 0;
}