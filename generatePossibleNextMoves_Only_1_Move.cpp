class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        
        vector<string> res;
        
        for(int index = 0; index + 1< s.size(); index++) {
            
            if(s[index] == '+' && s[index+1] == '+') {
                
                s[index] = '-';
                s[index + 1] = '-';
                
                res.push_back(s);
                
                s[index] = '+';
                s[index + 1] = '+';
            }
        }
        
        return res;
    }
};