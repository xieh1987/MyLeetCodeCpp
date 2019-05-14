class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s.push_back(x);
        int m = min(x, mn[mn.size()-1]);
        mn.push_back(m);
    }
    
    void pop() {
        s.erase(s.end()-1);
        mn.erase(mn.end()-1);
    }
    
    int top() {
        return s[s.size()-1];
    }
    
    int getMin() {
        return mn[mn.size()-1];
    }
    
private:
    vector<int> s;
    vector<int> mn{INT_MAX};
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
