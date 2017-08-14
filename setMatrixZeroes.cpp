class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        vector<int> zRow, zCol;
        
        int rows = matrix.size(), cols = matrix[0].size();
        
        for(int row = 0; row < rows; row++) {
            for(int col = 0; col < cols; col++) {
                
                if(matrix[row][col] == 0) {
                    
                    zRow.push_back(row);
                    zCol.push_back(col);
                }
            }
        }
        
        
        for(auto row : zRow) {
            
            for(int col = 0; col < cols; col++) {
                
                matrix[row][col] = 0;
            }
        }
        
        for(auto col : zCol) {
            
            for(int row = 0; row < rows; row++) {
                
                matrix[row][col] = 0;
            }
        }
    }
};