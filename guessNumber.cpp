// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        
        bool found = false;
        int low = 1, high = n, target;
        
        while(low < high && !found) {
            
            //Avoid overflow
            int mean_ = low + (high - low)/2;
            int res = guess(mean_);
            
            if(res == 0) {
                
                found = true;
                target = mean_;
            }
            else if(res == 1) {
                
                low = mean_ + 1;
            }
            else {
                high = mean_;
            }
        }
        
        return found ? target : low;
    }
};