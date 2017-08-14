class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string pre;
        int size = strs.size();
        
        if(size != 0) {
            
            sort(strs.begin(), strs.end());
            
            int checkLen = min(strs[0].size(), strs[size - 1].size());
            
            bool found = false;
            int charIndex = 0;
            while(charIndex < checkLen && !found) {
                
                if(strs[0][charIndex] == strs[size - 1][charIndex]) {
                    
                    pre += strs[0][charIndex];
                }
                else {
                    found = true;
                }
                
                ++charIndex;
            }
        }

        return pre;
    }
};