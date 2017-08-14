class Solution {
public:
    double myPow(double x, int n) {
        
        if(x == 0 || x == 1) {
            
            return x;
        }
        
        if(n == 0) {
            
            return 1;
        }
        
        if(n == -1) {
            
            return 1 / x;
        }
        if(n == 1) {
            
            return x;
        }
        
        // if(n > 0) {
            
            double prod = 1;
            
            if(n % 2 == 0) {
                
                double t = myPow(x, n/2);
                
                return t*t;
            }
            else {
                
                if(n < 0) {
                    
                    double t = myPow(x, n/2);
                    
                    return (t*t * (1/x));
                }
                else {
                    
                    double t = myPow(x, n/2);
                    
                    return (t*t * (x));
                }
            }
                // return (x*myPow(myPow(x, n/2), 2));
                
            /*for(int count = 0; count < n; count++) {
                
                prod *= x;
            }
            
            return prod;*/
        /*}
        else { // HANDLE THIS CASE INSIDE THE N%2 != 0 LOOP SINCE THAT IS WHERE THIS CASE MATTERS
            
            double inverse_prod = myPow(x, -n);
            return 1 /inverse_prod;
        }*/
        
        return 1;
    }
};