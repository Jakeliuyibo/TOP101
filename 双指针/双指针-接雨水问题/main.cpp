#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

/**
 * max water
 * @param arr int整型vector the array
 * @return long长整型
 */
long long maxWater(vector<int>& arr) 
{
    int len = arr.size();
    if(len==0) return 0;
    if(len==1) return 0;
    if(len==2) return 0;


    /* 遍历数组，求每个idx的左侧最值    */
    int left_relative_max = 0;
    vector<int> left_arr(len, 0);
    for(int idx=0; idx<len; idx++)
    {
        if(arr[idx]>left_relative_max)
        {
            left_relative_max = arr[idx];
        }
        left_arr[idx] = left_relative_max;
    }

    /* 遍历数组，求每个idx的右侧最值    */
    int right_relative_max = 0;
    vector<int> right_arr(len, 0);
    for(int idx=len-1; idx>=0; idx--)
    {
        if(arr[idx]>right_relative_max)
        {
            right_relative_max = arr[idx];
        }
        right_arr[idx] = right_relative_max;
    }

    long long int size = 0;
    for(int curr=1; curr<len-1; curr++)
    {
        int curr_height = arr[curr];

        /* 如果左右两侧存在比自己高的挡板，加上面积   */
        if(left_arr[curr-1]>curr_height && right_arr[curr+1]>curr_height)
        {
            // printf("curr idx=%d curr_h=%d left_h=%d right_h=%d add=%d\n",curr,curr_height,left_arr[curr-1],right_arr[curr+1],min(left_arr[curr-1], right_arr[curr+1]));
            size += (min(left_arr[curr-1], right_arr[curr+1])-curr_height);
        }
    }
    return size;
}

int main() 
{
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);

    vector<int> arr= {3,1,2,5,2,4};

    cout << maxWater(arr) << endl;

    return 0;
}