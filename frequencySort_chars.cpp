class Solution {
public:
    string frequencySort(string s) {
        
        string res;
        
        unordered_map<char, int> map_;
        
        for(char c : s) {
            
            map_[c]++;
        }
        
        vector<pair<char, int>> vec(map_.begin(), map_.end());
        
        sort(vec.begin(), vec.end(),
        [](pair<char, int> left,  pair<char, int> right) {
            
            return left.second > right.second;
        });
        
        for(auto p : vec) {
            
            for(int i = 0; i < p.second; i++) {
            
                res += p.first;
            }
        }
        
        return res;
    }
};