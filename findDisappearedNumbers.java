public class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        
        List<Integer> list = new ArrayList<Integer>();
        
        int len = nums.length;
        
        if(nums.length == 0 || nums.length == 1) return list;
        
        for(int index = 0; index < nums.length; index++) {
            
            int val = Math.abs(nums[index]);
            
            if(nums[val - 1] > 0) {
                nums[val - 1] = -nums[val - 1];
            }
        }
        
        for(int index = 0; index < nums.length; index++) {
            
            if(nums[index] > 0) {
                list.add(index + 1);
            }
        }
        
        return list;
    }
}