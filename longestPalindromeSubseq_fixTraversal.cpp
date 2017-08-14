class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        int len = s.size();
        int index = 0;
        
        int grid[len][len];
        
        for(int i = 0; i < len; i++) {
            
            grid[i][i] = 1;
        }
        
        for(int j = 1; j < len; j++) {
            
            for(int d = 1; d < j; d++) {
                
                int i = j - d;
                
                if(s[i] == s[j]) {
                    
                    grid[i][j] = 2 + grid[i+1][j-1];
                }
                else {
                    
                    grid[i][j] = max(grid[i+1][j], grid[i][j-1]);
                }
            }
        }
        
        return grid[0][len-1];
    }
};

/*        for(int j = 0; j < len; j++) {
            
            for(int i = j - 1; i > -1; i--) {*/