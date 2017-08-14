public class Solution {
    public List<int[]> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        
        List<int []> list = new ArrayList<int []>();
        
        int len1 = nums1.length,
            len2 = nums2.length;
            
        if(len1 == 0 || len2 == 0 || k == 0) {
            
            return list;
        }
        
        boolean foundK = false;
        boolean[][] chosen = new boolean[len1][len2];
        
        PriorityQueue<int[]> q = new PriorityQueue<int[]>((a,b) -> nums1[a[0]] + nums2[a[1]] - nums1[b[0]] - nums2[b[1]]);
        
        q.offer(new int[] {0, 0});
        chosen[0][0] = true;
        
        int found = 0;
        
        
        while(found < k && !q.isEmpty()) {
            
            int[] curr = q.poll();
            
            list.add(new int[]{nums1[curr[0]], nums2[curr[1]]});
            ++found;
            
            if(curr[0] + 1 < len1 && !chosen[curr[0] + 1][curr[1]]) {
                
                q.offer(new int[]{curr[0] + 1, curr[1]});
                chosen[curr[0] + 1][curr[1]] = true;
            }
                
            if(curr[1] + 1 < len2 && !chosen[curr[0]][curr[1] + 1]) {
                
                q.offer(new int[]{curr[0], curr[1] + 1});
                chosen[curr[0]][curr[1] + 1] = true;
            }
        }
        
        return list;
    }
}