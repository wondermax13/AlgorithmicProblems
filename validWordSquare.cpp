class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        
        bool foundMismatch = false;
        
        int rows = words.size();
        
        int row = 0;
        while(row < rows && !foundMismatch) {
            
            if(words[row].size() == rows) {
                foundMismatch = !doRowAndColumnMatch(row, words);
            }
            else {
                foundMismatch = true;
            }

            ++row;
        }
        
        return !foundMismatch;
    }
    
    bool doRowAndColumnMatch(int diag_index_, vector<string>& words) {
        
        bool foundMismatch = false;
        
        int noOfRows = words.size();
        int noOfCols = words[diag_index_].size();
        
        if(noOfCols == -1 || noOfRows != noOfCols) {
            
            foundMismatch = true;
        }
        else {
            int otherIndex = 0;
            while(otherIndex < noOfRows && !foundMismatch) {
            
                foundMismatch = words[diag_index_][otherIndex] != words[otherIndex][diag_index_];
            
                ++ otherIndex;
            }
        }
        
        return !foundMismatch;
    }
    
    int getRowsForCol(int col, vector<string>& words) {
        
        int count = 0;
        bool discontinuous = false;
        
        int index = 0;
        while(index < words.size() && !discontinuous) {
            
            
            
            ++count;
        }
        
        
        
        return !discontinuous ? count : -1;
    }
};