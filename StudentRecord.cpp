class Solution {
public:
    bool checkRecord(string s) {
        
        int a_count_ = 0, l_seq_ = 0;
        
        bool failed = false;
        
        if(s.size() > 0) {
        int index = 0;
            while(index < s.size() && !failed) {
            
                l_seq_ = s[index] == 'L' ? l_seq_ + 1 : 0;
            
                a_count_ = s[index] == 'A' ? a_count_ + 1 : a_count_;
            
                failed = (l_seq_ > 2) || (a_count_ > 1);
            
                ++index;
            }
        }
        
        return !failed;
    }
};