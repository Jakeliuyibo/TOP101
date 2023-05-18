#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;



/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
#include <unordered_map>
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) 
    {
        // unordered_map<int, int> mp;
        // while(pHead)
        // {
        //     if(mp[pHead->val]>0)
        //     {
        //         return pHead;
        //     }
        //     else
        //     {
        //         mp[pHead->val]++; 
        //         pHead = pHead->next;
        //     }
        // }

        // return nullptr;

        if(!pHead || !pHead->next) return nullptr;

        ListNode* slow = pHead;
        ListNode* fast = pHead;

        /*  检测是否存在环路  */
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                break;
            }
        }
        if(!fast || !fast->next)return nullptr;

        /* 重新寻找 */
        ListNode* p1   = pHead;
        ListNode* p2   = slow;
        while(p1 != p2)
        {
            p1 = p1->next;
            p2 = p2->next;
        }

        return p1;
    }
};


int main() 
{
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);

    int a[] = {1,2,3};


    for (auto i:a)
    {
        cout << i << endl;
    }



    return 0;
}