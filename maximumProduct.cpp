class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        
        int res;
        
        if(nums.size() == 3) {
            
            res = nums[0] * nums[1] * nums[2];
        }
        
        sort(nums.begin(), nums.end());
        
        if(nums[0] < 0 && nums[1] < 0) {
            
            res = max(nums[0] * nums[1] * nums[nums.size() - 1], nums[nums.size() - 3] * nums[nums.size() - 2] * nums[nums.size() - 1]);
        }
        
        else {
            
            res = nums[nums.size() - 3] * nums[nums.size() - 2] * nums[nums.size() - 1];
        }
        
        return res;
    }
};