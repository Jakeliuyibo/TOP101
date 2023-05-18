class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() 
    {

    }
    
    void addNum(int num) 
    {
        if(less_q.size() == greater_q.size())  // 偶数，先插入less_queue，然后移除less_queue一个元素到greater_queue
        {
            greater_q.push(num);

            /* 平衡less_q和greater_q    */
            less_q.push(greater_q.top());
            greater_q.pop();
        }
        else                                // 奇数，先插入greater_q，然后移除greater_q一个元素到less_queue
        {
            less_q.push(num);

            /* 平衡less_q和greater_q    */
            greater_q.push(less_q.top());
            less_q.pop();
        }
    }
    
    double findMedian() 
    {
        if((greater_q.size() + less_q.size())%2 == 0)
        {
            return (greater_q.top() + less_q.top()) / 2.0;
        }
        else
        {
            return less_q.top();
        }
    }
private:
    priority_queue<int, vector<int>, greater<int>>  greater_q;  // 维护中位数-最大数
    priority_queue<int, vector<int>, less<int>>     less_q;     // 维护中位数-最小数
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */