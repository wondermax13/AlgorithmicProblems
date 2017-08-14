class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        unordered_map<int, int> map_;
        
        int ele = 0;
        
        for(auto num : nums) {
            
            auto it = map_.find(num);
            if(it != map_.end()) {
                
                int currValue = it-> second;
                map_[num] = (currValue + 1);
            }
            else {
                map_.insert(make_pair(num, 1));
            }
        }
        
        int maxFreq = 0;
        for(auto freq : map_) {
            
            if((freq.second) > maxFreq) {

                ele = freq.first;
                maxFreq = freq.second;
            }
        }
        
        return ele;
    }
};