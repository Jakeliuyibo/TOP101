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
    TreeNode* expandBinaryTree(TreeNode* root) 
    {
        if(root == nullptr) return nullptr;

        if(root->left)
        {
            TreeNode* add1  = new TreeNode(-1);
            TreeNode* left = root->left;            // 
            root->left = add1;
            add1->left  = expandBinaryTree(left);
        }

        if(root->right)
        {
            TreeNode* add2  = new TreeNode(-1);
            TreeNode* right = root->right;            // 
            root->right = add2;
            add2->right  = expandBinaryTree(right);
        }

        return root;
    }
};