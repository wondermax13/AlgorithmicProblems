public class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        
        List<Integer> list = new ArrayList<Integer>();
        int len = nums.length;
        
        for(int index = 0; index < len; index++) {
            
            if(nums[Math.abs(nums[index]) - 1] < 0) {
                
                list.add(Math.abs(nums[index]));
            }
            else {
                nums[Math.abs(nums[index]) - 1] *= (-1);
            }
        }
        
        
        return list;
    }
}