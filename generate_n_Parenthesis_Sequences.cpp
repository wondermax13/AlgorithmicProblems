class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        vector<string> words;
        string curr;
        bt(curr, words, 0, 0, n);
        
        return words;
    }
    
    //We are traversing through a grid here.
    //From corner to corner different paths are taken
    //but we can only move either to the bottom or to the right
    //But we can't move more to the right (')') than we have downwards('(')
    void bt(string& curr, vector<string>& words, int left, int right, int n) {
        
        if(curr.size() == 2*n) {
            words.push_back(curr);
        }
        else {
            if(left < n) { //left == n implies we have reached the last row
                string currLeft = curr + "(";
                bt(currLeft, words, left + 1, right, n);
            }
            if(right < left) {
                string currRight = curr + ")";
                bt(currRight, words, left, right + 1, n);
            }
        }
    }
};