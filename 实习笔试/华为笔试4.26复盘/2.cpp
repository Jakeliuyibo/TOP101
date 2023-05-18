#include <bits/stdc++.h>

using namespace std;

struct mDListNode
{
    int val;
    mDListNode *prev;
    mDListNode *next;
    mDListNode()      : val(-1), prev(nullptr), next(nullptr){}
    mDListNode(int v) : val(v) , prev(nullptr), next(nullptr){}
};

class mResourcePool
{
public:
    mResourcePool(int min, int max) 
        : range_min(min), range_max(max)
    {
        front = new mDListNode(-1);
        tail  = new mDListNode(-1);
        front->next = tail;
        tail->prev  = front;

        /* 创建资源 */
        for(int idx=min; idx<=max; idx++)
        {
            auto node = new mDListNode(idx);
            push_back(node);
        }
    }
    ~mResourcePool(){};

    /* 分配资源，从头部删除元素 */
    void allocate(int num_allocate)
    {
        for(int ii=0; ii<num_allocate; ii++)
        {
            pop_front();
        }
    }

    /* 分配资源，从中间删除元素 */
    void allocate_specify(int node_id)
    {
        mDListNode *node = mp[node_id];
        pop_specify(node);
    }

    /* 释放资源，加入到尾部     */
    void release(int node_id)
    {
        mDListNode *node = new mDListNode(node_id);
        push_back(node);
    }

    int get_ret()
    {
        mDListNode *head = front;
        while(head)
        {
            cout << head->val << "->";
            head = head->next;
        }
        cout << endl;
        return front->next->val;
    }

private:

    /* 加入资源，添加到尾部   */
    void push_back(mDListNode *node)
    {
        mDListNode *tmp = tail->prev;
        tmp->next = node;
        node->prev = tmp;
        node->next = tail;
        tail->prev = node;

        /* 记录位置 */
        mp[node->val] = node;
    }

    /* 分配资源，从头部删除元素 */
    void pop_front()
    {
        mDListNode *tmp = front->next->next;
        front->next = tmp;
        tmp->prev  = front;
    }

    void pop_specify(mDListNode *node)
    {
        mDListNode *pp = node->prev;
        mDListNode *nn = node->next;

        pp->next = nn;
        nn->prev = pp;
    }

private:
    int range_min;
    int range_max;
    mDListNode *front;
    mDListNode *tail;
    map<int, mDListNode*> mp;  // 存储节点位置
};

int main()
{
    freopen("in.txt","r", stdin);

    /* 输入处理 */
    int range_min, range_max;
    cin >> range_min >> range_max;
    int num_opr;
    cin >> num_opr;
    vector<vector<int>> opr(num_opr, vector<int>(2,0));
    for(int iter=0; iter<num_opr; iter++)
    {
        cin >> opr[iter][0] >> opr[iter][1];
    }

    /* 模拟    */
    mResourcePool pool(range_min, range_max);
    pool.get_ret();
    for(int idx=0; idx<num_opr; idx++)
    {
        cout << "op " << opr[idx][0] << opr[idx][1] << endl;
        if(opr[idx][0] == 1)
        {
            pool.allocate(opr[idx][1]);
            pool.get_ret();
        }
        else if(opr[idx][0] == 2)
        {
            pool.allocate_specify(opr[idx][1]);
            pool.get_ret();
        }
        else if(opr[idx][0] == 3)
        {
            pool.release(opr[idx][1]);
            pool.get_ret();
        }
    }

    /* 输出处理 */
    cout << "res" << pool.get_ret() << endl;

    return 0;
}



