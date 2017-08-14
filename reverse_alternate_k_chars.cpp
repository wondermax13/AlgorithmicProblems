class Solution {
public:
    string reverseStr(string s, int k) {
        
        string str(s);
        int size = str.size();\
        
        bool reverse_ = true;
        
        if(!(k > 1 && size > 0)) {
            
            return str;
        }
        
        int start = 0;
        int end = min(start + k - 1, size - 1);
            
        while(start < size) {
                
            if(reverse_) {
                reverseStr(str, start, end);
            }
            
            reverse_ = !reverse_;
            
            start = end + 1;
            end = min(start + k - 1, size - 1);
        }
        
        return str;
    }
    
    void reverseStr(string& s, int start, int end) {
        
        while(start < end) {
            
            swapChars(s[start], s[end]);
            
            ++start;
            --end;
        }
    }
    
    void swapChars(char& a, char& b) {
        
        char c = a;
        a    = b;
        b    = c;
    }
};