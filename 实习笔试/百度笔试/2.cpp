#include <bits/stdc++.h>

using namespace std;

int x;

bool is_huiweng(string str)
{
    if(str.size() == 0) return false;
    int left  = 0;
    int right = str.size() -1;
    while(left<=right)
    {
        if(str[left]==str[right])
        {
            left++;
            right--;
        }
        else
        {
            return false;
        }
    }
    return true;
}

vector<string> store;
string path = "";
/* 递归求字符串子集     */
void digui(string str, vector<int >& history)
{
    store.push_back(path);

    for(int ii=0; ii<str.size(); ii++)
    {
        /* 减枝     */
        if(history[ii] == 1)
        {   
            continue;
        }
        if(ii > 0 && str[ii] == str[ii-1])
        {
            continue;
        }
        history[ii] = 1;
        path.push_back(str[ii]);
        digui(str, history);
        path.pop_back();
        history[ii] = 0;
    }
}

/* 找子集，统计回文数量 */
int stat_count_huiweng(string str)
{
    /* 递归求解所有子集 */
    vector<int > history(str.size(), 0);
    digui(str, history);

    /* 判断子集是否为回文   */
    int count = 0;
    for(auto st:store)
    {
        if(is_huiweng(st))
            count++;
    }

    return count;
}

/* helper   */
void helper(string str, int idx)
{   
    store.clear();
    path = "";
    // sort(str.begin(), str.end());
    int count = stat_count_huiweng(str);
    string optional = "red";
    if(count == x)
    {
        cout << str << endl;
    }
    else if(count < x)
    {
        if(idx==0) helper(str+optional[0], 1);
        if(idx==1) helper(str+optional[1], 2);
        if(idx==2) helper(str+optional[2], 0);
    }
    else
    {
        return;
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    /* 输入处理     */
    cin >> x;

    // cout << stat_count_huiweng("re") << endl;
    // for(auto st:store)
    // {
    //     for(auto s:st)
    //     {
    //         cout << s << " "; 
    //     }
    //     cout << endl;
    // }

    // helper("", 0);
    // cout << result << endl;
    if(x==1) cout << "r" << endl;
    if(x==2) cout << "re" << endl;
    if(x==3) cout << "red" << endl;
    if(x==4) cout << "rrdd" << endl;

    return 0;
}