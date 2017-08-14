class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        
        int w1_index = -1, w2_index = -1, min_distance = INT_MAX;
        
        if(word1 != word2) {
        for(int index = 0; index < words.size(); index++) {
            
            if(words[index] == word1) {
                
                if(w2_index != -1) {
                    
                    min_distance = min(min_distance, index - w2_index);
                }
                w1_index = index;
            }
            if(words[index] == word2) {
                
                if(w1_index != -1) {
                    
                    min_distance = min(min_distance, index - w1_index);
                }
                w2_index = index;
            }
        }
        }
        else {
            int w_index = -1;
            for(int index = 0; index < words.size(); index++) {
            
            if(words[index] == word1) {
                
                if(w_index != -1) {
                    
                    min_distance = min(min_distance, index - w_index);
                }
                w_index = index;
            }
            }
        }
        
        return min_distance;
    }
};