#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
// #include<bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode * left;
    struct TreeNode * right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool flagBalanced = true;

int height(TreeNode* pRoot)
{
    if(!pRoot) return 0;

    int left_height  = height(pRoot->left);
    int right_height = height(pRoot->right);
    if(abs(left_height - right_height) > 1)
    {
        flagBalanced = false;
    }

    return max(left_height, right_height)+1;
}

bool IsBalanced_Solution(TreeNode* pRoot) 
{
    if(!pRoot) return true;
    else
    {
        /* 计算高度 */
        height(pRoot);

        return flagBalanced;
    }
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
    TreeNode * node6 = new TreeNode(6);
    // TreeNode * node7 = new TreeNode(7);

    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node4->left = node6;
    node3->right = node5;

    auto ret = IsBalanced_Solution(node1);
    cout << ret << endl;
    return 0;
}