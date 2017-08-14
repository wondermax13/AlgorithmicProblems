class Solution {
public:
    bool checkPerfectNumber(int num) {
        
        if(num == 1) return false;
        
        bool sumMoreThanNumber = false;
        
        int divisor = 2, sum = 0;
        
        while(divisor <= sqrt(num) && !sumMoreThanNumber) {
            
            if(num % divisor == 0) {
                
                sum += divisor;
                
                if(divisor*divisor != num) {
                    
                    sum += num/divisor;
                }
                
                sumMoreThanNumber = sum > num;
            }
            
            ++divisor;
        }
        
        sum += 1; //1 is a factor
        
        return sum == num;
    }
};