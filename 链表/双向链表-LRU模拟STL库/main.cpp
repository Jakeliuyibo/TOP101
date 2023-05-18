#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int > PAIR;

class LRUCache {
private:
    int max_size;
    list<PAIR> mlist;
    unordered_map<int, list<PAIR>::iterator> mp;
public:
    LRUCache(int capacity) 
    {
        max_size = capacity;
    }
    
    /* 获取指定key的节点，并删除他当前位置，在头节点插入    */
    int get(int key) 
    {
        if(mp.count(key)>0)
        {
            auto cur = mp[key];
            int cur_val = cur->second;
            /* 删除cur元素  */
            mlist.erase(cur);
            mp.erase(key);
            /* 在头节点插入 */
            mlist.push_front({key, cur_val});
            mp[key] = mlist.begin();
            return cur_val;
        }
        else
        {
            return -1;
        }
    }
    
    void put(int key, int value) 
    {
        PAIR node = {key, value};

        if(mp.count(key)>0)
        {
            auto cur = mp[key];
            /* 删除cur元素  */
            mlist.erase(cur);
            mp.erase(key);
        }
        else                        // 不存在
        {
            if((int)mp.size() >= max_size)
            {
                /* 删除尾部元素 */
                auto bk = mlist.back();
                mlist.pop_back();
                mp.erase(bk.first);
            }
        }
        /* 插入元素 */
        mlist.push_front(node);
        mp[key] = mlist.begin();
    }
};


int main()
{
    // freopen("in.txt", "r", stdin);
    int ret = 0;

    LRUCache lRUCache(2);
    lRUCache.put(1, 1); // 缓存是 {1=1}
    // lRUCache.print_dlist();
    lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
    // lRUCache.print_dlist();
    ret = lRUCache.get(1);    // 返回 1
    // // lRUCache.print_dlist();
    cout << ret << endl;
    lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    // // lRUCache.print_dlist();
    ret = lRUCache.get(2);    // 返回 -1 (未找到)
    // // lRUCache.print_dlist();
    cout << ret << endl;
    lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    // // lRUCache.print_dlist();
    ret = lRUCache.get(1);    // 返回 -1 (未找到)
    cout << ret << endl;
    ret = lRUCache.get(3);    // 返回 3
    // // lRUCache.print_dlist();
    cout << ret << endl;
    ret = lRUCache.get(4);    // 返回 4
    // lRUCache.print_dlist();
    cout << ret << endl;

    return 0;
}