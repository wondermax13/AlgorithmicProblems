class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        
        int sum = 0;
        int curr = 0;
        
        if(n == 0) {
            
            return 1;
        }
        if(n == 1) {
            
            return 10;
        }
        
        curr = 9;
        sum = 9;
        
        /*
            The subproblem has been defined as finding no. of nos. with leading non-zeros
            Answer = sum + 1('0' number)
        */
        for(int digit = 2; digit < n+1; digit++) {
            
            if(10 -(digit -1) > 0) {
                
                curr = curr*(10 - (digit-1));
                sum += curr;
            }
        }
        
        return sum + 1;
    }
};