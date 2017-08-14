public class Solution {
    public int findTargetSumWays(int[] nums, int S) {
        
        int sum = 0;
        
        for(int num : nums) {
            
            sum += num;
        }
        
        int[] ways = new int[2*(sum + 1) + 1];
        int[] next = new int[2*(sum + 1) + 1];
        
        for(int num : nums) {
            
            // ways[mapI(index + num, sum)] = 1;
        }
        
        for(int num : nums) {
            
            for(int index = -sum; index <= sum; index++) {
                
                if(index + num <= sum) {
                    
                    next[mapI(index + num, sum)] += ways[mapI(index, sum)];
                }
                
                if(index - num > -sum + 1) {
                    
                    next[mapI(index - num, sum)] += ways[mapI(index, sum)];
                }
            }
            
            ways = next;
        }
        
        return ways[mapI(S, sum)];
    }
    
    int mapI(int index, int sum) {
        
        if(index == 0) return sum;
        
        if(index < 0) return sum - Math.abs(index);
        
        return sum + index;
    }
}