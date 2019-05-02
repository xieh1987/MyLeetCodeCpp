class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        qstack.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        int qsize = qstack.size();
        for (int i=1;i<qsize;++i) {
            qstack.push(qstack.front());
            qstack.pop();
        }
        qstack.pop();
    }

    // Get the top element.
    int top() {
        int qsize = qstack.size();
        for (int i=1;i<qsize;++i) {
            qstack.push(qstack.front());
            qstack.pop();
        }
        int res = qstack.front();
        qstack.push(res);
        qstack.pop();
        return res;
    }

    // Return whether the stack is empty.
    bool empty() {
        return qstack.empty();
    }
    
private:
    queue<int> qstack;
};
