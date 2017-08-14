class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int rows = board.size(), cols = board[0].size();
        
        bool rowEntries[rows + 1][9 + 1] = {false};
        bool colEntries[cols + 1][9 + 1] = {false};
        bool subBoxEntries[9 + 1][9 + 1] = {false};
        
        
        for(int row = 0; row < rows; row++) {
            for(int col = 0; col < cols; col++) {
                
                if(board[row][col] != '.') {
                    
                    int num = board[row][col] - '0', k = row / 3 * 3 + col / 3;
                    
                    if((rowEntries[row][num] || colEntries[col][num] || subBoxEntries[k][num])) {
                        
                        return false;
                    }
                    
                    rowEntries[row][num] = true;
                    colEntries[col][num] = true;
                    subBoxEntries[k][num] = true;
                }
                
            }
        }
        
        return true;
    }
};