class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        q = vector<int>(k, 0);
        start = 0;
        end = 0;
        len = 0;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(this->isFull()) return false;
        if(end==q.size()) end = 0;
        q[end] = value;
        ++end;
        ++len;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(this->isEmpty()) return false;
        q[start] = NULL;
        ++start;
        if(start==q.size()) start = 0;
        --len;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(this->isEmpty()) return -1;
        else return q[start];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(this->isEmpty()) return -1;
        else return q[end-1];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return len==0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return len==q.size();
    }
    
private:
    int start;
    int end;
    int len;
    vector<int> q;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
