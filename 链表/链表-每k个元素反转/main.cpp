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

/* 反转链表 */
ListNode* reverse(ListNode* head, ListNode* end)
{
    /* 边界处理 */
    if(!head || !head->next) return head;

    ListNode* pre  = nullptr;
    ListNode* curr = head;
    while(curr!=end)
    {
        ListNode* tmp = curr->next;

        curr->next = pre;
        pre = curr;
        curr = tmp;
    }
    return pre;
}

ListNode* reverseKGroup(ListNode* head, int k) 
{
    if(!head) return head;
    if(k==1)  return head;

    /* 每K步进行反转    */
    auto curr = head;
    for(int idx=0; idx<k; idx++)
    {
        if(!curr)
        {
            return head;
        }
        curr = curr->next;
    }

    auto ret = reverse(head, curr);
    head->next = reverseKGroup(curr, k);

    return ret;
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