class Solution {
public:
    vector<vector<string>> partition(string s) {
        
        vector<string> curr;
        vector<vector<string>> lists;
        
        bt_subset(0, s, curr, lists);
        
        return lists;
    }
    
    void bt_subset(int pos, string s, vector<string>& curr, vector<vector<string>>& lists) {
        
        if(pos >= s.size()) {
            
            lists.push_back(curr);
        }
        else {
            for(int i = pos + 1; i <= s.size(); i++) {
                
                if(isPalindrome(s, pos, i)) {
                    
                    curr.push_back(s.substr(pos, i - pos));
                    
                    int size = curr.size();
                    
                    bt_subset(i, s, curr, lists);
                    
                    curr.pop_back();
                }
            }
        }
    }
    
    bool isPalindrome(string s, int pos, int i) {
        
        bool mismatchFound = false;
        
        int left = pos, right = i - 1;
        
        while(left < right && !mismatchFound) {
            
            mismatchFound = s[left] != s[right];
            
            ++left;
            --right;
        }
        
        return !mismatchFound;
    }
};