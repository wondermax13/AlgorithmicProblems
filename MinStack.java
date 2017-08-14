public class MinStack {

    /** initialize your data structure here. */
    public MinStack() {
        
        stack = new Stack<Long>();
        //min = Integer.MIN_VALUE;
    }
    
    public void push(int x) {
        
        if(stack.isEmpty()) {
            
            stack.push(0L);
            min = x;
        }
        else {
            
            stack.push(x - min);
            if(x < min) min = x;
        }
    }
    
    public void pop() {
        
        if(stack.isEmpty()) {
            
            return;
        }
        else {
            
            long topVal = stack.pop();
            if(topVal < 0) {
                min = min - topVal;
            }
        }
    }
    
    public int top() {
        
        if(stack.isEmpty()) {
            
            return 0;
        }
        
        long topVal = stack.peek();
        
        if(topVal > 0) {
            return (int)(min + topVal);
        }
        
        return (int)min;
    }
    
    public int getMin() {
        
        return (int)min;
    }
    
    protected Stack<Long> stack;
    protected long min;
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */