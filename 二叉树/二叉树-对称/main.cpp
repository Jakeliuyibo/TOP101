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

bool cmp(TreeNode* p1, TreeNode* p2)
{
    if(!p1 && !p2) return true;
    if(!p1)        return false;
    if(!p2)        return false;

    if(p1->val == p2->val)
    {
        return cmp(p1->left, p2->right) && cmp(p1->right, p2->left);
    }
    else
    {
        return false;
    }
}

bool isSymmetrical(TreeNode* pRoot) 
{
    if(!pRoot) return true;

    return cmp(pRoot->left, pRoot->right);
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