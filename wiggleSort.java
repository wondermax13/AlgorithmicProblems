public class Solution {
    public void wiggleSort(int[] nums) {
        
        int len = nums.length;
        
        if(len < 2) return;
        
        boolean greater = true;
        
        for(int i = 1; i < nums.length; i++) {
            
            // greater = i%2 == 1;
            if(greater && nums[i] < nums[i-1]) {
                
                swap(i, i-1, nums);
            }
            else if(!greater && nums[i] > nums[i-1]) {
                
                swap(i, i-1, nums);
            }
            
             greater = !greater;
        }
    }
    
    protected void swap(int a, int b, int[] nums) {
        
        int c = nums[b];
        nums[b] = nums[a];
        nums[a] = c;
    }
}