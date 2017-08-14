public class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
    
            Arrays.sort(nums);
        List<List<Integer>> lists = new ArrayList<>();
        generateSubset(0, new ArrayList<Integer>(), new boolean[nums.length], lists, nums);
        
        return lists;
    }

    protected void generateSubset(int start,
        List<Integer> currList,
        boolean[] used,
        List<List<Integer>> lists,
        int [] nums) {
         
        if(currList.size() == nums.length) {
            lists.add(new ArrayList<>(currList));
        }
        else {
/*            for(int newNo = 0; newNo < nums.length; newNo++) {
                
                    if( !( used[newNo] || (newNo > 0 && nums[newNo] == nums[newNo-1] && !used[newNo-1]) ) ) {
                        
                        used[newNo] = true;
                        currList.add(nums[newNo]);

                        generateSubset(newNo + 1, currList, used, lists, nums);

                        currList.remove(currList.size() - 1);
                        used[newNo] = false;
                    }
                    */
                    for(int i = 0; i < nums.length; i++){
            if(!(used[i] || i > 0 && nums[i] == nums[i-1] && !used[i - 1])) { //continue;
            used[i] = true; 
            currList.add(nums[i]);
            generateSubset(i + 1, currList, used, lists, nums);
            used[i] = false; 
            currList.remove(currList.size() - 1); }
        }
            // }
        }
    }
}