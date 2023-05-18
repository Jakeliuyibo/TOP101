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

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) 
{
    if(!t1 && !t2) return t1;
    if(!t1)        return t2;
    if(!t2)        return t1;

    /* 计算根节点   */
    t1->val = t1->val + t2->val;

    /* 计算左子树   */
    t1->left = mergeTrees(t1->left, t2->left);

    /* 计算右子树   */
    t1->right = mergeTrees(t1->right, t2->right);

    return t1;
}

int main() 
{
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);

    vector<vector<int>> vv;

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    vv.push_back(v);
    vv.push_back(vector<int> {});
    vv[1].push_back(213);


    for (int ii=0; ii<vv.size(); ii++)
    {
        for(int jj=0; jj<vv[ii].size(); jj++)
            cout << vv[ii][jj] << endl;
    }
    

    return 0;
}