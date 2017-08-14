class Solution {
public:
    bool isPowerOfThree(int n) {
        
        bool failed = false;
        if(n == 0) {
            
            failed = true;
        }
        else {
            while( n != 1 && !failed) {
            
                failed = n % 3 != 0;
                n /= 3;
            }
        }
        
        return !failed;/
    }
};