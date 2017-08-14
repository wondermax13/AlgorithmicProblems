class Solution {
public:
    char findTheDifference(string s, string t) {
        
        if(s.size() == 0) {
            
            return t[0];
        }
        
        unordered_map<char, int> map_1_, map_2_;
        
        
        for(char& c : s) {
            
            auto it = map_1_.find(c);
            
            if(it != map_1_.end()) {
                
                int curr = it->second;
                it->second = curr + 1;
            }
            else {
                map_1_.insert(make_pair(c, 1));
            }
        }
        
        for(char& c : t) {
            
            auto it = map_2_.find(c);
            
            if(it != map_2_.end()) {
                
                int curr = it->second;
                it->second = curr + 1;
            }
            else {
                map_2_.insert(make_pair(c, 1));
            }
        }
        
        for(pair<char, int> p : map_2_) {
            
            auto it = map_1_.find(p.first);
            if(it == map_1_.end() || it->second != p.second) {
                
                return p.first;
            }
        }
        
        char target;
        return target;
    }
};