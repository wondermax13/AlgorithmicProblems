class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        
        int size = points.size();
        int pts = 0;
        
        for(int commIndex = 0; commIndex < size; commIndex++) {
            
            unordered_map<int, int> map_;
            for(int firstIndex = 0; firstIndex < size; firstIndex++) {
                
                if(commIndex != firstIndex) {
                int dist = pow((points[commIndex].first - points[firstIndex].first), 2)
                    + pow((points[commIndex].second - points[firstIndex].second), 2);
                    
                auto it = map_.find(dist);
                if(it != map_.end()) {
                    
                    int curr = it->second;
                    
                    it->second = curr + 1;
                }
                else {
                        
                    map_.insert(make_pair(dist, 1));
                }
                }
            }

            for(pair<int, int> dists : map_) {
                
                pts += ((dists.second) * (dists.second - 1));
            }
        }
        
        return pts;
    }
};