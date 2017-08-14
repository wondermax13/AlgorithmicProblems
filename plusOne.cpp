class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        
        
        int size = digits.size();
        
        vector<int> result;
        
        int index = size - 1;
        
        int sum = (1 + digits[index]);
        int r = sum % 10;
        int q = sum / 10;
        
        result.insert(result.begin(), r);
        
        index = size - 2;
        while(index > -1) {
            
            result.insert(result.begin(), (q + digits[index])%10);
            
            q = (q + digits[index]) / 10;
            
            --index;
        }
        
        if(q > 0) {
            
            result.insert(result.begin(), (q));
        }
        
        return result;
    }
};