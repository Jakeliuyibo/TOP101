#include <bits/stdc++.h>
using namespace std;


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct node
{
    int val;
    int lists_id;
    node(int a, int b) : val(a), lists_id(b) {}
};
bool operator<(node a, node b)
{
    if(a.val > b.val)
    {
        return true;
    }
    else
    {
        return false;
    }
}

class Solution 
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        priority_queue<node> pq;    // 优先队列

        int n = lists.size();       // 链表个数 
        for(int ii=0; ii<n; ii++)
        {
            ListNode* head = lists[ii];
            while(head)
            {
                pq.push(node(head->val, ii));
                head = head->next;
            }

        }

        /* 构建输出链表     */
        ListNode* pre = new ListNode();
        ListNode* head = pre;
        while(!pq.empty())
        {
            struct node curr_node = pq.top();
            pq.pop();

            ListNode* curr = new ListNode(curr_node.val);
            head->next = curr;
            head = head->next;

            // cout << "**" << curr_node.val << " * " << curr_node.lists_id << endl;
        }

        return pre->next;
    }




};