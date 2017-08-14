class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        
        /* Fails for [[1]]
        if(wall.size() < 2) {
            
            return 0;
        }*/
        
        unordered_map<int, int> map_;
        
        //Find the right bound
        int rightBound = 0;
        for(int bound : wall[0]) {
            
            rightBound += bound;
        }
        
        for(vector<int> row : wall) {
            
            int start = 0;
            for(int bound : row) {
                
                start += bound;
                
                if(start != 0 && start != rightBound) {
                    map_[start]++;
                }
            }
        }
        
        int maxBounds = 0;
        
        for(auto p : map_) {
            
            maxBounds = max(maxBounds, p.second);
        }
        
        return wall.size() - maxBounds;
    }
};