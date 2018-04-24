class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        int min_dist = INT_MAX, dist = 0;
        
        string& curr = beginWord;
        
        unordered_set<int> used;
        
        findDistance(curr, used, dist, min_dist, endWord, wordList);
        
        return min_dist == INT_MAX ? 0 : min_dist;
    }
    
    void findDistance(
        string& curr,
        unordered_set<int>& used,
        int dist,
        int& min_dist,
        string& endWord,
        vector<string>& wordList) {
          
        if(curr == endWord) {
            min_dist = min(min_dist, dist + 1);
        }
        
        else {
        
        for(int index = 0; index < wordList.size(); index++) {
            
            if(used.find(index) == used.end()
               && areOneDiff(wordList[index], curr)) {
                
                string tmp = curr;
                used.insert(index);
                
                curr = wordList[index];
                
                findDistance(curr, used, dist + 1, min_dist, endWord, wordList);
                
                used.erase(index);
                curr = tmp;
            }
        }
        }
    }
    
    bool areOneDiff(string& first, string& second) {
        
        int diff = 0;
        
        int index = 0;
        
        while(index < first.size() && diff < 2) {
            
            if(first[index] != second[index]) {
                ++diff;
            }
            
            ++index;
        }
        
        return diff == 1;
    }
};