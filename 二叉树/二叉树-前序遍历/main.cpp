#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/* 递归前序遍历二叉树   */
void preorder(vector<int>& ret, TreeNode* root)
{
    /* 遍历根节点   */
    if(!root)
    {
        return;
    }
    
    /* 遍历根节点   */
    ret.push_back(root->val);

    /* 遍历左子树   */
    preorder(ret, root->left);

    /* 遍历右子数   */
    preorder(ret, root->right);
}

vector<int> preorderTraversal(TreeNode* root) 
{
    vector<int> ret;
    preorder(ret, root);
    return ret;
}


int main() 
{
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);

    vector<int> a = {1,2,3};
    vector<int> b = { 2, 3, 4 };


    for (auto i:a)
    {
        cout << i << endl;
    }
    
    a = a + b;





    return 0;
}