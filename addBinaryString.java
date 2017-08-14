public class Solution {
    public String addBinary(String a, String b) {
        
        StringBuilder result = new StringBuilder();
        
        if(a.isEmpty() && b.isEmpty()) {
            
            return "";
        }
        
        int q = 0, r = 0;
        int index1 = a.length() - 1, index2 = b.length()-1;
        
        while(index1 > -1 || index2 > -1) {
            
            int firstVal = index1  > -1 ? Character.getNumericValue(a.charAt(index1)) : 0;
            int secondVal = index2  > -1 ? Character.getNumericValue(b.charAt(index2)) : 0;
            
            r = (firstVal + secondVal + q)%2;
            q = (firstVal + secondVal + q)/2;
            
            result.insert(0, convertBit(r));
            
            --index1;
            --index2;
        }
        
        while(index1 > -1) {
            
            int firstVal = index1  > -1 ? Character.getNumericValue(a.charAt(index1)) : 0;
            
            r = (firstVal + q)%2;
            q = (firstVal + q)/2;
            
            result.insert(0, convertBit(r));
            
            --index1;
        }
        while(index2 > -1) {
            
            int secondVal = index2  > -1 ? Character.getNumericValue(b.charAt(index2)) : 0;
            
            r = (secondVal + q)%2;
            q = (secondVal + q)/2;
            
            result.insert(0, convertBit(r));
            
            --index1;
        }
        
        if(q == 1) {
            result.insert(0, convertBit(q));
        }
        
        
        return result.toString();
    }
    
    char convertBit(int r) {
        
        return r == 0 ? '0' : '1';
    }
}