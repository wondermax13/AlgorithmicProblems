class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        set<int> vals;
        
        int count = 0;
        
        if(k != 0) {
        for(auto index : nums) {
            
            if(vals.find(index) == vals.end()) {
                
                if(vals.find(index + k) != vals.end()) {
                    ++count;
                }
                if(vals.find(index - k) != vals.end()) {
                    ++count;
                }
                
                vals.insert(index);
            }
        }
        }
        else {
            for(auto index : nums) {
            
            if(vals.find(index) != vals.end()) {
                
                ++count;
            }
            
            vals.insert(index);
            }
        }
        
        return count;
    }
};