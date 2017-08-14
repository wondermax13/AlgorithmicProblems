public class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        
        int currLen = 0, maxLen = 0;
        
        for(int i = 0; i < nums.length; i++) {
            
            if(nums[i] == 1) {
                ++currLen;
            }
            else {
                maxLen = Math.max(maxLen, currLen);
                currLen = 0;
            }
        }
        
        maxLen = Math.max(maxLen, currLen);
        
        return maxLen;
    }
}