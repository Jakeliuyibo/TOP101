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

bool isCompleteTree(TreeNode* root) 
{
    /* 层序遍历 */
    queue<TreeNode*> queue;
    bool flagReachNullNode = false;

    queue.push(root);
    while(!queue.empty())
    {

        TreeNode* curr = queue.front();
        queue.pop();
        if(!curr)
        {
            flagReachNullNode = true;
        }
        else
        {
            if(flagReachNullNode)
                return false;
            queue.push(curr->left);
            queue.push(curr->right);
        }
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