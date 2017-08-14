class Solution {
public:
    bool isStrobogrammatic(string num) {
        
        int size = num.size();
        
        if(size == 0) {
            
            return true;
        }
        
        int index = 0;
        bool foundException = false, valid = true;
        
        while(index <= (size - 2)/2 && !foundException) {
            
            if(!isPairValid(num[index], num[size - 1 - index])) {
                   
                foundException = true;
            }
            
            ++index;
        }
        
        if(size % 2 == 1) {
            
            if(!isDigitValid(num[(size)/2])) {
                
                foundException = true;
            }
        }
        
        return !foundException;
    }
    
    bool isDigitValid(char c) {
        
        return (c == '1' || c == '8' || c == '6' || c == '9' || c == '0');
    }
    
    bool isPairValid(char l, char r) {
        
        return (l == '8' && r == '8')
            || (l == '1' && r == '1')
            || (l == '0' && r == '0')
            || (l == '6' && r == '9')
            || (l == '9' && r == '6');
    }
};