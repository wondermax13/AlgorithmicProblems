public class Solution {
    public boolean wordPattern(String pattern, String str) {
        
        int len1 = pattern.length();
        int len2 = str.length();
        
        if(len1 == 0 && len2 == 0) {
            
            return true;
        }
        
/*        if( (len1 == 0 && len2 != 0) || (len1 != 0 && len2 == 0) ) {
            
            return false;
        }
*/        
        return checkPattern(pattern, str, len1, len2);
    }
    
    protected boolean checkPattern(
        String pattern, String str, int len1, int len2) {
        
        String [] words = str.split(" ");
        
        if(words.length != pattern.length()) return false;
        
        HashMap mapC = new HashMap<Character, Integer>();
        HashMap mapS = new HashMap<String, Integer>();
        
        boolean foundMismatch = false;
        int index1 = 0;
        
        boolean c_contained;
        boolean str_contained;

        String small;
        while(index1 < len1 && !foundMismatch) {
            
            c_contained = mapC.containsKey(pattern.charAt(index1));
            str_contained = mapS.containsKey(words[index1]);
            
            if(words[index1] == " ") return false;
            
            if(mapC.containsKey(pattern.charAt(index1)) ^ mapS.containsKey(words[index1])) return false;
            
            
            if( c_contained != str_contained) return false;
            
            if(c_contained && str_contained) {
                
                if(!mapC.get(pattern.charAt(index1)).equals(mapS.get(words[index1]))) {
                    
                    return false;
                }
                
            }
            
            mapC.put(pattern.charAt(index1), index1);
            mapS.put(words[index1], index1);

            ++index1;
        }
        
        return true;
    }
}