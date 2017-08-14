class Solution {
public:
    int findNthDigit(int n) {
        
        if(n <= 9) {
            
            return n;
        }
        
        int power = 1;
        
        int val = (pow(10, power-1) * 9 * power);
        
        cout << " power " << val << endl;
        
        while(n > pow(10, power-1) * 9 * power) {
            
            n -= pow(10, power-1) * 9 * power;
            
            power++;
        }
        
        int q = n / power, r = n % power;
        
        cout << n << endl;
        cout << q << " " << r << endl;
        
        int num = r > 0 ? pow(10, power-1) + q : pow(10, power-1) + q - 1;
        
        int digit = getDigit(num, r);
        
        return digit;
    }
    
    int getDigit(int num, int r) {
        
        string num_str = to_string(num);
        
        int index = r == 0 ? num_str.size() - 1 : r - 1;
        
        return num_str[index] - '0';
    }
};