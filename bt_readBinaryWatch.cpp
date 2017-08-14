class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        
        vector<string> vec_;
        
        for(int h = 0; h < 12; h++) {
            for(int m = 0; m < 60; m++) {
                
                int leftSet = bitset<10>(h).count();
                int rightSet = bitset<10>(m).count();
                    
                if(leftSet + rightSet == num) {
                    vec_.emplace_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
                }
            }
        }
        
        return vec_;
    }
};