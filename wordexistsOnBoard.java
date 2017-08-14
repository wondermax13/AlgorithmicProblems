public class Solution {
    public boolean exist(char[][] board, String word) {
        
        for(int row = 0; row < board.length; row++) {
            for(int col = 0; col < board[0].length; col++) {
                
                if(checkWord(row, col, board, word)) {
                    
                    return true;
                }
            }
        }
        
        return false;
    }
    
    protected boolean checkWord(int row, int col, char[][] board, String word) {
        
        if(word.length() == 0) return true;
        
        if(row < 0 || row > board.length - 1 || col < 0 || col > board[0].length - 1 ) {
            
            return false;
        }
        
        if(board[row][col] == '-') return false;
        
        if(board[row][col] == word.charAt(0)) {
            
            char curr = board[row][col];
            board[row][col] = '-';
            
            if(checkWord(row-1, col, board, word.substring(1))
                || checkWord(row+1, col, board, word.substring(1))
                || checkWord(row, col-1, board, word.substring(1))
                || checkWord(row, col+1, board, word.substring(1))) {
                    
                    return true;
            }
            
            board[row][col] = curr;
        }
        
        
        return false;
    }
}