#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int res_size = 0;

bool helper(vector<string>& result, vector<int>& opr_row, string opr, vector<string>& opr_str)
{
    if(opr_row[0] != 1 || opr[0] != 'i')
    {
        return false;
    }

    /* 操作 */
    for(int idx=0; idx<opr.size(); idx++)
    {
    
        // printf("pre idx=%d opr=%c opr_row=%d res_size=%d\n", idx, opr[idx], opr_row[idx], res_size);

        if(opr[idx] == 'i')         // 在row前插入一行
        {
            int row = opr_row[idx] - 1;
            result.insert(result.begin()+row, opr_str[idx]);
            res_size++;
        }
        else if(opr[idx] == 'a')    // 在row否插入一行
        {
            int row = opr_row[idx] - 1 + 1;
            result.insert(result.begin()+row, opr_str[idx]);
            res_size++;
        }
        else if(opr[idx] == 'r')    // 整体替换指定行
        {
            int row = opr_row[idx] - 1;
            result[row] = opr_str[idx];
        }
        else if(opr[idx] == 'd')    // 删除指定行
        {
            if((opr_row[idx]-1) >= res_size)
                return false;
            int row = opr_row[idx] - 1;
            result.erase(result.begin()+row, result.begin()+row + 1);
            res_size--;
        }
        else
        {
            return false;
        }

        
        // for(auto a:result)
        // {
        //     cout << a << endl;
        // }
        // printf("next idx=%d opr=%c opr_row=%d res_size=%d\n", idx, opr[idx], opr_row[idx], res_size);
    }

    return true;
}


int main(){

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    vector<int> opr_row;
    string opr;
    vector<string> opr_str;
    
    string input;
    getline(cin, input);
    // cout << input << endl;

    /* 解析字符串       */
    string input_str = "";
    for(int idx=0; idx<input.size(); idx++)
    {
        // cout << "curr char " << input[idx] << endl;
        /* 处理输入 */
        int input_row = input[idx] - '0';
        char input_opr = input[idx+2];
        opr_row.push_back(input_row);
        opr.push_back(input_opr);
        
        if(input_opr != 'd')
        {
            int jj;
            for(jj=idx+4; jj<input.size(); jj++)
            {
                if(input[jj] == '|' || input[jj] == '\0')
                {
                    opr_str.push_back(input_str);
                    input_str = "";
                    break;
                }
                else
                {
                    input_str += input[jj];
                }
            }
            idx = jj;
        }
        else
        {
            opr_str.push_back(input_str);
            idx = idx + 3;
        }
    }
    opr_str.push_back(input_str);

    vector<string> result{};   // 结果保存

    /* 处理字符串   */
    bool ret = helper(result, opr_row, opr, opr_str);
    if(ret == true)
    {
        cout << "result" << endl;
        for(auto res:result)
        {
            if(res.size() > 0)
                cout << res << endl;
        }
    }
    else
    {
        cout << "error" << endl;
    }

    return 0;
}