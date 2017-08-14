class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        int count = 0;
        
        while(n > 0) {
            
            count = (n & 1) ? count + 1 : count;
            n /= 2;
            
            /* OR
                n &= n - 1;
                count++;
            */
        }
        
        return count;
    }
};