class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> vec_;
        vector<int> diff_(26, 0);
        
        int p_size = p.size();
        
        if(s.size() >= p_size) {
            
            for(int index = 0; index < p_size; index++) {
                
                diff_[s[index] - 'a']++;
                diff_[p[index] - 'a']--;
            }
            
            if(isAnagram(diff_)) {
                
                vec_.push_back(0);
            }
            
            for(int index = p_size; index < s.size(); index++) {
                
                diff_[s[index - p_size] - 'a']--;
                diff_[s[index]          - 'a']++;
                
                if(isAnagram(diff_)) {
                    vec_.push_back(index - p_size + 1);
                }
            }
        }
        
        return vec_;
    }
    
    bool isAnagram(vector<int> diff_) {
        
        bool foundMismatch = false;
        
        int index = 0;
        while(index < diff_.size() && !foundMismatch) {
            
            foundMismatch = diff_[index] != 0;
            
            ++index;
        }
        
        return !foundMismatch;
    }
    
    //Don't use. Use difference vector
    bool isAnagram(string s, int s_start, int s_end, string b) {
        
        int letters[26];
        
        for(int index = s_start; index <= s_end; index++) {
            
            int left = s[index] - 'a';
            int right = b[index - s_start] - 'a';
            letters[left]++;
            letters[right]--;
        }
        
        bool foundMismatch = false;
        int index = 0;
        while(index < 26 && !foundMismatch) {
            
            foundMismatch = letters[index] != 0;
            
            ++index;
        }
        
        return !foundMismatch;
    }
};