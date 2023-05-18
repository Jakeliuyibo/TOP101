#include <iostream>
using namespace std;

struct ListNode 
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverse(ListNode* head)
{
    if(!head || !head->next)    return head;
    
    ListNode* pre = nullptr;
    while(head)
    {
        ListNode* next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    return pre;
}

ListNode* reverseBetween(ListNode* head, int m, int n) 
{
    if(m>=n) return head;

    ListNode* slow = head;

    /* fast先走n-m步    */
    ListNode* fast = head;
    int step = n-m;
    while(fast && step--)
    {
        fast = fast->next;
    }

    /* 将slow移动到第m个节点，fast移动到第n个节点   */
    ListNode* pre_slow = nullptr;
    step = m-1;
    while(fast && step--)
    {
        pre_slow = slow;
        slow = slow->next;
        fast = fast->next;
    }

    /* pre_slow指向fast,反转slow到fast,slow指向fast->next*/
    ListNode* fast_next = fast->next;
    fast->next = nullptr;
    if(!pre_slow)
    {
        // 反转slow到fast
        head = reverse(slow);
        slow->next = fast_next;
    }
    else
    {
        // 反转slow到fast
        pre_slow->next = reverse(slow);
        slow->next = fast_next;

    }
    return head;
}


int main() 
{
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);

    // ListNode* node5 = new ListNode(5);
    // ListNode* node4 = new ListNode(4);
    // ListNode* node3 = new ListNode(3);
    ListNode* node2 = new ListNode(5);
    ListNode* node1 = new ListNode(3);
    node1->next = node2;
    node2->next = nullptr;
    // node3->next = node4;
    // node4->next = node5;
    // node5->next = nullptr;

    cout << reverseBetween(node1, 1, 2) << endl;

    return 0;
}
