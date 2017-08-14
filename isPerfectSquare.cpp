class Solution {
public:
    bool isPerfectSquare(int num) {
        
        if(num <= 1) {
            
            return true;
        }
        
        bool found = false;
        
        int low = 1, high = num;
        
        int index = (low + high) / 2;
        
        while(low <= num / 2 && !found) {
            
            found = num == index*index;
            ++index;
        }
        
        return found;
    }
};

class Solution {
public:
    bool isPerfectSquare(int num) {
        
        if(num <= 1) {
            
            return true;
        }
        
        bool found = false;
        
        int low = 1, high = num;
        
        long index, target;
        
        while(low < high && !found) {
            
            index = (low + high) / 2;
            
            target = index*index;
            
            if(num == target) {
                
                found = true;
            }
            else if(num < target) {
                
                high = index;
            }
            else {
                low = index + 1;
            }
        }
        
        return found;
    }
};
