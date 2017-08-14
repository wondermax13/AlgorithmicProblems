class Solution {
public:
    bool detectCapitalUse(string word) {
        
        bool all_upper, all_lower, camelCase, failed = false;
        
        int size = word.size();
        if(size >= 2) {
            
            if(word[0] >= 'A' && word[0] <= 'Z') {
                
                all_upper = true;
                all_lower = false;
                camelCase = true;
            }
            else {
                
                all_upper = false;
                all_lower = true;
                camelCase = false;
            }
            
            int index = 1;
            while(index < word.size() && !failed) {
                
                all_upper = all_upper && (word[index] >= 'A' && word[index] <= 'Z');
                all_lower = all_lower && !(word[index] >= 'A' && word[index] <= 'Z');
                camelCase = camelCase && !(word[index] >= 'A' && word[index] <= 'Z');
                
                failed = !(all_upper || all_lower || camelCase);
                
                
                ++index;
            }
        }
        
        return !failed;
    }
};