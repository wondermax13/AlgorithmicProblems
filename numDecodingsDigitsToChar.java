public class Solution {
    public int numDecodings(String s) {
        
        int len = s.length(), noOfWays = 0;
        
        if(len == 0) {
            
            noOfWays = len;
        }
        else {
            
            noOfWays = findWaysToDecode(s);
        }
        
        return noOfWays;
    }
    
    protected int findWaysToDecode(String s) {
        
        int [] ways = new int[s.length() + 1];
        
        ways[0] = 0;
        ways[1] = s.charAt(0) == '0' ? 0 : 1;
        
        for(int index = 1; index < s.length(); index++) {
            
            if(s.charAt(index) - '0' > 0) {
                
                ways[index+1] += ways[index];
            }
            
            if(doDigitsFormValidChar(s.charAt(index - 1), s.charAt(index))) {
                
                ways[index+1] += ways[index - 1];
            }
        }
        
        return ways[s.length()];
    }
    
    protected boolean doDigitsFormValidChar(char first, char second ) {
        
        
        return (first - '0' > 0) 
            && (first - '0' < 2 || (first - '0' < 3 && second - '0' < 7));
    }
}