#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasPathSum(TreeNode* root, int sum) 
{
    if(!root) return false;

    /* 遍历根节点   */
    if(!root->left && !root->right && sum-root->val==0)
    {
        return true;
    }

    /* 遍历左子树   */
    /* 遍历右子树   */
    return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
}


int main() 
{
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);

    ListNode * node1 = new ListNode(1);
    ListNode * node2 = new ListNode(2);
    ListNode * node3 = new ListNode(3);
    ListNode * node4 = new ListNode(4);
    ListNode * node5 = new ListNode(5);

    node1->next = node2;
    node2->next = node3; 
    node3->next = node4;
    node4->next = node5;
    node5->next = nullptr;

    ListNode * ret = reverseKGroup(node1, 2);
    cout << ret->val << endl;
    return 0;
}