#include <bits/stdc++.h>

using namespace std;

struct DListNode
{
    int key, val;
    DListNode *prev, *next;
    DListNode(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr)  {}
};

class LRUCache 
{
private:
    DListNode *pleft;                       // 左端点
    DListNode *pright;                      // 右端点
    unordered_map<int, DListNode*> mp;      // 哈希表，存储节点，o(1)查找
    int max_size;                           // 最大容量
    int size;                               // 当前   
public:
    LRUCache(int capacity) 
    {
        max_size        = capacity;
        size            = 0;
        pleft           = new DListNode(-1, -1);
        pright          = new DListNode(-1, -1);

        /* 构建left->right连接  */
        pleft->next     = pright;
        pright->prev    = pleft;
    }
    
    int get(int key) 
    {
        if(mp.count(key)>0)
        {
            /* 获取节点 */
            DListNode* cur = mp[key];
            int val = cur->val;
            remove(cur);                        // 移除当前节点
            insert(key, val);                   // 将当前节点插入到最右侧
            return val;
        }
        else
            return -1;
    }
    
    void put(int key, int value) 
    {
        if(mp.count(key)>0)
        {
            /* 获取节点 */
            DListNode* cur = mp[key];
            remove(cur);                        // 移除当前节点
        }
        else
        {
            /* 插入新节点   */
            if(size >= max_size)
            {
                /* 删除最久未用的元素   */
                remove(pleft->next);
            }
        }

        /* 插入元素     */
        insert(key, value);                 // 将当前节点插入到最右侧
    }

    void remove(DListNode *node)
    {
        auto pre = node->prev;
        auto nxt = node->next;

        /* 建立prev node 和next node的连接  */
        pre->next = nxt;
        nxt->prev = pre;

        /* TODO 删除node                    */
        size--;
        mp.erase(node->key);
    }

    void insert(int key, int val)
    {
        auto pre = pright->prev;
        auto node = new DListNode(key, val);
        auto nxt = pright;
        /* 建立old到新节点的连接      */
        pre->next  = node;
        node->prev = pre;
        /* 建立新节点到right的连接          */
        node->next = nxt;
        nxt->prev  = node;
        /* TODO 添加node                    */
        size++;
        mp[key] = node;
    }

    void print_dlist(void)
    {
        auto head = pleft;
        while(head)
        {
            printf("(%d,%d)->", head->key, head->val);
            head = head->next;
        }
        printf(" 个数%d\n", size);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    // freopen("in.txt", "r", stdin);
    int ret = 0;

    LRUCache lRUCache(2);
    lRUCache.put(1, 1); // 缓存是 {1=1}
    lRUCache.print_dlist();
    lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
    lRUCache.print_dlist();
    ret = lRUCache.get(1);    // 返回 1
    lRUCache.print_dlist();
    cout << ret << endl;
    lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    lRUCache.print_dlist();
    ret = lRUCache.get(2);    // 返回 -1 (未找到)
    lRUCache.print_dlist();
    cout << ret << endl;
    lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    lRUCache.print_dlist();
    ret = lRUCache.get(1);    // 返回 -1 (未找到)
    cout << ret << endl;
    ret = lRUCache.get(3);    // 返回 3
    lRUCache.print_dlist();
    cout << ret << endl;
    ret = lRUCache.get(4);    // 返回 4
    lRUCache.print_dlist();
    cout << ret << endl;

    return 0;
}