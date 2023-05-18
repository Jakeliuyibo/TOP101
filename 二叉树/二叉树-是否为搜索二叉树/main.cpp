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

void midorder(TreeNode* root, vector<int>& storage)
{
    if(!root) return;

    /* 遍历左子树   */
    midorder(root->left, storage);
    /* 遍历根节点   */
    storage.push_back(root->val);
    /* 遍历左子树   */
    midorder(root->right, storage);
}

bool isValidBST(TreeNode* root) 
{
    vector<int> storage;

    /* 中序遍历 */
    midorder(root, storage);

    /* 判断数组是否递增 */
    for(int idx=1; idx<storage.size(); idx++)
    {
        if(storage[idx-1] > storage[idx])
            return false;
    }
    return true;
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