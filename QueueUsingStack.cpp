class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {

        backStack.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        
        int movedElements = 0;
        while(!backStack.empty()) {
            
            ++movedElements;
            frontStack.push(backStack.top());
            backStack.pop();
        }
        
        frontStack.pop();
        
        while(!frontStack.empty()) {
            
            --movedElements;
            backStack.push(frontStack.top());
            frontStack.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        
        int movedElements = 0;
        while(!backStack.empty()) {
            
            ++movedElements;
            frontStack.push(backStack.top());
            backStack.pop();
        }
        
        int front = frontStack.top();
        
        while(!frontStack.empty()) {
            
            --movedElements;
            backStack.push(frontStack.top());
            frontStack.pop();
        }
        
        return front;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        
        return backStack.empty();
    }
    
    std::stack<int> frontStack,
                    backStack;
};