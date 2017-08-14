class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if(s1.size() > s2.size()) {
            
            return false;
        }
        
        vector<int>freq(26, 0);
        
        for(int i = 0; i < s1.size(); i++) {
            
            ++freq[s1[i] - 'a'];
            --freq[s2[i] - 'a'];
        }
        
        if(checkMatch(freq)) {
            
            return true;
        }
        
        
        
        vector<int>checker(freq);
        
        bool found = false;
        int index = s1.size();
        while(index < s2.size() && !found) {
            
            //cout << " index: " << index << endl;
            
            ++checker[s2[index - s1.size()] - 'a'];
            --checker[s2[index] - 'a'];
            
            
            //cout << " changing " << index << " and " << (index - s1.size()) << endl;
            
            found = checkMatch(checker);
            
            /*
                Use sliding window instead of loop
                Though the whole checker array is being checked each time
            int curr = index;
            
            while(curr < index + s1.size()) {
                
                // mismatch = (s1.find(s2[currIndex]) == s1.end());
                
                if(!mismatch) {
                    
                    --checker[s2[curr] - 'a'];
                }
                ++ curr;
                
            }*/
            
            /*int checkIndex = 0;
            while(checkIndex < checker.size() && !mismatch) {
                    
                mismatch = checker[checkIndex] != 0;

                checkIndex++;
            }
            
            found = !mismatch;*/
            
            //cout << "found: " << found << endl;
            
            //checker = freq;
            
            ++index;
        }
        
        
        
        return found;
    }
    
    bool checkMatch(vector<int> checker) {
        
        int checkIndex = 0;
        bool mismatch = false;
        while(checkIndex < checker.size() && !mismatch) {
                    
            mismatch = checker[checkIndex] != 0;

            checkIndex++;
        }
            
        return !mismatch;
    }
};