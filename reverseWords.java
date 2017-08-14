public class Solution {
    public void reverseWords(char[] s) {
        
        int len = s.length;
        char[] result = new char[len];
        
        int spaceIndex = len - 1;
        int endIndex = len - 1;
        
        int resIndex = 0;
        
        while(spaceIndex > -1) {
            
            spaceIndex = findSpace(s, endIndex);
            resIndex = appendData(result, resIndex, s, spaceIndex + 1, endIndex);
            endIndex = spaceIndex - 1;
        }
        
        appendData(result, resIndex, s, 0, endIndex);
        
        for(int index = 0; index < len; index++) {
            s[index] = result[index];
        }
    }
    
    protected int findSpace(char[]s, int endIndex) {
        
        int index = endIndex - 1, spaceIndex = -1;
        boolean found = false;
        
        while(index > 0 && !found) {
            
            if(s[index] == ' ') {
                found = true;
                spaceIndex = index;
            }
            --index;
        }
        
        return spaceIndex;
    }
    
    protected int appendData(char[] res, int resIndex, char[] s, int start, int end ) {
        
        for(int index = start; index <= end; index++) {
            
            res[resIndex] = s[index];
            resIndex++;
        }
        
        if(start != 0) {
            
            res[resIndex] = ' ';
            resIndex++;
        }
        
        return resIndex;
    }
}