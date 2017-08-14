class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int newIndex = 0;
        
        for(int index = 0; index < nums.size(); index++) {
            
            if(nums[index] != val) {
                
                nums[newIndex] = nums[index];
                ++newIndex;
            }
        }
        
        return newIndex;
    }
};