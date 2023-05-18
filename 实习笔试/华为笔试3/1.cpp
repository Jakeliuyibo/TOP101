#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);

    /* 输入处理 */
    int range_min, range_max;
    cin >> range_min >> range_max;
    int cnts;
    cin >> cnts;
    vector<vector<int>> opr(cnts, vector<int>(2, 0));
    for(int ii=0; ii<cnts; ii++)
    {
        cin >> opr[ii][0] >> opr[ii][1];
    } 

    /* 处理     */
    /* 建立资源池   */
    vector<int> ziyuan;                 // 可分配的资源
    vector<int> zhanyong;               // 占用的资源
    unordered_map<int, int> ziyuan_map; // 哈希表记录资源大致位置   
    unordered_map<int, int> zhanyong_map; // 哈希表记录资源大致位置   
    for(int ii=range_min; ii<=range_max; ii++)
    {
        ziyuan.push_back(ii);
        ziyuan_map[ii] = ii-range_min;
    }

    /* 处理opr操作  */
    for(auto op:opr)
    {
        if(op[0] == 1)                                                                  // 把资源->占用
        {
            int op_cnt = op[1];                          // 分配的资源个数
            for(int ii=0; ii<op_cnt; ii++)
            {
                zhanyong.push_back(ziyuan[ii]);             // 占用
                zhanyong_map[ziyuan[ii]] = zhanyong.size();
            }
            /* 删除资源 */
            ziyuan.erase(ziyuan.begin(), ziyuan.begin()+op_cnt);
        }
        else if(op[0] == 2)
        {
            int op_tar = op[1];     // 分配的内存名字
            /* 找到资源位置 */
            for(int ii=min(ziyuan_map[op_tar], (int)ziyuan.size()-1); ii>=0; ii--)
            {
                if(ziyuan[ii] == op_tar)
                {
                    zhanyong.push_back(op_tar); // 占用
                    zhanyong_map[op_tar] = zhanyong.size();

                    /* 删除资源 */
                    ziyuan.erase(ziyuan.begin() + ii, ziyuan.begin()+ii +1);
                    break;
                }
            }
        }
        else if(op[0] == 3)                                                                 // 把占用->资源
        {
            int op_tar = op[1];     // 释放的内存名字
            for(int ii=min(zhanyong_map[op_tar], (int)zhanyong.size()-1); ii>=0; ii--)
            {   
                if(zhanyong[ii] == op_tar)
                {
                    ziyuan.push_back(op_tar); // 占用
                    ziyuan_map[op_tar] = ziyuan.size();
                    /* 删除资源 */
                    zhanyong.erase(zhanyong.begin() + ii, zhanyong.begin()+ii +1);
                    zhanyong_map[op_tar] = zhanyong.size()-1;
                    break;
                }
            }
        }
    }


    /* 输出处理     */
    cout << "资源" << endl;
    for(auto op:ziyuan)
    {
        cout << op << " ";
    }
    cout << endl;
    cout << "占用" << endl;
    for(auto op:zhanyong)
    {
        cout << op << " ";
    }
    cout << endl;

    cout << ziyuan[0] << endl;
    return 0;
}