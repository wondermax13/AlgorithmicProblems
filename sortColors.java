public class Solution {
    public void sortColors(int[] nums) {
        
        int len = nums.length;
        int movedzeros = 0, movedones = 0;
        
        //1st pass
        for(int index = len - 1; index > 0; index--) {
            
            if(nums[index] == 0) {
                
                boolean found = false;
                int num = 0;
                
                while(num < index && !found) {
                    
                    if(nums[num] == 1 || nums[num] == 2) {
                        
                        nums[index] = nums[num];
                        nums[num] = 0;
                        found = true;
                        ++movedzeros;
                    }
                    
                    num++;
                }
            }
        }
        
        //2nd pass
        for(int index = len - 1; index > 0; index--) {
            
            if(nums[index] == 1) {
                
                boolean found = false;
                int num = movedzeros;
                
                while(num < index && !found) {
                    
                    if(nums[num] == 2) {
                        
                        nums[index] = nums[num];
                        nums[num] = 1;
                        found = true;
                        ++movedones;
                    }
                    
                    num++;
                }
            }
        }
    }
}