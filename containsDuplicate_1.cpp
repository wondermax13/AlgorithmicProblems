class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        if(nums.size() < 2) return false;
        
        set<int> set_;
        
        int index = 0;
        bool found = false;
        
        while(index < nums.size() && !found) {
            
            if( (set_.find(nums[index]) != set_.end() )) {
                
                found = true;
            }
            else {
                set_.insert(nums[index]);
            }
            
            ++index;
        }
        
        return found;
    }
};