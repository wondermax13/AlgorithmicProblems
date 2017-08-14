class Solution {
public:
    int numDecodings(string s) {
       
       int len = s.length();
       
       if(len == 0) {
           
           return 0;
       }
       if(len == 1) {
           
           return (s[0] - '0' == 0) ? 0 : 1;
       }
       if(len == 2) {
           
           if(isSeqLimiting(s[0], s[1])) return 0;
           
           return areDigitsValid(s[0], s[1]) ? 2 : 1;
       }
       
       int ways[s.length() + 1];
       
       ways[0] = 0;
       ways[1] = 1;
       
       int lastSequence = 0;
       int lastTwoValid = 0;
       
       //Index for the string
       int index = 2;
       bool foundInvalid = false;
       
       while(index < len && !foundInvalid) {
           
           foundInvalid = isSeqLimiting(s[index-1], s[index]);
           
           if(!foundInvalid) {
               
               lastSequence = ways[index-2];
               
               lastTwoValid = areDigitsValid(s[index-1], s[index]) ? lastSequence : 0;
               ways[index] = ways[index-1] + lastTwoValid;
           }
           
           ++index;
       }
       
       return foundInvalid ? 0 : ways[len-1];
    }
    
    bool areDigitsValid(char left, char right) {
        
        bool areValid = false;
        
        int leftDigit = left -'0',
            rightDigit = right - '0';
            
        return (leftDigit > 0 && leftDigit < 3 && rightDigit < 7);
    }
    
    bool isSeqLimiting(char left, char right) {
        
        bool areValid = false;
        
        int leftDigit = left -'0',
            rightDigit = right - '0';
            
        return (leftDigit > 2) && (rightDigit == 0);
    }
};