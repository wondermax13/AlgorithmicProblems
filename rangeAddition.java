public class Solution {
    public int[] getModifiedArray(int length, int[][] updates) {
        
        // Arrays.sort(updates, (int[]a, int[]b) ->(a[0] - b[0]));
        
        if(length < 0) return null;
        int [] res = new int[length];
        
        for(int update = 0; update < updates.length; update++) {
            
            res[updates[update][0]] += updates[update][2];
            
            if(updates[update][1] < length -1 ) {
                
                res[updates[update][1] + 1] -= updates[update][2];
            }
        }
        
        int sum = 0;
        for(int index = 0; index < length; index++) {
            
            sum += res[index];
            
            res[index] = sum;
        }
        
        return res;
    }
    
    protected int findFirstGreaterUpdate(int index, int[][] updates) {
        
        int high = updates.length - 1, low = 0;
        
        while(low <= high) {
            
            int pivot = (low + high)/2;
            
            if(index <= updates[pivot][0]) {
                
                high = pivot - 1;
            }
            else {
                low = pivot + 1;
            }
        }
        
        return low;
    }
}