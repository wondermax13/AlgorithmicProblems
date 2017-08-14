public class Solution {
    public int firstUniqChar(String s) {
        
        Map<Character,Integer> map = new LinkedHashMap<Character,Integer>();
        
        int charFrequency = 0;
        
        for(char c : s.toCharArray()) {
            
            if(map.containsKey(c)) {
                
                charFrequency = map.get(c);
                map.put(c, charFrequency + 1);
            }
            else {
                
                map.put(c, 1);
            }
        }
        
        for(Map.Entry<Character,Integer> entry : map.entrySet()) {
            
            if(entry.getValue() == 1) {
                
                return s.indexOf(entry.getKey());
            }
        }
        
        return -1;
    }
    
}