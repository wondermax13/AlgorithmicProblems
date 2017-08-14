class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> dictionary) {
        
        for(string word : dictionary) {
            
            string abbr = getAbbreviation(word);
            
            map_[abbr].insert(word);
        }
    }
    
    bool isUnique(string word) {
        
        bool unique = true;
        
        string abbr = getAbbreviation(word);
        
        auto it = map_.find(abbr);
        if(it != map_.end()) {
            
            set<string> words = it->second;
            
            if(words.size() == 1 && words.find(word) != words.end()) {
                
                unique = true;
            }
            else {
                unique = false;
            }
        }
        else {
            unique = true;
        }
        
        return unique;
    }
    
    string getAbbreviation(string word) {
        
        int size = word.size();
        
        if(size < 3) {
            
            return word;
        }
        
        string abbr(word.begin(), word.begin() + 1);
        abbr.append(to_string(size - 2));
        abbr += (word[size -1]);
        
        return abbr;
    }
    unordered_map<string, set<string>> map_;
    unordered_set<string> set_;
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */