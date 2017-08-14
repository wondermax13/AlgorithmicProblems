class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int res = 0;
        
        int index = 0;
        
        while(index < nums.size()) {
            
            res = res ^ index ^ nums[index];
            ++index;
        }
        
        return res ^ nums.size();
    }
};