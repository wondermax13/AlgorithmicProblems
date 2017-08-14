public class Solution {
    public String multiply(String num1, String num2) {
        
        int len1 = num1.length();
        int len2 = num2.length();
        
        int []result = new int[len1 + len2];
        
        for(int index1 = len1 - 1; index1 > -1; index1--) {
            
            
            for(int index2 = len2 - 1; index2 > -1; index2--) {
            
                int targetIndex = index1 + index2 + 1;
                
                int q = 0, r = 0, prod = 0;
                
                prod = (num1.charAt(index1) - '0') * (num2.charAt(index2) - '0');
                
                r = (prod + result[targetIndex]) % 10;
                q = (prod + result[targetIndex]) / 10;
                
                result[targetIndex] = r;
                result[targetIndex - 1] += q;
            }
        }
        
        StringBuilder res = new StringBuilder();
        
        for(int pos : result) {
            
            if(!(res.length() == 0 && pos == 0)) {
                
                res.append(pos);
            }
        }
        
        /*int index = 0;
        while(result[index] == '0' && index < len1 + len2) {
            ++index;
        }
        
        // ++index;
        
        while(index < len1 + len2) {
            
            res.append(result[index]);
            ++index;
        }
        */
        return res.length() == 0 ? "0" : res.toString();
    }
}