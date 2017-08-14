public class Solution {
    public boolean isPalindrome(String s) {
        
        
        if(s.isEmpty()) {
            
            return true;
        }
        
        boolean nonMatchFound = false;
        int startIndex = 0,
            endIndex = s.length()-1;
        
        
        while(!nonMatchFound && startIndex <= endIndex) {
            
            startIndex = findNextRightValidIndex(s, startIndex);
            endIndex = findNextLeftValidIndex(s, endIndex);
            
            if(startIndex != -1 && endIndex != -1) {
                
                char left = processChar(s.charAt(startIndex));
                char right = processChar(s.charAt(endIndex));
                
                if(left != right) {
                    
                    nonMatchFound = true;
                }
            }
            else {
                return true;
            }
        }
        
        return !nonMatchFound;
    }
    
    protected int findNextRightValidIndex(String s, int currIndex) {
        
        int index = currIndex + 1;
        
        while(index < s.length() && !Character.isLetterOrDigit(s.charAt(index))) {
            
            index++;
        }
        
        if(index < s.length()) {
            
            return index;
        }
        
        return -1;
    }
    
    protected int findNextLeftValidIndex(String s, int currIndex) {
        
        int index = currIndex - 1;
        
        while(index > -1 && !Character.isLetterOrDigit(s.charAt(index))) {
            
            index--;
        }
        
        if(index > -1) {
            
            return index;
        }
        
        return -1;
    }
    
    protected char processChar(char input) {
        
        char output;
        if(Character.isUpperCase(input)) {
            output = Character.toLowerCase(input);
        }
        else {
            output = input;
        }
        
        return output;
    }
}