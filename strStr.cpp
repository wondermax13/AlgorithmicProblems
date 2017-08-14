class Solution {
public:
    int strStr(string haystack, string needle) {
        
        bool foundNeedle = false;
        
        if(needle.size() == 0) return 0;
        
        if(needle.size() > haystack.size()) return -1;
        
        int ind1 = 0, target = -1;
        
        while((ind1 <= haystack.size() - (needle.size())) && !foundNeedle) {
            
            bool mismatch = false;
            int ind2 = 0;
            while(ind2 < needle.size() && !mismatch) {
                
                mismatch = needle[ind2] != haystack[ind1 + ind2];
                
                ++ind2;
            }
            
            if(!mismatch) {
                
                foundNeedle = true;
                target = ind1;
            }
            
            ++ind1;
        }
        
        return target;
    }
};