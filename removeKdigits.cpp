class Solution {
public:
    string removeKdigits(string num, int k) {
        
        if(num.size() <= k) {
            
            return "0";
        }
            
        string curr = num;
        int remainingDigits = k;
        long minVal = INT_MAX;
        
        removeDigit(curr, remainingDigits, minVal);
        
        return to_string(minVal);
    }
    
    void removeDigit(
        string& curr, int& remainingDigits, long & minVal) {
        
        if(remainingDigits <= 0) {
            
            minVal = min((int)minVal, stoi(curr));
        }
        else {
            
            for(int digit = 0; digit < curr.size(); digit++) {
                
                string digStr(1, curr[digit]);
                
                curr.erase(digit, 1);
                --remainingDigits;
                
                //cout << " erased curr: " << curr << endl;
                
                removeDigit(curr, remainingDigits, minVal);
                
                curr.insert(digit, digStr);
                //cout << " inserted curr: " << curr << endl;
                ++remainingDigits;
            }
        }
    }
};