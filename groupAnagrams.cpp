class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> currentStrings;
        
        createMatrixFromStrings(strs, currentStrings);
        
        return currentStrings;
    }
    
    void createMatrixFromStrings(vector<string> strs,
                                 vector<vector<string>>& currentStrings) {
        
        for(str : strs) {
            
            int index = 0;
            bool matchFound = false;
            
            while( index < currentStrings.size() && !matchFound) {
                
                // vector<string> vec = currentStrings.at(index);
                
                if(areAnagrams(currentStrings.at(index).at(0), str)) {
                    
                    matchFound = true;
                    currentStrings.at(index).push_back("same");
                }
                
                index++;
            }
            
            if(!matchFound) {
                
                vector<string> vec;
                vec.push_back(str);
                
                currentStrings.push_back(vec);
            }
        }
    }
    
    bool areAnagrams(string left, string right) {
        
        if(left.length() != right.length()) {
            
            return false;
        }
        
        int charFreq[128];
        
        for(int index = 0; index < left.length(); index++) {
            
            charFreq[left[index]]++;
            charFreq[right[index]]--;
        }
        
        for(int c = 0; c < 128; c++) {
            
            if(charFreq[c] != 0) {
                
                return false;
            }
        }
        
        return true;
    }
};