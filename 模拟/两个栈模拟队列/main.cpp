class MyQueue {
private:
    int size;
    stack<int> st;
    stack<int> fuzhu_st;

    void getDataFromStToFuzhuSt()
    {
        while(!st.empty())
        {
            fuzhu_st.push(st.top());
            st.pop();
        }
    }
public:
    /** Initialize your data structure here. */
    MyQueue() 
    {
        size = 0;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) 
    {
        st.push(x);
        size++;
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() 
    {
        int ret = peek();
        fuzhu_st.pop();
        size--;
        return ret;
    }
    
    /** Get the front element. */
    int peek() 
    {
        /* 移出st栈的数据到fuzhu_st */
        if(fuzhu_st.empty())
        {
            getDataFromStToFuzhuSt();
        }

        return fuzhu_st.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() 
    {
        return size == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */