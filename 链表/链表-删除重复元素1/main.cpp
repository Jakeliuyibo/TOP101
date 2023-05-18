#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

struct ListNode 
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* deleteDuplicates(ListNode* head) 
{
    if(!head) return nullptr;
    else
    {
        ListNode* pcurr  = head;

        while(pcurr)
        {
            if(pcurr->next && pcurr->val==pcurr->next->val)     // 当前节点值与下一节点值相等
            {
                pcurr->next = pcurr->next->next;
            }
            else
            {
                pcurr = pcurr->next;
            }
        }

        return head;
    }
}


int main() 
{
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);

    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(1);
    ListNode* node3 = new ListNode(1);
    ListNode* node4 = new ListNode(2);
    ListNode* node5 = new ListNode(2);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = nullptr;

    cout << deleteDuplicates(node1) << endl;

}
