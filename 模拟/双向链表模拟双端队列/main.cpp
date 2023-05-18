struct DualListNode
{
    int val;
    DualListNode* prev;
    DualListNode* next;
    DualListNode(int x) : val(x), prev(nullptr), next(nullptr) {}
};

class MyCircularDeque {
private:
    DualListNode* head;
    DualListNode* tail;
    int num;                // 节点个数
    int capacity;           // 容量
public:
    MyCircularDeque(int k) 
    {
        capacity = k;
        num = 0;
        head = new DualListNode(-1);
        tail = new DualListNode(-1);
        head->next = tail;
        tail->prev = head;
    }
    
    bool insertFront(int value) 
    {
        if(isFull())
            return false;

        DualListNode* last = head->next;
        DualListNode* curr = new DualListNode(value);
        head->next = curr;
        curr->prev = head;
        curr->next = last;
        last->prev = curr;
        num++;
        return true;
    }
    
    bool insertLast(int value) 
    {
        if(isFull())
            return false;
            
        DualListNode* last = tail->prev;
        DualListNode* curr = new DualListNode(value);
        last->next = curr;
        curr->prev = last;
        curr->next = tail;
        tail->prev = curr;
        num++;
        return true;
    }
    
    bool deleteFront() 
    {
        if(isEmpty())
            return false;

        DualListNode* last = head->next->next;
        head->next = last;
        last->prev = head;
        num--;
        return true;
    }
    
    bool deleteLast() 
    {
        if(isEmpty())
            return false;

        DualListNode* last = tail->prev->prev;
        last->next = tail;
        tail->prev = last;
        num--;
        return true;
    }
    
    int getFront() 
    {
        if(isEmpty())
            return -1;
        else
            return head->next->val;
    }
    
    int getRear() 
    {
        if(isEmpty())
            return -1;
        else
            return tail->prev->val;
    }
    
    bool isEmpty() 
    {
        return num==0;
    }
    
    bool isFull() 
    {
        return num==capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */