#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;


// /**
//  * 反转字符串
//  * @param str string字符串 
//  * @return string字符串
//  */

string solve(string str) 
{
    string ret = "";

    // for(int ii=0; ii<str.size(); ii++)
    // {
    //     ret += str[str.size()-1-ii];
    // }


    for(int ii=0; ii<str.size(); ii++)
    {
        ret[ii] = str[str.size()-1-ii];
    }
    
    return ret;
}


int main() 
{
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);

    string s;
    cin >> s;
    cout << solve(s) << endl;

    return 0;
}