class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        if(nums.size() != 0) {
            
            int startIndex = 0, index = 0;
            
            while(index < nums.size()) {
                
                if(nums[index] != 0) {
                    
                    nums[startIndex] = nums[index];
                    ++startIndex;
                }
                
                ++index;
            }
            
            while(startIndex < nums.size()) {
                
                nums[startIndex] = 0;
                ++startIndex;
            }
        }
    }
};