class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        if(grid.size() < 2) return grid[0][0];
        
        vector<vector<int>> values(grid.size(), vector<int>(grid[0].size(), grid[0][0]));
        
        // values[0][0] = 0;
        int m = grid.size(), n = grid[0].size();
        
        for(int i = 0; i < m; i++) {
            
            values[i][0] = grid[i][0] + values[i-1][0];
        }
        
        for(int j = 0; j < n; j++) {
            
            values[0][j] = grid[0][j] + values[0][j-1];
        }

            
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                
                values[i][j] = min(values[i-1][j], values[i][j-1]) + grid[i][j];
            }
        }
        
        return values[grid.size()-1][grid[0].size()-1];
    }
};