class WordDistance {
public:
    WordDistance(vector<string> words) {
        
        for(int index = 0; index < words.size(); index++) {
            
/*
        MINE
            auto it = map_.find(words[index]);
            if(it != map_.end()) {
                
                it->second.push_back(index);
            }
            else {
                
                map_.insert(make_pair(words[index], vector<int>(1, index)));
            }
*/

            map_[words[index]].push_back(index);
        }
    }
    
    int shortest(string word1, string word2) {
        
        vector<int> indices_1 = map_.at(word1);
        vector<int> indices_2 = map_.at(word2);
        
        int min_dist = INT_MAX;
        
/*
      MINE

        for(int ind1 = 0; ind1 < indices_1.size(); ind1++) {
            for(int ind2 = 0; ind2 < indices_2.size(); ind2++) {
                
                min_dist = min(min_dist, abs(indices_1[ind1] - indices_2[ind2]));
            }
        }
*/
        int ind1 = 0, ind2 = 0;
        
        while(ind1 < indices_1.size() && ind2 < indices_2.size()) {
            
            min_dist = min(min_dist, abs(indices_1[ind1] - indices_2[ind2]));
            
            indices_1[ind1] < indices_2[ind2] ? ind1++ : ind2++;
        }
        
        return min_dist;
    }
    
    unordered_map<string, vector<int>> map_;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */