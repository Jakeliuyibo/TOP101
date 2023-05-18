#include <iostream>
using namespace std;

class mCirQueue
{
    private:
        int  capacity;       // 队列容量
        int *pdata;          // 数据存储
        int  pfront;        // 队列头部
        int  size;
    public:
        mCirQueue(int cap)
        {
            capacity = cap;
            pdata    = new int[cap];
            pfront   = 0;
            size     = 0;
        }
        void push(int e)
        {
            if(size == capacity)
            {
                cout << "full" << endl;
                return;
            }

            int prear = (pfront + size) % capacity;
            pdata[prear] = e;
            size++;
        }
        void pop()
        {
            if(size == 0)
            {
                cout << "empty" << endl;
                return;
            }
            
            cout << pdata[pfront] << endl;
            pfront = (pfront + 1) % capacity;
            size--;
        }
        void front()
        {
            if(size == 0)
            {
                cout << "empty" << endl;
                return;
            }

            cout << pdata[pfront] << endl;
        }
};

int main() 
{
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);

    int capacity, num_oper;
    cin >> capacity >> num_oper;

    mCirQueue mcirqueue(capacity);

    /* 循环读取输入行操作   */
    for (int idx=0; idx<num_oper; idx++)
    {   
        string oper;
        cin >> oper;
        if (oper == "push")
        {
            int num = 0; 
            cin >> num;
            mcirqueue.push(num);
        }
        else if( oper == "pop")
        {
            mcirqueue.pop();
        }
        else if( oper == "front")
        {
            mcirqueue.front();
        }
        else
        {
            cout << "error" << endl;
        }
    }
}
