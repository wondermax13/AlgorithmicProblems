public class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        
        List<List<Integer>> triplets = new ArrayList<List<Integer>>();
        
        Arrays.sort(nums);
        
        //0 till 3rd last element
        for(int index1 = 0; index1 < nums.length - 2; index1++) {
            
            //Perform check to make sure this isn't a repeated element
            //Skip if index1 > 0 and nums[index1] == nums[index1 -1]
            if(index1 == 0 || index1 > 0 && nums[index1] != nums[index1 -1]) {
                
                int sum = -nums[index1],
                    startIndex = index1 + 1,
                    endIndex = nums.length - 1;
                
                boolean pairFound = false;
                
                while(startIndex < endIndex) {
                    
                    if(nums[startIndex] + nums[endIndex] == sum) {
                        
                        List<Integer> list = new ArrayList<Integer>();
                        
                        list.add(nums[index1]);
                        list.add(nums[startIndex]);
                        list.add(nums[endIndex]);
                        
                        triplets.add(list);
                        
                        //Don't set this since we need to move further and find other pairs
                        // pairFound = true;
                        
                        //Skip the further instances of the startIndex and endIndex with same nums[index] values
                        while(startIndex < endIndex && nums[startIndex] == nums[startIndex + 1]){
                            ++startIndex;
                        }
                        while(startIndex < endIndex && nums[endIndex] == nums[endIndex - 1]){
                            --endIndex;
                        }
                        //Do a final move
                        ++startIndex;--endIndex;
                    }
                    
                    else if(nums[startIndex] + nums[endIndex] < sum) {
                        
                        ++startIndex;
                    }
                    else {
                        --endIndex;
                    }
                }
            }
        }
        
        return triplets;
    }
}