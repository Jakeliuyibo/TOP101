#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
// #include<bits/stdc++.h>

using namespace std;

void quickSort(vector<int>& arr, int L, int R)
{
    /* 终止条件 */
    if (L>=R) return;

    /* 初始条件 */
    int left = L;
    int right = R;
    int pivot = arr[left];

    /* 迭代 */
    while(left<right)
    {
        /* 比较右值和pivot  */
        while(left<right && arr[right]>=pivot)
            right--;
        if(left<right)                           // right比pivot小
            arr[left] = arr[right];
        /* 比较左值         */
        while(left<right && arr[left]<=pivot)
            left++;
        if(left<right)                          // left比pivot大
            arr[right] = arr[left];

        if(left>=right)                         // 填入pivot值
            arr[left] = pivot;
    }
    quickSort(arr, L, left-1);
    quickSort(arr, right+1, R);

}


vector<int> MySort(vector<int>& arr) 
{
    quickSort(arr, 0, arr.size()-1);
    return arr;
}


int main() 
{
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);

    TreeNode * node1 = new TreeNode(1);
    TreeNode * node2 = new TreeNode(2);
    TreeNode * node3 = new TreeNode(3);
    TreeNode * node4 = new TreeNode(4);
    TreeNode * node5 = new TreeNode(5);
    // TreeNode * node6 = new TreeNode(6);
    // TreeNode * node7 = new TreeNode(7);

    node3->left = node2;
    node3->right = node5;
    node2->left  = node1;
    node2->right = node4;

    auto ret = isValidBST(node3);
    cout << ret << endl;
    return 0;
}