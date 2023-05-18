#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

bool helper(vector<int>& arr, int n)
{
    bool flag_rule1 = true;
    bool flag_rule2 = true;
    bool flag_rule3 = true;
    
    /* 校验规则1    */
    int first = arr[0];
    int flag_next = first<10?1:0;

    for(int idx=1; idx<n; idx++)
    {
        /* 校验arr[idx]是否满足上一位要求   */
        if(flag_next == 0)
        {
            if(arr[idx]<10)
            {
                flag_next = 1;
            }
            else
            {
                flag_rule1 = false;
                break;
            }
        }
        else
        {
            if(arr[idx]>=10)
            {
                flag_next = 0;
            }
            else
            {
                flag_rule1 = false;
                break;
            }
        }
    }
    
    /* 校验规则2    */
    if(arr[0]>=10 && arr[n-1]>=10)
    {
        /* 检验[1,n-2]是否为一位数    */
        for(int idx=1; idx<=(n-2); idx++)
        {
            if(arr[idx]>=10)
            {
                flag_rule2 = false;
                break;
            }
        }
    }
    else
    {
        flag_rule2 = false;
    }
    
    /* 校验规则3    */
    if(arr[0]<10 && arr[n-1]<10)
    {
        /* 检验[1,n-2]是否为两位数    */
        for(int idx=1; idx<=(n-2); idx++)
        {
            if(arr[idx]<10)
            {
                flag_rule3 = false;
                break;
            }
        }
    }
    else
    {
        flag_rule3 = false;
    }
    
    cout << flag_rule1 << flag_rule2 << flag_rule3 << endl;
    return flag_rule1 || flag_rule2 || flag_rule3;
}


int main(){

    vector<int> array = {3,10,3};
    
    bool ret = helper(array, array.size());

    cout << ret << endl;
    return 0;
}