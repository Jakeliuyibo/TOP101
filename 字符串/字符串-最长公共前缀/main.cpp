#include <iostream>
#include <iterator>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cstddef>

using namespace std;

bool mcmp(string &a, string & b)
{
    return a.size() < b.size();
}

/**
 * 
 * @param strs string字符串vector 
 * @return string字符串
 */
string longestCommonPrefix(vector<string>& strs) 
{
    /* 输入处理 */
    if(strs.size() == 0) return "";
    if(strs.size() == 1) return strs[0];

    /* 字符串处理   */
    sort(strs.begin(), strs.end(), mcmp);

    string cmp_begin = strs.front();
    string cmp_end   = strs.back();
    for(int idx=0; idx<cmp_begin.size(); idx++)
    {
        if(cmp_begin[idx] != cmp_end[idx])
        {
            return cmp_begin.substr(0, idx);
        }
    }

    return cmp_begin;   
}


int main() 
{
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);

    vector<string> strs = {"abca","abc","abca","abc","abcc"};
    cout << longestCommonPrefix(strs)<< endl;

}