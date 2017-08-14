class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        
        q.push_back(x);
        
        for(int i = 0; i < q.size() - 1; i++) {
            
            int x = q.front();
            q.pop_front();
            q.push_back(x);
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        
        int val = q.front();
        q.pop_front();
        
        return val;
    }
    
    /** Get the top element. */
    int top() {
        
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        
        return q.empty();
    }
    
    deque<int> q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */