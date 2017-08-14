class Solution {
public:
    int nextGreaterElement(int n) {
        
        auto digits = to_string(n);
        /*next_permutation(begin(digits), end(digits));
        auto res = -1;
        try {
            res = stoi(digits);
        }
        catch(out_of_range e) {
        
        }
        return (res > INT_MAX || res <= n) ? -1 : res;
        */
        
        long long res = -1;
        
        bool found = false;
        int index = digits.size() - 2;
        while(index >= 0 && !found) {
        
            if(digits[index] < digits[index+1]) {
                found = true;
            }
            else {
                --index;
            }
        }
        
        if(found) {
            char min_ = digits[index+1];
            int target = index + 1;
            for(int nextIndex = index+1; nextIndex < digits.size(); nextIndex++) {
                
                if(min_ > digits[nextIndex] && digits[nextIndex] > digits[index]) {
                    
                    min_ = digits[nextIndex];
                    target = nextIndex;
                }
            }
            
            swap(digits[index], digits[target]);
            
            sort(digits.begin() + index + 1, digits.end());
            
            res = stoll(digits);
        }
    
        return (res < INT_MAX && res > INT_MIN) ? res : -1;
    }
};