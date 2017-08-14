class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int size = nums.size();
        
        vector<int> result(size, 1);
        
        int prodLeft = 1, prodRight = 1;
        
        for(int index = 1; index < size; index++) {
            
            prodLeft *= nums[index - 1];
            result[index] *= prodLeft;
        }
        
        for(int index = size - 2; index >= 0; index--) {
            
            prodRight *= nums[index + 1];
            result[index] *= prodRight;
        }
        
        return result;
    }
};