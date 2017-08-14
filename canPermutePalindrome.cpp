class Solution {
public:
    bool canPermutePalindrome(string s) {
        
        unordered_map<char, int> map_;
        int noOfOdds = 0;
        
        int index = 0;
        
        while(index < s.size()) {
            
            map_[s[index]]++;
            
            ++index;
        }
        
        ; //unordered_map<char, int>::iterator iter;
        
        decltype (map_.begin()) i = map_.begin();
        
        while(i != map_.end() && noOfOdds < 2) {
            
            
            if(i-> second % 2 != 0) {
                
                ++noOfOdds;
            }
            
            ++i;
        }
        
        
        return noOfOdds < 2;
    }
};