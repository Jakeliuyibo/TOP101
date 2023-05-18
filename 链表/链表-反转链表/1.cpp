#include <bits/stdc++.h>


using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverse(ListNode *head)
{
    if(head == nullptr) return nullptr;

    ListNode *pre = nullptr;
    while(head)
    {
        ListNode *tmp = head->next;
        head->next = pre;
        pre = head;
        head = tmp;
    }
    return pre;
}

int main()
{
    /* 初始化       */
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    n1->next = n2;
    n2->next = n3;
    n3->next = nullptr;

    /* 反转链表     */
    ListNode *n = reverse(n1);
    while(n)
    {
        cout << n->val <<endl;
        n = n->next;
    }

    return 0;
}