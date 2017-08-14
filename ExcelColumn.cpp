class Solution {
public:
    int titleToNumber(string s) {
        
        if(s.length() == 0) {
            
            return 0;
        }
        
        int sum = 0;
        int currentVal = 0;
        
        int index = s.length() - 1;
        while(index > -1) {
            
            currentVal = letterValue(s.at(index));
            
            sum += currentVal * (pow(26, (s.length() - index - 1)));
            --index;
        }
        
        return sum;
    }
    
    int letterValue(char c) {
        
        return c - 'A' + 1;
    }
};