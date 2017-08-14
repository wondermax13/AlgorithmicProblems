class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        
        int nos = 0;
        
        int rows = picture.size();
        if(rows == 0) return 0;
        int columns = picture[0].size();
        
        int rowIndices[rows], colIndices[columns];
        
        
        for(int row = 0; row < rows; row++) {
            
            for(int col = 0; col < columns; col++) {
                
                // if(picture[row][col] == 'B') {
                    
                    rowIndices[row] += picture[row][col] == 'B';
                    colIndices[col] += picture[row][col] == 'B';
                // }
            }
        }
        
        for(int row = 0; row < rows; row++) {
            
            for(int col = 0; col < columns; col++) {
                
                // if( rowIndices[row] == 1 ) {
                        
                        nos += (picture[row][col] == 'B' && rowIndices[row] == 1 && colIndices[col] == 1);
                // }
            }
        }
        
        return nos;
    }
};