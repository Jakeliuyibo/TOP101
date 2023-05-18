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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> res;

        if(!root)   return res;

        int layer = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            res.push_back({});

            /* 取出当前层所有数据   */
            int step = q.size();
            for(int ii=0; ii<step; ii++)
            {
                TreeNode* cur = q.front();
                q.pop();
                /* 记录当前层数据   */
                res[layer].push_back(cur->val);

                if(cur->left)   q.push(cur->left);
                if(cur->right)  q.push(cur->right);
            }

            layer++;
        }

        /* 对layer%2行反序*/
        for(int ii=0; ii<res.size(); ii++)
        {
            if(ii%2!=0)
                reverse(res[ii].begin(), res[ii].end());
        }

        return res;
    }
};