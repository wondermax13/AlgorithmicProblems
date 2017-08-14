class StringIterator {
public:
    StringIterator(string compressedString) : buffer(compressedString) {
        
        
        if(!buffer.empty()) {
            
            index = 0;
            c = buffer[index++];
            
            string numString;
            while(index < buffer.size() && isDigit(buffer[index])) {
                
                numString.push_back(buffer[index++]);
            }
            
            count = stoi(numString);
        }
    }
    
    char next() {
        
        if(count != 0) {
            
            --count;
            return c;
        }
        
        else if(index < buffer.size()) {
            c = buffer[index++];
            
            string numString;
            while(index < buffer.size() && isDigit(buffer[index])) {
                
                    numString.push_back(buffer[index++]);
            }
        
            count = stoi(numString);
        
            --count;
            return c;
        }
        
        return ' ';
    }
    
    bool hasNext() {
        
        return count > 0 || index < buffer.size();
    }
    
    bool isDigit(char c) {
        
        return c >= '0' && c <= '9';
    }
    
    string buffer;
    int count;
    char c;
    int index;
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */