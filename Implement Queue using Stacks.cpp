class Queue {
    
private:
    stack<int> squeue;
    
public:
    // Push element x to the back of queue.
    void push(int x) {
        squeue.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        stack<int> temp;
        while (!squeue.empty()) {
            temp.push(squeue.top());
            squeue.pop();
        }
        temp.pop();
        while(!temp.empty()) {
            squeue.push(temp.top());
            temp.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        stack<int> temp;
        while (!squeue.empty()) {
            temp.push(squeue.top());
            squeue.pop();
        }
        int res = temp.top();
        while(!temp.empty()) {
            squeue.push(temp.top());
            temp.pop();
        }
        return res;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return squeue.empty();
    }
};
