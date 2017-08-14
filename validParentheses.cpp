class Solution {
public:
    bool isValid(string s) {
        
        int len = s.length();
        
        if(len == 0) {
            
            return true;
        }
        
        if(len % 2 != 0) {
            
            return false;
        }
        
        int startIndex = 0,
            endIndex = s.length() - 1;
            
        bool invalid = false;
        
        stack<char> leftChars;
        
        while(startIndex < s.length()) {
            
            if(isLeftBracket(s[startIndex])) {
                
                leftChars.push(s[startIndex]);
            }
            
            else {
                
                if(leftChars.empty()) {
                    
                    return false;
                }
                
                char latestLeftChar = leftChars.top();
                leftChars.pop();
                
                if(!isCharPairValid(latestLeftChar, s[startIndex] )) {
                    
                    return false;
                }
            }

            ++startIndex;
        }
        
        return leftChars.empty();
    }
    
    bool isCharPairValid(char left, char right) {
        
        return (left == '(' && right == ')')
            || (left == '{' && right == '}')
            || (left == '[' && right == ']');
    }
    
    bool isLeftBracket(char bracket) {
        
        return bracket == '('
            || bracket == '{'
            || bracket == '[';
    }
};