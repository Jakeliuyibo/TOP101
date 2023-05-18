#include <iostream>
using namespace std;

vector<string>  result;
string          path;

void helper(string str, vector<int >& history)
{
    /* 终止条件 */
    if(path.size() == str.size())
    {
        result.push_back(path);
        return;
    }

    /* 循环     */
    unordered_map<char, int> mp;             // 记录本次的使用记录 
    for(int idx=0; idx<str.size(); idx++)
    {
        if(history[idx]==0 && mp[str[idx]]==0)
        {
            /* 记录本层历史 */
            mp[str[idx]]++;

            /* 递归 */
            path.push_back(str[idx]);
            history[idx] = 1;
            helper(str, history);

            /* 回溯 */
            path.pop_back();
            history[idx] = 0;
        }

    }
}

vector<string> Permutation(string str) 
{
    vector<int > history(str.size(), 0);
    helper(str, history);
    return result;
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
