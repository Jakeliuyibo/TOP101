#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int* dfs(TreeNode* root)
{
    /* dp   0:不盗 1:盗     */
    int* dp = new int[2];
    memset(dp, 0, sizeof(dp));

    if(root == nullptr) return dp;

    int* dp_left  = dfs(root->left);
    int* dp_right = dfs(root->right);

    /* 计算当前节点的dp       */
    dp[0]   = max(dp_left[0], dp_left[1]) + max(dp_right[0], dp_right[1]);
    dp[1]   = root->val + dp_left[0] + dp_right[0];

    return dp;
}

int rob(TreeNode* root) 
{
    int *dp = dfs(root);

    return max(dp[0], dp[1]);
}

int main()
{   
    cout << "hello" << endl;
    TreeNode* r1 = new TreeNode(1);
    TreeNode* r2 = new TreeNode(2);
    TreeNode* r3 = new TreeNode(3);
    r1->left = r2;
    r1->right = r3;

    cout << rob(r1) << endl;

    return 0;
}