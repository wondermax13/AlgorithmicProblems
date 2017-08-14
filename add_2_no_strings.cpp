class Solution {
public:
    string addStrings(string num1, string num2) {
        
        string res;
        
        int index1 = num1.size() - 1;
        int index2 = num2.size() - 1;
        
        int sum, r = 0, q = 0;
        
        while(index1 > -1 && index2 > -1) {
            
            sum = addDigits(num1[index1], num2[index2]) + q;
            
            q = sum / 10;
            r = sum % 10;
            
            res.insert(0, to_string(r));
            
            --index1;
            --index2;
        }
        
        while(index1 > -1) {
            
            sum = num1[index1] - '0' + q;
            
            q = sum / 10;
            r = sum % 10;
            
            res.insert(0, to_string(r));
            
            --index1;
        }
        
        while(index2 > -1) {
            
            sum = num2[index2] - '0' + q;
            
            q = sum / 10;
            r = sum % 10;
            
            res.insert(0, to_string(r));
            
            --index2;
        }
        
        if(q > 0) {
            
            res.insert(0, to_string(q));
        }
        
        return res;
        
    }
    
    int addDigits(char a, char b) {
        
        return (a - '0') + (b - '0');
    }
};