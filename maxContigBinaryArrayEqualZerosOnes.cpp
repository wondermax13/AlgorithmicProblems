class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        unordered_map<int, int> map_;
        
        //IMPORTANT
        map_.insert(make_pair(0, -1));
        
        int sum = 0, max_dist_ = 0;
        for(int index = 0; index < nums.size(); index++) {
            
            int addNo = nums[index] == 1 ? 1 : -1;
            
            sum += addNo;
            
            auto it = map_.find(sum);
            if(it != map_.end()) {
                
                max_dist_ = max(max_dist_, abs(index - it-> second));
            }
            else {
                
                map_.insert(make_pair(sum, index));
                // map_[sum] = index;
            }
        }
        
        return max_dist_;
    }
};