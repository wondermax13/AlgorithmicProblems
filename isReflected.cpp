class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        
        int max = INT_MAX, min = INT_MIN;
        
        for(pair<int, int> pt : points) {
            
            max = max < pt.first ? pt.first : max;
            min = min > pt.first ? pt.first : min;
        }
        
        unordered_map<int, set<int>> map_;
        
        sort(points.begin(), points.end(),
            [](pair<int, int> left, pair<int, int> right){
            
            return left.first < right.first;
        });
        
        populateMap(points, map_);
        
        bool oddFound = false;
        int index = 0;
        
        int mid = (max + min) / 2;
        
        auto it = map_.begin();
        while(it != map_.end() && !foundOdd) {
            
            auto sear = map_.find(it->first);
            
            if(sear != map_.end()) {
                
                set<int> s = it->second;
                
                if(s.contains())
            
            for (auto start=s.begin(), end = s.end(); start!=end; ++start) {
            if ((*start + *(--end)) / 2.0 != line)
                return false;
            if (start==end) break;
            }
            else {
                foundOdd = it->first != mid;
            }
            
            ++it;
        }
        }

        return !oddFound;
    }
    
    void populateMap(vector<pair<int, int>>& points, unordered_map<int, vector<int>> map_) {
        
        for(pair<int, int> pt : points) {
            
            map_[pt.first].insert(pt.second);
        }
    }
};