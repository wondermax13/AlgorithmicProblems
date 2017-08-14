class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        
        
        vector<int> comb(target+1, 0);
        
        comb[0] = 1;
        
        for(int prevTarg = 1; prevTarg < target + 1; prevTarg++) {
            
            for(int num = 0; num < nums.size(); num++) {
                
                if(prevTarg - nums[num] >= 0) {
                    
                    comb[prevTarg] += comb[prevTarg - nums[num]];
                }
            }
        }
        
        return comb[target];
    }
};