class MyStack 
{
    queue<int> qu;
    queue<int> fuzhu_qu;
    int size;
public:
    MyStack() 
    {
        size = 0;
    }
    
    void push(int x) 
    {
        qu.push(x);
        size++;
    }
    
    int pop() 
    {
        int ret = top();

        /* 借助辅助队列实现pop  */
        for(int ii=0; ii<size-1; ii++)
        {
            fuzhu_qu.push(qu.front());
            qu.pop();
        }
        qu.pop();
        size--;
        swap(qu, fuzhu_qu);

        return ret;
    }
    
    int top() 
    {
        return qu.back();
    }
    
    bool empty() 
    {
        return size==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */