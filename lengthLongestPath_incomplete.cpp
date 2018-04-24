class Solution {
public:
    int lengthLongestPath(string input) {
        
    }
    
    void getMaxLength(
        int level, int& curr, int& maxLen, int start, int end, string& input) {
       
        int slashNLoc = findSlashN(input, start, end);
        
        if(slashNLoc == -1) {
            
            if(dotFound(start, end)) {
                
                curr += (end - start);
                maxLen = max(maxLen, curr);
            }
            else { }
        }
        else {
            getMaxLength(level + 1, curr + slashNLoc - start, maxLen, slashNLoc + 2*level, end, input);
        }
    }
};