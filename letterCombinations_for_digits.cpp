class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> res;
        string curr;
        
        if(digits.size() > 0) {
            bt_permute(0, curr, res, digits);
        }
        
        return res;
    }
    
    void bt_permute(int pos, string& curr, vector<string>& res, string digits) {
        
        if(pos >= digits.size()) {
            
            res.push_back(curr);
        }
        else {
            
            string charmap[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
            
            string letterSeq = charmap[digits[pos] - '0'];
            // getLetterSeqForDigit(, letterSeq);
            
            
            for(int i = 0; i < letterSeq.size(); i++) {
                
                curr.push_back(letterSeq[i]);
                bt_permute(pos + 1, curr, res, digits);
                curr.pop_back();
            }
        }
    }
    
};