#include <iostream>
using namespace std;

struct ListNode 
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) 
{
    /* 输入判断 */
    if (!pHead1) return nullptr;
    if (!pHead2) return nullptr;
    if (pHead1 == pHead2)   return pHead1;

    /* 双指针,    */
    ListNode* ta = pHead1;
    ListNode* tb = pHead2;
    while(ta != tb)
    {
        ta = ta? ta->next : pHead2;
        tb = tb? tb->next : pHead1;
    }

    return ta;
}


int main() 
{
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);

    ListNode* node7 = new ListNode(7);
    ListNode* node6 = new ListNode(6);
    ListNode* node5 = new ListNode(5);
    ListNode* node4 = new ListNode(4);
    ListNode* node3 = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node1 = new ListNode(1);
    node1->next = node2;
    node2->next = node3;
    node3->next = node6;

    node4->next = node5;
    node5->next = node6;

    node6->next = node7;

    cout << FindFirstCommonNode(node1, node4) << endl;
}
