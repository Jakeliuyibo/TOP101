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

void postorder(vector<int>&ret, TreeNode* root)
{
    if(!root) return;

    /* 遍历左子树   */
    postorder(ret, root->left);
    /* 遍历右子树   */
    postorder(ret, root->right);
    /* 遍历根节点   */
    ret.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode* root) 
{
    vector<int> ret;
    postorder(ret, root);
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