class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        
        int w1_index = -1, w2_index = -1, min_distance = INT_MAX;
        
        for(int index = 0; index < words.size(); index++) {
            
            //w1 found at index
            if(words[index] == word1) {
                
                //w2 has been found already
                if(w2_index != -1) {
                    
                    min_distance = min(min_distance, index - w2_index);
                }
                //Set last w1 found
                w1_index = index;
            }
            //w2 found at index.
            if(words[index] == word2) {
                
                if(w1_index != -1) {
                    
                    min_distance = min(min_distance, index - w1_index);
                }
                //Set last w2 found
                w2_index = index;
            }
        }
        
        return min_distance;
    }
};