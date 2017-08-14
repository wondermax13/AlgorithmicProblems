class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        int index = 0, endIndex = nums.size() - 1, moves = 0;
        
        int diff = nums[endIndex] - nums[index];
        
        while(endIndex != 0) {
            
            
            moves += (nums[endIndex] - nums[0]);
            
            --endIndex;
        }
        
        return moves;
    }
    
    bool checkSame(vector<int> nums) {
        
        bool found = false;
        
        int num = nums[0];
        int index = 1;
        
        while(index < nums.size() && !found) {
            
            found = num != nums[index];
        }
        
        return !found;
    }
};