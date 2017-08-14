class Solution {
public:
    string decodeString(string s) {
        
        string res = findVal(0, s.size() - 1, s);
        
        
        return res;
    }
    
    string findVal(int start, int end, string& s) {
        
        string res;
        /* No brackets found
        if() {
            
            
        }*/
        
        int index = start;
        while(index <= end) {
            
            cout << "index: " << index << endl;
            
            if(isLetter(s[index])) {
                
                res.append(1, s[index]);
                ++index;
            }
            else {
                
                string numString;
                
                while(isDigit(s[index])) {
                    
                    numString.append(1, s[index]);
                    ++index;
                }
                
                cout << "numString: " << numString << endl;
                int num = stoi(numString);
                
                int rb = findRightBracketFor(index, s);
                
                for(int i = 1; i <= num; i++) {
                    
                    res.append(findVal(index + 1, rb - 1, s));
                }
                
                index = rb + 1;
            }
            
            //cout << "res: " << res << endl;
        }
        
        cout << "res: " << res << endl;
        
        return res;
    }
    
    bool isLetter(char c) {
        
        return (c >= 'a' && c <= 'z')
            || (c >= 'A' && c <= 'Z');
    }
    
    bool isDigit(char c) {
        
        return (c >= '0' && c <= '9');
    }
    
    int findRightBracketFor(int leftBracket, string& s) {
        
        cout << "leftBracket: " << leftBracket << endl;
        
        int leftBrackets = 1;
        
        int index = leftBracket + 1;
        
        while(index < s.size() && leftBrackets > 0) {
            
            if(s[index] == '[') {
                
                ++leftBrackets;
            }
            
            if(s[index] == ']') {
                
                --leftBrackets;
            }
            
            ++index;
        }
        
        cout << "rightBracket: " << index - 1 << endl;
        
        return index - 1;
    }
};