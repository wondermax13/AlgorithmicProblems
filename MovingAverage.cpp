class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        
        size_ = size;
    }
    
    double next(int val) {
        
        if(q.empty()) {
            
            avg = val;
        }
        else {
            
            if(q.size() == size_) {
                
                int oldestElement = q.front();
                int sum_without_oldest = avg * size_ - oldestElement;
                
                
                
                
                avg = (avg*size_ - q.front() + val) / (size_);
                q.pop_front();
            }
            else {
                
                avg = (avg * q.size() + val) / (q.size() + 1);
            }
        }
        
        q.push_back(val);
        
        return avg; //sum / q.size();
    }
    
    double avg = 0; int size_;
    deque<int> q;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */