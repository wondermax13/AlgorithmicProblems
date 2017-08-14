public class Solution {
    public boolean isOneEditDistance(String s, String t) {
        
        boolean oneEditAway = false;
        
        if(Math.abs(s.length() - t.length()) > 1) {
            
            oneEditAway = false;
        }
        else {
            
            int sLen = s.length(), tLen = t.length();
            if((sLen == 0 && tLen == 1) || (sLen == 1 && tLen == 0)) {
                
                return true;
            }
            
            String shorter = s.length() <= t.length() ? s : t;
            String longer = s.length() <= t.length() ? t : s;
            
            oneEditAway = areOneEditAway(shorter, longer);
        }
        
        return oneEditAway;
    }
    
    boolean areOneEditAway(String shorter, String longer) {
        
        boolean areEqualLength = shorter.length() == longer.length(),
                areAway = false;
                
        int noOfEdits = 0;
                
        int shorterLen = shorter.length();
        int longerLen = longer.length();
        
        int index1 = 0, index2 = 0;
        
        while((index1 < shorterLen) && noOfEdits < 2) {
            
            if(shorter.charAt(index1) != longer.charAt(index2)) {
                
                ++noOfEdits;
                
                if(!areEqualLength) {
                    
                    ++index2;
                }
            }
            
            ++index1;
            ++index2;
        }
        
        if(areEqualLength) {
            
            areAway = (noOfEdits == 1);
        }
        else {
            areAway = (noOfEdits == 0 && index2 == longerLen - 1)
                || (noOfEdits == 1 && index2 == longerLen);
        }
        
        return areAway;
    }
    
}