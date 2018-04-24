class Solution {
public:
    int numJewelsInStones(string J, string S) {
        
        int count = 0;
        unordered_set<char> jewels;
        
        for(auto letter : J) {
            jewels.insert(letter);
        }
        
        for(auto letter : S) {
            
            if(jewels.find(letter) != jewels.end()) {
                
                ++count;
            }
        }
        
        return count;
    }
};