public class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        
        Arrays.sort(nums);
        List<List<Integer>> lists = new ArrayList<>();
        generateSubset(0, new ArrayList<Integer>(), lists, nums);
        
        return lists;
    }
    
    protected void generateSubset(int start,
        List<Integer> currList,
        List<List<Integer>> lists,
        int [] nums) {

        lists.add(new ArrayList<>(currList));
        
        //Will reach here since for loop determines the range of start.
        //We call start + 1
         //if(start > nums.length - 1) return;

        
        for(int newNo = start; newNo < nums.length; newNo++) {
            
            //Check for duplicates or if newNo == start
            if(newNo == start || (nums[newNo] != nums[newNo - 1])) {
             
                currList.add(nums[newNo]);
                generateSubset(newNo + 1, currList, lists, nums);
                currList.remove(currList.size() - 1);
            }
        }
    }
}