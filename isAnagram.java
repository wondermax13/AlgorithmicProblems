public class Solution {
    public boolean isAnagram(String s, String t) {
        
        if(s.length() != t.length()) {
            
            return false;
        }
        
        int freq = 0;
        
        Map<Character, Integer> map = new HashMap<Character, Integer>();
        
        for(int index = 0; index < s.length(); index++) {
            
            char left = s.charAt(index);
            char right = t.charAt(index);
            
            if(map.containsKey(left)) {
                
                freq = map.get(s.charAt(index));
            }
            else {
                freq = 0;
            }
            map.put(s.charAt(index), freq + 1);
            
            if(map.containsKey(right)) {
                
                freq = map.get(t.charAt(index));
            }
            else {
                freq = 0;
            }
            map.put(t.charAt(index), freq - 1);
        }
        
        for(Map.Entry entry : map.entrySet()) {
            
            if((Integer)entry.getValue() != 0) {
                
                return false;
            }
        }
        
        return true;
    }
}