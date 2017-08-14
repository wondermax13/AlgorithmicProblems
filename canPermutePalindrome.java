public class Solution {
    public boolean canPermutePalindrome(String s) {
        
        int []frequencies = new int[1024];
        //int []frequencies = new int[Character.getNumericValue('z') - Character.getNumericValue('a') + 1];
        Map<Character, Integer> map = new HashMap<Character, Integer>();
        
        for(char c : s.toCharArray()) {
            
            frequencies[c]++;
            
            if(map.containsKey(c)) {
                
                int fre = map.get(c);
                map.put(c, fre + 1);
            }
            else {
                
                map.put(c, 1);
            }
        }
        
        int noOfOdds = 0;
        
        for(int index = 0; index < frequencies.length && noOfOdds < 2; index++) {
            
            if(frequencies[index]%2 != 0) {
                
                // noOfOdds++;
            }
        }
        
        for(Map.Entry<Character,Integer> entry : map.entrySet()) {
            
            if(entry.getValue() %2 != 0) {
                
                noOfOdds++;
            }
        }
        
        return noOfOdds < 2;
    }
}