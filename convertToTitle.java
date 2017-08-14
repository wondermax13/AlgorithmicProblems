public class Solution {
    public String convertToTitle(int n) {
        
        StringBuilder str = new StringBuilder();
        
        int base = 26;
        int exp = 0;
        int remainder = 0;
        
        while(Math.pow(base,exp) <= n) {
            
            exp++;
        }
        
        exp--;
        
        char letter;
        
        while(n >= 0) {
            
            int power = (int)Math.pow(base,exp);
            int q = n / power;
            
            n -= q*power;
            exp--;
            
            letter = convertToLetter(q);
            str.append(letter);
        }
        
        return str.toString();
    }
    
    protected char convertToLetter(int exp) {
        
        if(exp < 1 || exp > 26) {
            
            return '&';
        }
        
        int A = 'A';
        
        return (char) (A + exp - 1);
    }
}