public class Solution {
    public List<int[]> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        
        List<int []> list = new ArrayList<int []>();
        
        if(nums1.length == 0 || nums2.length == 0) return list;
        
        int index1 = 0, index2 = 0;
        
        boolean endRange = false;
        
        while(k > 0 && !endRange) {
            
            int [] pair = new int[2];
            pair[0] = nums1[index1];
            pair[1] = nums2[index2];
            
            list.add(pair);
            
            if(index1 + 1 < nums1.length && index2 + 1 < nums2.length) {
                
                if(nums1[index1 + 1] > nums2[index2 + 1]) {
                    ++index2;
                }
               
                else
                    ++index1;
               
                --k;
            }
           
            else if(index1 + 1 < nums1.length && index2 + 1 >= nums2.length) {
               
                ++index1;
                --k;
            }
            
            else if(index1 + 1 >= nums1.length && index2 + 1 < nums2.length) {
               
                ++index2;
                --k;
            }
           
            endRange = index1 >= nums1.length || index2 >= nums2.length;
        }
        
        return list;
    }
}