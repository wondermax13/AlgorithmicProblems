class Solution {
public:
    int rob(vector<int>& nums) {
        
        int size = nums.size();
        
        if(size == 0) {
            
            return 0;
        }
        
        vector<int> rob_(size), dont_rob_(size);
        
        rob_[0] = nums[0];
        
        for(int index = 1; index < size; index++) {
            
            rob_[index] = dont_rob_[index - 1] + nums[index];
            dont_rob_[index] = rob_[index - 1];
            
            rob_[index] = max(rob_[index], dont_rob_[index]);
        }
        
        return max(rob_[size - 1], dont_rob_[size - 1]);
    }
};