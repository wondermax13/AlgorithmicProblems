class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        
        vector<int> matched;
        vector<vector<string>> matches;
        
        if(strings.size() == 0) {
            
            return matches;
        }
        
        for(int i = 0; i < strings.size(); i++) {
            
            if(find(matched.begin(), matched.end(), i) == matched.end()) {
                
                matched.push_back(i);
                
                vector<string> newMatch;
                newMatch.push_back(strings[i]);

                for(int j = i+1; j < strings.size(); j++) {
                    
                     if(find(matched.begin(), matched.end(), j) == matched.end()) {
                        
                        if(checkSameShift(strings[i], strings[j])) {
                            
                            matched.push_back(j);
                            newMatch.push_back(strings[j]);
                        }
                     }
                }
                
                matches.push_back(newMatch);
            }
        }
        
        return matches;
    }
    
    bool checkSameShift(string &s1, string &s2) {
        
        if(s1.size() != s2.size()) {
            
            return false;
        }
        
        if(s1.size() == 0) return true;
        
        bool foundMismatch = false;
        int index = 0;
        int commonDiff = s1[0] - s2[0];
        
        while(index < s1.size() && !foundMismatch) {
            
            foundMismatch 
                = (s1[index] - s2[index]) != commonDiff
                    && (s1[index] - s2[index]) != (26 + commonDiff);
            
            ++index;
        }
        
        return !foundMismatch;
    }
};