class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        unordered_map<char, char> map_;
        
        int size = t.size();
        
        if(s.size() != size) {
            
            return false;
        }
        
        int index = 0;
        bool foundMismatch = false;
        while(index < size && !foundMismatch) {
            
            auto it = map_.find(s[index]);
            
            if(it != map_.end()) {
                
                foundMismatch = it->second != t[index] ? true : foundMismatch;
            }
            else {
                
                for(auto it1 : map_) {
                    
                    foundMismatch = it1.second == t[index] ? true : foundMismatch;
                }
                
                if(!foundMismatch) {
                    map_.insert(make_pair(s[index], t[index]));
                }
            }
            
            ++index;
        }
        
        return !foundMismatch;
    }
};