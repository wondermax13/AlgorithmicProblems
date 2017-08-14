public class Solution {
    public List<String> letterCombinations(String digits) {
        
        List<String> result;
        
        int len = digits.length();
        
        if(len == 0) {
            
            result = new ArrayList<String>();
        }
        else {
            int fourLetterCombinations = find4LetterDigits(digits);
            int zeroLetterCombinations = find0LetterDigits(digits);
            int totalCombinations = 4 * fourLetterCombinations + 3 * (len -  fourLetterCombinations - zeroLetterCombinations);
            
            result = new ArrayList<String>(totalCombinations);
            
            for(int comb = 0; comb < totalCombinations; comb++) {
                
                result.add(new String());
            }
            
            setCombinations(digits, result);
        }
        
        return result;
    }
    
    protected void setCombinations(String digits, List<String> result) {
        
        // map;
        
        
    }
    
    protected int find4LetterDigits(String digits) {
        
        int count = 0;
        
        for(int index = 0; index < digits.length(); index++) {
            
            if(digits.charAt(index) == '7' 
                || digits.charAt(index) == '9') {
                
                ++count;
            }
        }
        
        return count;
    }
    
    protected int find0LetterDigits(String digits) {
        
        int count = 0;
        
        for(int index = 0; index < digits.length(); index++) {
            
            if(digits.charAt(index) == '0' 
                || digits.charAt(index) == '1') {
                
                ++count;
            }
        }
        
        return count;
    }
}