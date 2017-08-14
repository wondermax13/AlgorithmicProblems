class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        
        vector<string> board;
        vector<vector<string>> res;
        
        bt(0, n, board, res);
        
        return res;
    }
    
    void bt(int row, int n, vector<string>& board, vector<vector<string>>& res) {
        
        if(row >= n) {
            
            res.push_back(board);
        }
        else {
        for(int j = 0; j < n; j++) {
            if(validPosition(row, j, n, board)) {
                    
                string newRow(n, '.');
                newRow[j] = 'Q';
                    
                board.push_back(newRow);
                bt(row + 1,  n, board, res);
                board.pop_back();
            }
        }
        }
    }
    
    bool validPosition(int row, int col, int n, vector<string>& board) {

        //check if the column had a queen before.        
        for(int i = 0; i < row; i++) {
            
            if(board[i][col] == 'Q') {
                return false;
            }
        }
        
        //check if the 45° diagonal had a queen before.
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
            if (board[i][j] == 'Q')
                return false;
        //check if the 135° diagonal had a queen before.
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
            if (board[i][j] == 'Q')
                return false;
        return true;
    }
};