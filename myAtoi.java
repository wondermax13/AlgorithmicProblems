public class Solution {
    public int myAtoi(String str) {
        
        int len = str.length();
        if(len == 0) {
            return 0;
        }
        
        int index = 0, negations = 0;
        while(index < len 
            && (str.charAt(index) == '-' || str.charAt(index) == '+')) {
            
            if(str.charAt(index) == '-') {
                
                ++negations;
            }
            
            ++index;
        }
        
        if(index == len) return 0;
        
        int x = (int)(Math.pow(-1, negations));
        return (x)*(translateAbsoluteVal(str, index, len));
        /*if((-1) ^  == '-') {
            return len > 1 ? 0 - () : 0;
        }
        else if(str.charAt(0) == '+') {
            return len > 1 ? translateAbsoluteVal(str, 1, len) : 0;
        }
        else {
            return translateAbsoluteVal(str, 0, len);
        }*/
    }
    
    protected int translateAbsoluteVal(String str, int index, int len) {
        
        int val = str.charAt(index) - '0';
        
        for(int i = index + 1; i < len; i++) {
            
            val = 10*val + (str.charAt(i) - '0');
        }
        
        return val;
    }
}