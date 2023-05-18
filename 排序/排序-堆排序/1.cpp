#include <bits/stdc++.h>

using namespace std;

void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}


/* 维护堆性质：根节点值大于左右节点 */
void heapifer(int array[], int n, int idx)
{
    /* 父节点   */
    int root_pos = idx;
    /* 左子节点 */
    int lson_pos = 2*root_pos + 1;
    /* 右子节点 */
    int rson_pos = 2*root_pos + 2;

    /* 比较左节点和根节点   */
    if(lson_pos<n && array[lson_pos]>array[root_pos])
        root_pos = lson_pos;
    /* 比较右节点和根节点   */
    if(rson_pos<n && array[rson_pos]>array[root_pos])
        root_pos = rson_pos;

    if(root_pos != idx)
    {
        swap(&array[idx], &array[root_pos]);
        /* 维护子树   */
        heapifer(array, n ,root_pos);
    }
}


void head_sort(int array[], int n)
{
    /* 建堆 */
    for(int idx=(n-1)/2; idx>=0; idx--)
    {
        /* 维护堆性质       */
        heapifer(array, n, idx);
    }

    /* 排序 */
    for(int idx=n-1; idx>=0; idx--)
    {
        /* 将根节点放到末尾      */
        swap(&array[idx], &array[0]);

        /* 维护array[0]的堆性质 */
        heapifer(array, idx, 0);
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    /* 输入处理 */
    int array[] = {1,2,4,8,7,9,3,14,10,16,3,2};
    int n = sizeof(array) / sizeof(array[0]);
    for(auto a:array)
    {
        cout << a << " ";
    }
    cout << endl;
    
    /* 归并排序 */
    head_sort(array, n);

    for(auto a:array)
    {
        cout << a << " ";
    }
    cout << endl;
    cout << n << endl;

    return 0;
}