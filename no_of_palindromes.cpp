class Solution {
public:
    int longestPalindrome(string s) {
        
        unordered_map<char, int> map_;
        populateMap(s, map_);
        
        int odds = 0, evens = 0, total = 0;
        
        vector<int> vec_(map.size());
        int index = 0;
        
        for(auto p : map_) {
            
            int count = p.second;
            if(count %2 == 1) {
                
                odds++;
            }
            
            evens = count / 2;
            if(evens > 0) {
                total += evens;
                
                vec_[index] = evens;
                ++index;
            }
        }
        
        int product = 1;
        for(int i = 0; i < index; i++) {
            
            product *= factorial(vec_[i]);
        }
        
        return (factorial(total)/product)*odds;
    }
    
    void populateMap(string s, unordered_map<char, int> map_) {
        
        for(char c : s) {
            
            map_[c]++;
        }
    }
    
    int factorial(int n) {
        return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
    }
};