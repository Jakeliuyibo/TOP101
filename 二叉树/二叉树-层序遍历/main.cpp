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

void order(vector<vector<int>> &vv, int depth, TreeNode* root)
{
    if(!root) return;

    if(depth >= vv.size())
    {
        vv.push_back(vector<int> {});
    }

    /* 遍历根节点   */
    vv[depth].push_back(root->val);
    /* 遍历左子树   */
    order(vv, depth+1, root->left);
    /* 遍历右子树   */
    order(vv, depth+1, root->right);
}

vector<vector<int> > levelOrder(TreeNode* root) 
{
    vector<vector<int>> vv;
    int depth = 0;

    order(vv, depth, root);

    return vv;
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


