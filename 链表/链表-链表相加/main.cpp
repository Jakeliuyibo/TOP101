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
ListNode* reverse(ListNode* head)
{
    /* 边界处理 */
    if(!head || !head->next) return head;

    ListNode* pre  = nullptr;
    ListNode* curr = head;
    while(curr)
    {
        ListNode* tmp = curr->next;

        curr->next = pre;
        pre = curr;
        curr = tmp;
    }
    return pre;
}

ListNode* addInList(ListNode* head1, ListNode* head2) 
{
    ListNode* rev_head1 = reverse(head1);
    ListNode* rev_head2 = reverse(head2);

    ListNode* ret       = new ListNode(0);
    ListNode* pre       = ret;
    int sum = 0;
    while(rev_head1 || rev_head2 || sum>0)
    {
        int value1 = rev_head1?rev_head1->val:0;
        int value2 = rev_head2?rev_head2->val:0;

        sum += value1 + value2;

        ListNode* tmp = new ListNode(sum%10);
        pre->next = tmp;
        pre = tmp;

        /* 进位 */
        sum /= 10;

        /* 移动idx  */
        if(rev_head1) rev_head1 = rev_head1->next;
        if(rev_head2) rev_head2 = rev_head2->next;
    }

    return reverse(ret->next);
}


int main() 
{
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);

    ListNode * node1 = new ListNode(9);
    ListNode * node2 = new ListNode(3);
    ListNode * node3 = new ListNode(7);

    ListNode * node4 = new ListNode(6);
    ListNode * node5 = new ListNode(3);

    node1->next = node2;
    node2->next = node3; 
    node3->next = nullptr;

    node4->next = node5;
    node5->next = nullptr;

    ListNode * ret = addInList(node1, node4);
    cout << ret->val << endl;
    return 0;
}