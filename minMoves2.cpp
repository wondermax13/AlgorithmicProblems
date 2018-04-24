class Solution {
public:
    int minMoves2(vector<int>& nums) {
     
        int result = 0;
        
        sort(nums.begin(), nums.end());
        
        int mid = nums[nums.size() / 2];
        
        for(auto num : nums) {
            
            result += abs(num - mid);
        }
        
        return result;
    }
};