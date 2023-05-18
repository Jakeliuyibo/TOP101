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
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 * 
 * @param pRoot TreeNode类 
 * @return TreeNode类
 */
TreeNode* Mirror(TreeNode* pRoot) 
{
    if(!pRoot) return pRoot;

    if(pRoot->left || pRoot->right)
    {
        /* 交换左右子树 */
        TreeNode* tmp = Mirror(pRoot->left);
        pRoot->left   = Mirror(pRoot->right);
        pRoot->right  = tmp;
    }

    return pRoot;
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