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

bool isPail(ListNode* head) 
{
    /* 输入处理 */
    if(!head) return false;

    vector<int> vec1;
    while (head)
    {
        vec1.push_back(head->val);
        head = head->next;
    }

    vector<int> vec2 = vec1;
    reverse(vec2.begin(), vec2.end());
    if(vec1 == vec2) return true;
    else return false;

}


int main() 
{
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);

    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = nullptr;

    cout << isPail(node1) << endl;

}
