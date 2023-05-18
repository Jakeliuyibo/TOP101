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

int lowestCommonAncestor(TreeNode* root, int p, int q) 
{
    if(p<root->val && q<root->val)       /* 如果p和q都小于根节点值，说明在root左节点 */
    {
        return lowestCommonAncestor(root->left, p, q);
    }
    else if(p>root->val && q>root->val)  /* 如果p和q都大于根节点值，说明在root右节点 */
    {
        return lowestCommonAncestor(root->right, p, q);
    }
    else
    {
        return root->val;
    }

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