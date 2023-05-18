#include <iostream>
using namespace std;

struct ListNode 
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * @param pHead ListNode类 
 * @param k int整型 
 * @return ListNode类
 */
ListNode* FindKthToTail(ListNode* pHead, int k) 
{
    if(pHead == nullptr) return nullptr;

    /* 计算链表长度 */
    int len_listnode = 0;
    ListNode* pTemp = pHead;
    while(pTemp)
    {
        len_listnode++;
        pTemp = pTemp->next;
    }

    if (len_listnode < k) return nullptr;
    else
    {
        int offset = len_listnode - k;
        ListNode* pTemp = pHead;
        while(offset > 0)
        {
            pTemp = pTemp->next;
            offset--;
        }
        return pTemp;
    }
}


int main() 
{
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);

    ListNode* node5 = new ListNode(5);
    ListNode* node4 = new ListNode(4);
    ListNode* node3 = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node1 = new ListNode(1);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = nullptr;

    int k;
    cin >> k;

    cout << FindKthToTail(node1, k) << endl;
}
