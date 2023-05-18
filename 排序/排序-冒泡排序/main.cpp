#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
// #include<bits/stdc++.h>

using namespace std;

void bubbleSort(vector<int>& arr)
{
    /* 外循环为排序次数，由于每一轮中最大数会沉底，因此只需排序size-1轮 */
    for(int ii=0; ii<arr.size()-1; ii++)
    {
        for(int jj=0; jj<arr.size()-1-ii; jj++)
        {
            if(arr[jj]>arr[jj+1])
                swap(arr[jj], arr[jj+1]);
        }
    }
}


vector<int> MySort(vector<int>& arr) 
{
    // quickSort(arr, 0, arr.size()-1);
    bubbleSort(arr);
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