public class Solution {
    public int missingNumber(int[] nums) {
        
        int number = -1;
        boolean found = false;
        
        boolean[] idealArray = new boolean[nums.length + 1];
        
        for(boolean b : idealArray ) {
            
            b = false;
        }
 
        for(int num : nums) {
            
            idealArray[num] = true;
        }
        
        for(int index = 0; index < idealArray.length && !found; index++) {
            
            if(!idealArray[index]) {
                
                found = true;
                number = index;
            }
        }
        
        return number;
    }
}