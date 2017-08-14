class Solution {
public:
    int mySqrt(int x) {
        
        if(x == 0 || x == 1) {
            
            return x;
        }
        
        bool passed_x_ = false;
        int i = 2, target = -1;
        while(!passed_x_) {
            
            passed_x_ = !(i*i < x);
                
            if(passed_x_) {
                
                target = i*i == x ? i : i - 1;
            }

            ++i;
        }
        
        return target;
    }
};

class Solution {
public:
    int mySqrt(int x) {
        
        if(x == 0 || x == 1) {
            
            return x;
        }
        
        if(x == 2) return 1;
        
        bool passed_x_ = false;
        int low = 1, high = x;
        int target = -1;
        
        while(low < high && !passed_x_) {
            
            int mid = low + (high - low) / 2;
            
            if(mid*mid == x) {
                
                return mid;
            }
            else if(mid > x/mid) {
                
                high = mid - 1;
            }
            else {
                
                if(mid + 1 > x/(mid + 1)) {
                    
                    return mid;
                }
                
                low = mid + 1;
            }
        }
        
        return low;
    }
};