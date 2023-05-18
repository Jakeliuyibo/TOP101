/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int MIN = -1001;
    int res = MIN;

    int dfs(TreeNode* root)
    {
        if(root == nullptr) return 0;

        int root_val  = root->val;
        int left_val  = max(0, dfs(root->left ));  
        int right_val = max(0, dfs(root->right));  

        res = max(res, root_val + left_val + right_val);

        /* 构建返回值   */
        return root_val + max(left_val, right_val);
    }

    int maxPathSum(TreeNode* root) 
    {
        dfs(root);

        return res;
    }
};