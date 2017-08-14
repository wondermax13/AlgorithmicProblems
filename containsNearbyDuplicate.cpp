class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        if(nums.size() < 2) return false;
        
        unordered_map<int, int> set_;
        
        int index = 0;
        bool found = false;
        
        while(index < nums.size() && !found) {
            
            auto it = set_.find(nums[index]);
            
            if(it != set_.end()) {
                
                if(index - it->second < k + 1) {
                    
                    found = true;
                }
                else {
                    set_[nums[index]] = index;
                }
            }
            else {
                //Erase indices behind by more than k
                if(index > k) {
                    
                    set_.erase(set_.find(nums[index - k - 1]));
                }
                
                set_.insert(make_pair(nums[index], index));
            }
            
            ++index;
        }
        
        return found;
    }
};