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


ListNode* removeNthFromEnd(ListNode* head, int n) 
{
    /* 创建虚表头   */
    ListNode * ret  = new ListNode(0);
    ret->next = head;
    ListNode * pre  = ret;
    ListNode * fast = head;
    ListNode * slow = head;

    /* 快指针先行n步    */
    while(n--)
    {
        fast = fast->next;
    }

    /* 同时移动slow和fast节点   */
    while(fast)
    {
        pre  = slow;
        slow = slow->next;
        fast = fast->next;
    }

    /* 处理slow节点所在位置 */
    pre->next = slow->next;

    return ret->next;
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

    ListNode * ret = removeNthFromEnd(node1, 1);
    cout << ret->val << endl;
    return 0;
}