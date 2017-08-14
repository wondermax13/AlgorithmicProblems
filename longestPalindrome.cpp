class Solution {
public:
    int longestPalindrome(string s) {
        
        unordered_map<char, int> map_;
        populateMap(s, map_);
        
        int odds = 0, evens = 0;
        
        for(auto p : map_) {
            
            int count = p.second;
            if(count %2 == 1) {
                
                odds++;
            }
            
            evens += count / 2;
        }
        
        return 2*evens + (odds > 0 ? 1 : 0);
    }
    
    void populateMap(string s, unordered_map<char, int>& map_) {
        
        for(char c : s) {
            
            auto it = map_.find(c);
            if(it != map_.end()) {
                map_[c]++;
            }
            else {
                map_[c] = 1;
            }
        }
    }
    
    int factorial(int n) {
        return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
    }
};