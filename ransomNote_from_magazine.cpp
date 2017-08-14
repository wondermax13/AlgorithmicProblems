class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        if(magazine.size() < ransomNote.size()) {
            
            return false;
        }
        
        unordered_map<char, int> map_(26);
        
        constructMapFromMagazine(magazine, map_);
        
        bool missing = false;
        int index = 0;
        while(index < ransomNote.size() && !missing) {
            
            char letter = ransomNote[index];
            
            missing = (--map_[letter] < 0);
            
            auto it = map_.find(letter);
            if(it != map_.end()) {
                
                int count = it -> second;
                
                //Incorrect
                //missing =  count >= 0;
                //it-> second = count - 1;
                missing = (--map_[letter] < 0);
            }
            else {
                missing = true;
            }
            
            ++index;
        }
        
        return !missing;
    }
    
    void constructMapFromMagazine(
        string magazine, unordered_map<char, int>& map_) {
            
            for(char letter : magazine) {
                
                ++map_[letter];
                /*auto it = map_.find(letter);
                if(it != map_.end()) {
                    
                    (it-> second = it-> second + 1); 
                }
                else {
                    
                    map_.insert(make_pair(letter, 2));
                }*/
            }
    }
};