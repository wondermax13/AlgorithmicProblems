public class Solution {
    public List<List<Integer>> canUseDuplicatesToSumToTarget(int[] candidates, int target) {

        Arrays.sort(candidates);
        List<List<Integer>> lists = new ArrayList<>();
        generateCombinations(0, new ArrayList<Integer>(), lists, candidates, target);
        
        return lists;
    }
    
        protected void generateCombinations(
            int start,
            List<Integer> currList,
            List<List<Integer>> lists,
            int [] nums,
            int remain) {
                
            if(remain < 0) return;

            if(remain == 0) {
                lists.add(new ArrayList<>(currList));
            }
            else if(remain > 0) {
                
                for(int newNo = start; newNo < nums.length; newNo++) {
                    
                    //Since nos. are sorted, all the following nums[] will be > remain if
                    //this condn. fails
                    if(nums[newNo] <= remain) {
                        
                        currList.add(nums[newNo]);
                        generateSubset(newNo, currList, lists, nums, remain - nums[newNo]);
                        currList.remove(currList.size() - 1);
                    }
                }
            }
        }

        public List<List<Integer>> useUniquesToSumToTarget(int[] candidates, int target) {

        Arrays.sort(candidates);
        List<List<Integer>> lists = new ArrayList<>();
        generateCombinations(0, new ArrayList<Integer>(), lists, candidates, target);
        
        return lists;
    }
    
    protected void generateCombinations(
        int start,
        List<Integer> currList,
        List<List<Integer>> lists,
        int [] nums,
        int remain) {
            
        if(remain < 0) return;

        if(remain == 0) {
            lists.add(new ArrayList<>(currList));
        }
        else if(remain > 0) {
            
            for(int newNo = start; newNo < nums.length; newNo++) {
                
                //Since nos. are sorted, all the following nums[] will be > remain if
                //this condn. fails
                if(nums[newNo] <= remain && (newNo == start || nums[newNo] != nums[newNo - 1])) {
                    
                    currList.add(nums[newNo]);
                    generateSubset(newNo, currList, lists, nums, remain - nums[newNo]);
                    currList.remove(currList.size() - 1);
                }
            }
        }
    }
}