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
        /* 创建虚表头 */
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* pcurr  = dummy;
        while(pcurr->next && pcurr->next->next)
        {   
            if(pcurr->next->val == pcurr->next->next->val)
            {
                int tmp = pcurr->next->val;
                while(pcurr->next && pcurr->next->val == tmp)
                {
                    pcurr->next = pcurr->next->next;
                }
            }
            else
            {
                pcurr = pcurr->next;
            }
        }

        return dummy->next;
    }
}


int main() 
{
    freopen("in.txt", "rt", stdin);
    // freopen("out.txt", "wt", stdout);

    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(2);
    ListNode* node4 = new ListNode(3);
    ListNode* node5 = new ListNode(3);
    ListNode* node6 = new ListNode(4);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = nullptr;

    cout << "end" << endl;
    cout << deleteDuplicates(node1)->val << deleteDuplicates(node1)->next->val<< endl;

}
