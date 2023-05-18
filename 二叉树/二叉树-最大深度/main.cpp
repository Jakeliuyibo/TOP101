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

/**
 * 
 * @param root TreeNode类 
 * @return int整型
 */
int maxDepth(TreeNode* root) 
{
    if(!root) return 0;

    /* 遍历左子树       */
    int left_depth  = maxDepth(root->left);

    /* 遍历右子树       */
    int right_depth = maxDepth(root->right); 

    /* 比较左右子树深度     */
    int max_depth = left_depth > right_depth ? left_depth : right_depth;

    return max_depth+1;
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