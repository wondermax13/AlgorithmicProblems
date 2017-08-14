class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        
        int rad = 0;
        
        pair<int,int> range;
        
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        
        for(int house : houses) {
            
            findRange(house, heaters, range);
        
            int left = range.first != -1 ? abs(house - range.first) : INT_MAX;
            int right = range.second != -1 ? abs(house - range.second) : INT_MAX;
        
            int min_dist_ = min(left, right);
        
            rad = max(rad, min_dist_);
        }
        
        
        return rad;
    }
    
    void findRange(int house, vector<int>& heaters, pair<int, int>& range) {
        
        if(heaters[0] > house) {
            range.first = -1;
            range.second = heaters[0];
        }
        
        //THIS IS THE DEFAULT CASE AFTER THE FOR LOOP
        /*else if(heaters[heaters.size() - 1] < house) {
            range.first = heaters[heaters.size() - 1];
            range.second = -1;
        }*/
        
        else {
            
            for(int index = 0; index + 1 < heaters.size(); index++) {
                
                if(house == heaters[index]) {
                    
                    range.first = heaters[index];
                    range.second = heaters[index];
                    
                    return;
                }
                else if(house > heaters[index] && house < heaters[index + 1]) {
                    
                    range.first = heaters[index];
                    range.second = heaters[index + 1];
                    
                    return;
                }
            }
            
            range.first = heaters[heaters.size() - 1];
        range.second = -1;
        }
        
        
    }
};