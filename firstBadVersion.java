/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        
        int startIndex = 1;
        int endIndex = n;
        
        while(startIndex < endIndex) {
            
            int mid = startIndex + (endIndex - startIndex) / 2;
            
            if(isBadVersion(mid)) {
                
                endIndex = mid;
            }
            else {
                startIndex = mid + 1;
            }
        }
        
        return findBadForRange(1, n);
    }
    
    protected int findBadForRange(int startIndex, int endIndex) {
        
        int badIndex = -1;
        
        if(startIndex == endIndex) {
            
            badIndex = startIndex;
        }
        else if(startIndex > endIndex) {
            
            badIndex = -1;
        }
        
        else {
            
            int mid = startIndex + (endIndex - startIndex) / 2;
            
            if(isBadVersion(mid)) {
                
                badIndex = findBadForRange(startIndex, mid);
            }
            else {
                badIndex = findBadForRange(mid + 1, endIndex);
            }
        }
        
        return badIndex;
    }
}