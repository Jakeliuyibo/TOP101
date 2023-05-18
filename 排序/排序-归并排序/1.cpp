#include <bits/stdc++.h>

using namespace std;

/* 合并 */
void merge(int array[], int tmpArray[], int left, int mid, int right)
{
    /* 标记左半区的起始位置     */
    int l_pos = left;
    /* 标记右半区的起始位置     */
    int r_pos = mid+1;
    /* 标记tmp的起始位置        */
    int t_pos = left;

    /* 对两个半区进行排序       */
    while(l_pos<=mid&&r_pos<=right)
    {
        if(array[l_pos]>=array[r_pos])
        {
            tmpArray[t_pos++] = array[r_pos++];
        }
        else
        {
            tmpArray[t_pos++] = array[l_pos++];
        }
    }

    /* 合并左半区剩余的数据     */
    while(l_pos <= mid)
    {
        tmpArray[t_pos++] = array[l_pos++];
    }
    /* 合并右半区剩余的数据     */
    while(r_pos <= right)
    {
        tmpArray[t_pos++] = array[r_pos++];
    }
    /* 将tmpArray拷贝到array   */
    for(int idx=left; idx<=right; idx++)
    {
        array[idx] = tmpArray[idx];
    }
}


/* 拆分合并排序 */
void merge_sort(int array[], int tmpArray[], int left, int right)
{
    if(left < right)
    {
        /* 递归拆分 */
        int mid = (left + right) / 2;
        merge_sort(array, tmpArray, left , mid);
        merge_sort(array, tmpArray, mid+1, right);

        /* 合并     */
        merge(array, tmpArray, left, mid, right);
    }
}


int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    /* 输入处理 */
    int array[] = {7,5,3,2,6,7,9,5,2,2,1,1,3,45,5};
    int n = sizeof(array) / sizeof(array[0]);

    int tmpArray[100];


    /* 归并排序 */
    merge_sort(array, tmpArray, 0, n-1);

    for(auto a:array)
    {
        cout << a << " ";
    }
    cout << endl;
    cout << n << endl;

    return 0;
}