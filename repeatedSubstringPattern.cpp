class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        int size = s.size();
        
        if(size == 0) {
            
            return true;
        }
        
        int len = 1;
        bool foundSubstring = false;
        bool foundMismatch = false;
        
        while(len < size && !foundSubstring) {
            
            
            if(size % len == 0) {
                
                foundMismatch = false;
            
                int index = len, end = index + (len -1);

                while(index < size && !foundMismatch) {
                
                    foundMismatch = !areSame(s, len, index, end);
                    index = end + 1;
                    end = index + (len -1);
                }
                
                foundSubstring = !foundMismatch;
            }
            
            ++len;
        }
        
        return foundSubstring;
    }
    
    bool areSame(string& s, int len, int start, int end) {
        
        bool foundMismatch = false;
        
        int index = 0;
        while(index < len && !foundMismatch) {
            
            foundMismatch = s[index] != s[index + start];
            
            ++index;
        }
        
        return !foundMismatch;
    }
};