public class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        
        int len = s.length();
        boolean []split = new boolean[len + 1];
        
        split[0] = true;
        
        for(int endIndex = 1; endIndex <= len; endIndex++ ){
            
            for(int startIndex = 0; startIndex < endIndex; startIndex++) {
                
                
                if(split[startIndex]) {
                    
                    /*List<String> result = wordDict.stream()
                                          .filter(item -> item.equals(
                                          .collect(Collectors.toList());
                    */
                    
                    for(String str : wordDict) {
                        
                        if(str.equals(s.substring(startIndex, endIndex))) {
                            
                            split[endIndex] = true;
                            break;
                        }
                    }
                }
            }
        }
        
        return split[s.length()];
    }
}