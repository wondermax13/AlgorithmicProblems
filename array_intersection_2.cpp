class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int, int> map_1_, map_2_;
        
        for(int& c : nums1) {
            
            auto it = map_1_.find(c);
            
            if(it != map_1_.end()) {
                
                int curr = it->second;
                it->second = curr + 1;
            }
            else {
                map_1_.insert(make_pair(c, 1));
            }
        }
        
        for(int& c : nums2) {
            
            auto it = map_2_.find(c);
            
            if(it != map_2_.end()) {
                
                int curr = it->second;
                it->second = curr + 1;
            }
            else {
                map_2_.insert(make_pair(c, 1));
            }
        }
        
        vector<int> res;
        for(pair<int, int> p : map_2_) {
            
            auto it = map_1_.find(p.first);
            if(it != map_1_.end()) {
                
                for(int i = 0; i < min(p.second, it->second); i++) {
                    
                    res.push_back(p.first);
                }
            }
        }
        
        return res;
    }
};